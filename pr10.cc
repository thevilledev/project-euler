#include <iostream>
#include <vector>
#include <cstdlib>

const int LIMIT = 2000000;

void sieve(std::vector<bool>& primes);
void vomit(const std::vector<bool> primes);

int main() {
    std::vector<bool> primes(LIMIT+1, true);
    sieve(primes);
    vomit(primes);
    return EXIT_SUCCESS;
}

void sieve(std::vector<bool>& primes) {
    for(int i = 2; i*i <= LIMIT; ++i) {
        for(int k = 2; k <= LIMIT/i; ++k) {
            primes.at(i*k) = false;
        }
    }
}

void vomit(const std::vector<bool> primes) {
    long int sum = 0;
    for(int i = 2; i < static_cast<int>(primes.size()); ++i) {
        if(primes.at(i) == true) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
}
