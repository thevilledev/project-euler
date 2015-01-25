#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

bool isprime(const int n);
bool ispermutation(const int a, const int b, const int c);
string int2str(const int number);

int main() {
    for(int a = 1489; a <= 9999; a += 2) {
      for(int b = a + 2; b <= 9999; b += 2) {
        int c = 2*b - a;
        if( (b > a) && (c < 10000) && isprime(a) && isprime(b) ) {
          if( ispermutation(a, b, c) && isprime(c)) {
            cout << "> " << a << b << c << endl;
            return EXIT_SUCCESS;
          }
        }
      }
    }
    return EXIT_FAILURE;
}

bool ispermutation(int a, int b, int c) {
    string A = int2str(a); string B = int2str(b); string C = int2str(c);
    sort(A.begin(), A.end()); sort(B.begin(), B.end()); sort(C.begin(), C.end());
    if( (A == B) && (A == C) && (B == C) ) {
        return true;
    }
    return false;
}

bool isprime(const int n) {
    if( (n <= 1) || (n % 2) == 0) {
        return false;
    }
    for(long int i = 3; i*i <= n; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

string int2str(const int number) {
    stringstream translator; translator << number;
    return translator.str(); 
}
