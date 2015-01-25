#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

void sieve(std::vector<bool>& Nums, const int limit);
void vomit(const std::vector<bool> primes);

int main() {
    const int limit = 105000;
    std::vector<bool> primes(limit+1, true);
    sieve(primes, limit);
    vomit(primes);
    return EXIT_SUCCESS;
}

void sieve(std::vector<bool>& primes, const int limit) {
    for(int i = 2; i*i <= limit; ++i) {
        for(int k = 2; k <= limit/i; ++k) {
            primes.at(i*k) = false;
        }
    }
}

void vomit(const std::vector<bool> primes) {
    int counter = 0;
    for(int i = 2; i < primes.size(); ++i) {
        if(primes.at(i) == true) {
	    ++counter;
	    if(counter == 10001) {
	        std::cout << i << std::endl;
	    }
        }
    }
}
