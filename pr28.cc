#include <iostream>
using namespace std;

int main() {
    int sum = 1;
    int level = 1;
    int difference = 2;
    int current = 1;
    while(level <= 500) {
        for(int i = 1; i <= 4; ++i) {
            current += difference;
            sum += current;
        }
        ++level;
        difference += 2;
    }
    cout << "> " << sum << endl;
}
