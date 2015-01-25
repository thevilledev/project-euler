#include <iostream>
using namespace std;

bool divable(const int num) {
    for(int i = 11; i <= 20; ++i) {
        if(num % i != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num = 2520;
    while(!divable(num)) {
        ++num;
    }
    cout << num << endl;
}
