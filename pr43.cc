#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

const int LENGTH = 10;

bool property(const int nums[]);
long long arrtoint(const int nums[]);
vector<int> getDigits(const int nums[]);


int main () {
    int nums[] = {0,1,2,3,4,5,6,7,8,9};
    sort (nums, nums+LENGTH);
    long long sum = 0;
    do {
        if(nums[0] != 0 && nums[9] != 0) {
            if(property(nums)) {
                sum += arrtoint(nums);
                cout << ">>> " << arrtoint(nums) << endl;
            }
        }
    } while ( next_permutation (nums,nums+LENGTH) );
    cout << "> " << sum << endl;
    return EXIT_SUCCESS;
}

vector<int> getDigits(const int nums[]) {
    vector<int> digits;
    string tmp = "";
    for(int i = 1; i < 8; ++i) {
        stringstream flow; flow << nums[i] << nums[i+1] << nums[i+2];
        int digs = 0; flow >> digs;
        digits.push_back(digs);
    }
    return digits;
}
        
bool property(const int nums[]) {
    const int SIZE = 7;
    int divs[] = {2,3,5,7,11,13,17};
    vector<int> digits = getDigits(nums);
    for(int i = 0; i < SIZE; ++i) {
        if(digits.at(i) % divs[i] != 0) {
            return false;
        }
    }
    return true;
}

long long arrtoint(const int nums[]) {
    stringstream flow;
    for(int i = 0; i < LENGTH; ++i) {
        flow << nums[i];
    }
    long long result = 0; flow >> result;
    return result;
}
