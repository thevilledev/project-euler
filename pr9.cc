#include <iostream>
#include <cstdlib>
using namespace std;

bool istriplet(const int a, const int b, const int c);

int main() {
    for( int c = 1; c <= 1000; ++c ) {
        for( int b = 1; b < c; ++b ) {
            for( int a = 1; a < b; ++a) {
                if(istriplet(a, b, c)) {
                    cout << "> " << a*b*c << endl;
                    return EXIT_SUCCESS;
                }
            }
        }
    }
}

bool istriplet(const int a, const int b, const int c) {
    if(a*a+b*b==c*c&&a+b+c==1000) {
        return true;
    }
    return false;
}
