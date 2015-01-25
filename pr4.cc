#include <iostream>
#include <sstream>
using namespace std;

bool ispalind(const string product);

int main() {
    int max = 0;
    for(int i = 1; i < 1000; ++i) {
        for(int k = 1; k < 1000; ++k) {
            long int product = i * k;
            string num_str = ""; stringstream out;
            out << product; num_str = out.str();
            if(ispalind(num_str) && (product > max)) {
                max = product;
            }
        }
    }
    cout << "> " << max << endl;
}

bool ispalind(const string product) {
    string tmp = "";
    int size = static_cast<signed int>(product.size()) - 1;
    for(int i = size; i >= 0; --i) {
        tmp += product.at(i);
    }
    if(tmp == product) {
        return true;
    }
    return false;
}
