#include <iostream>
using namespace std;

int sumsquare() {
    int sum = 0;
    for(int i = 1; i <= 100; ++i) {
        sum += i;
    }
    return sum*sum;
}

int squaresum() {
    int sum = 0;
    for(int i = 1; i <= 100; ++i) {
        sum += i*i;
    }
    return sum;
}

int main() {
    cout << sumsquare() - squaresum() << endl;
}

