#include <iostream>
using namespace std;

int getDivisors(const int num) {
    int divs = 1;
    for(int i = 2; i*i <= num; ++i) {
        if(num % i == 0) {
            ++divs;
        }
    }
    return 2*divs;
}

int main() {
    int divisors, answer = 0;
    int i = 1;
    do {
        int sum = 0;
        for(int k = 0; k <= i; ++k) {
            sum += k;
        }
        divisors = getDivisors(sum);
        answer = sum;
        ++i;
    } while (divisors < 500);
    cout << "> " << answer << endl;
}
