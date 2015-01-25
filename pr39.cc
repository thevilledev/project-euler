#include <iostream>
using namespace std;

int main() {
    int sMax = 0;
    int pMax = 0;
    for(int p = 120; p <= 1000; p += 2) {
        int solutions = 0;
        for(long int c = 1; c < p; ++c) {
          for(long int b = 1; b < c; ++b) {
            for(long int a = 1; a < b; ++a) {
                if(a+b+c==p && a*a+b*b==c*c) {
                    ++solutions;
                }
            }
          }
        }
        if(solutions > sMax) {
            pMax = p;
            sMax = solutions;
        }
    }
    cout << "> " << pMax << ", " << sMax << " solutions." << endl;
}
