#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;

void sieve(vector<bool>& primes, const int limit);
bool isprime(int n);
bool truncR(int num);
bool truncL(int num);
string int2str(const int number);
int str2int(const string number);

int main() {
    int limit = 1000000;
    int sum = 0; int counter = 0;
    vector<bool> primes(limit+1, true);
    sieve(primes, limit);
    for(int i = 10; i < primes.size(); ++i) {
       if(primes.at(i)) {
            if(truncR(i) && truncL(i)) {
                cout << "*** " << i << endl; 
                sum += i; ++counter;
            }
        }
    }
    cout << "> " << sum << endl;
    return EXIT_SUCCESS;
}

void sieve(vector<bool>& primes, const int limit) {
    for(int i = 2; i*i <= limit; ++i) {
        for(int k = 2; k <= limit/i; ++k) {
            primes.at(i*k) = false;
        }
    }
}

bool isprime(int n) {
    if(n <= 1) {
        return false;
    }
    else if(n != 2 && n % 2 == 0) {
        return false;
    }
    for(long int i = 3; i*i <= n; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

bool truncR(int num) {
    string num_str = int2str(num);
    for(int i = num_str.size()-1; i >= 1; --i) {
        int subnum = str2int(num_str.substr(0, i));
        if(!isprime(subnum)) {
            return false;
        }
    }
    return true;
}

bool truncL(int num) {
    string num_str = int2str(num);
    for(int i = 1; i < num_str.size(); ++i) {
        string tmp = num_str; tmp.erase(tmp.begin(),tmp.begin()+i);
        int subnum = str2int(tmp);
        if(!isprime(subnum)) {
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
