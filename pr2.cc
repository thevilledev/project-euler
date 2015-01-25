#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4000000;

int fibo(int luku);

int main() {
    vector<int> numbers;
    int i, num = 1;
    int sum = 0;
    do {
        if(num % 2 == 0) {
            sum += num;
        }
        ++i; num = fibo(i);
    } while (num < MAX);
    cout << "> " << sum << endl;
}

int fibo(int luku) {
    if (luku <= 1) return 1;
    return fibo(luku - 1) + fibo(luku - 2);
}
