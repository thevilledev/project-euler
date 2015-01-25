#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
using namespace std;

void sieve(vector<bool>& primes, const int limit);
void rotateleft(string& number);
bool isprime(const vector<bool> primes, const int candidate);
bool islegit(const vector<bool> primes, const int candidate);
string int2str(const int number);
int str2int(const string number);

int main() {
    int counter = 0;
    int limit = 1000000;
    vector<bool> primes(limit+1, true);
    sieve(primes, limit);
    for(int i = 1; i < primes.size(); i+=2) {
        if(primes.at(i) && islegit(primes, i)) {
            ++counter;
        }
    }
    cout << "> " << counter << endl;
    return EXIT_SUCCESS;
}

void sieve(vector<bool>& primes, const int limit) {
    for(int i = 2; i*i <= limit; ++i) {
        for(int k = 2; k <= limit/i; ++k) {
            primes.at(i*k) = false;
        }
    }
}

void rotateleft(string& number) {
    rotate(number.begin(), number.begin()+1, number.end());
}

bool isprime(const vector<bool> primes, const int candidate) {
    return primes.at(candidate);
}

bool islegit(const vector<bool> primes, const int candidate) {
    string number = int2str(candidate);
    for(int k = 0; k < number.size()-1; ++k) {
        rotateleft(number);
        if(!isprime(primes, str2int(number))) {
            return false;
        }
    }
    return true;
}

string int2str(const int number) {
    stringstream flow; flow << number;
    string transformed = flow.str();
    return transformed;
}

int str2int(const string number) {
    stringstream flow(number);
    int transformed = 0; flow >> transformed;
    return transformed;
}
