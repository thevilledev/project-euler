#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int LENGTH = 10;

int main () {
    int nums[] = {0,1,2,3,4,5,6,7,8,9};
    int counter = 1;
    do {
        ++counter;
    } while ( next_permutation (nums,nums+LENGTH) && counter < 1000000 );
    for(int i = 0; i < LENGTH; ++i) {
        cout << nums[i];
    }
    cout << endl;
    return EXIT_SUCCESS;
}
