#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

bool isLegit(const string num_str);
bool isprime(long int n);

int main() {
    for(long int i = 9999999; i >= 1; --i) {
        stringstream flow; flow << i;
        string num = flow.str();
        if(isLegit(num)) {
            stringstream j; j << num;
            int answer = 0; j >> answer;
            if(isprime(answer)) {
                cout << answer << endl;
                return EXIT_SUCCESS;
            }
        }
    }
}

bool isLegit(const string num_str) {
    if(num_str.find("0") == string::npos &&
       num_str.find("8") == string::npos &&
       num_str.find("9") == string::npos) {
        const string nums = "1234567";
        for(int i = 0; i < nums.size(); ++i) {
            if(num_str.find(nums.at(i)) == string::npos) {
                return false;
            }   
        }   
        return true;
    }   
    return false;
}   

bool isprime(long int n) {
    for(long int i = 2; i*i <= n; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
