#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string int2str(const int number);
bool ispandigital(const int a, const int b, const int product);
bool check_multipl(const string a_str, const string b_str);
bool check_numbers(const string product);
bool check_dupes(const vector<int> products, const int product);

int main() {
    int sum = 0;
    vector<int> products;
    for(int a = 1; a < 2000; ++a) {
        for(int b = 1; b < 1000; ++b) {
            int product = a*b;
            if(ispandigital(a, b, product) && check_dupes(products, product)) {
                products.push_back(product);
                sum += product;
            }
        }
    }
    cout << "> " << sum << endl;
}

bool ispandigital(const int a, const int b, const int product) {
    string a_str = int2str(a); string b_str = int2str(b);
    if(check_multipl(a_str, b_str)) {
        string fproduct = int2str(product); fproduct += a_str+b_str;
        if(fproduct.size() == 9) {
            if(check_numbers(fproduct)) {
                return true;
            }
        }
    }
    return false;
}

bool check_multipl(const string a_str, const string b_str) {
    for(string::const_iterator it = a_str.begin(); it != a_str.end(); ++it) {
        if(b_str.find(*it) != string::npos) {
            return false;
        }
    }
    return true;
}

bool check_numbers(const string product) {
    const string nums = "123456789";
    for(int i = 0; i < nums.size(); ++i) {
        if(product.find(nums.at(i)) == string::npos) {
            return false;
        }
    }
    return true;
}

bool check_dupes(const vector<int> products, const int product) {
    for(vector<int>::const_iterator it = products.begin(); it != products.end(); ++it) {
        if(*it == product) { return false; }
    }
    return true;
}

string int2str(const int number) {
    stringstream translator; translator << number;
    return translator.str();
}
