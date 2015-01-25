#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;

const int MAX = 1000000;

void sieve(vector<bool>& Nums);
void vomit(vector<bool>& Nums);
bool isprime(const int n);

int main(int argc, char** argv) {
    vector<bool> Nums(MAX+1, true);
    sieve(Nums);
    vomit(Nums);
    return EXIT_SUCCESS;
}

void sieve(vector<bool>& Nums) {
    for(int i = 2; i*i <= MAX; ++i) {
        for(int k = 2; k <= MAX/i; ++k) {
            Nums.at(i*k) = false;
        }
    }
}

void vomit(vector<bool>& Nums) {
    int summa = 0;
    for(int i = 2; i < Nums.size(); ++i) {
        if(Nums.at(i) == true) {
            if(summa + i >= MAX) {
                int tmp = 1;
                while(!isprime(summa)) {
                    summa -= Nums.at(i-tmp);
                    ++tmp;
                }
            }
            else {
                summa += i;
            }
        }
    }
    cout << "> " << summa << endl;
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
