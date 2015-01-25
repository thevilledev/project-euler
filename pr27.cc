#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

bool isprime(int n) {
    if(n <= 1) {
        return false;
    }
    else if(n % 2 == 0) {
        return false;
    }
    for(long int i = 3; i*i <= n; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int maxA = 0;
    int maxB = 0;
    int nMax = 0;
    for( int a = -999; a < 1000; ++a) {
        for( int b = -999; b < 1000; ++b) {
            int n = 0;
            while(true) {
                if(!isprime(n*n + a*n + b)) {
                    break;
                }
                else {
                    ++n;
                }
            }
            if(n > nMax) {
                nMax = n;
                maxA = a;
                maxB = b;
            }
        }
    }
    cout << "> " << maxA*maxB << endl;
    return EXIT_SUCCESS;
}
