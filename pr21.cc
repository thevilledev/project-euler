#include <iostream>
#include <set>
using namespace std;

int getDivisors(const int num);
bool isLegit(const int a, const int b, const set<pair<int, int> > amicables);
int getSum(const set<pair<int, int> > amicables);

int main() {
    set<pair<int, int> > amicables;
    for(int i = 1; i < 10000; ++i) {
        int divisors = getDivisors(i);
        if(getDivisors(divisors) == i) {
            if(isLegit(i, divisors, amicables)) {
                amicables.insert(make_pair(i, divisors));
            }
        }
    }
    cout << getSum(amicables) << endl;
}

int getDivisors(const int num) {
    int divs = 0;
    for(int i = 1; i <= num/2; ++i) {
        if(num % i == 0) {
            divs += i;
        }
    }
    return divs;
}

bool isLegit(const int a, const int b, const set<pair<int, int> > amicables) {
    if( a == b) {
        return false;
    }
    for(set<pair<int, int> >::const_iterator iter = amicables.begin();
        iter != amicables.end(); ++iter) {
            if(iter->first == b && iter->second == a) {
                return false;
            }
    }
    return true;
}

int getSum(const set<pair<int, int> > amicables) {
    int summa = 0;
    for(set<pair<int, int> >::const_iterator iter = amicables.begin();
        iter != amicables.end(); ++iter) {
            summa += iter->first;
            summa += iter->second;
    }       
    return summa;
}   

