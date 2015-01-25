#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int ASCII = 48;

int main() {
    string concat = "";
    int counter = 1;
    int product = 1;
    while(concat.size() <= 1000000) {
        stringstream flow; flow << counter;
        string tmp = flow.str();
        concat += tmp;
        ++counter;
    }
    for(int i = 1; i <= 1000000; i *= 10) {
        product *= concat.at(i-1)-ASCII;
    }
    cout << "> " << product << endl;
}
