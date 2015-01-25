#include <iostream>
#include <sstream>
using namespace std;

bool correct(const int number);
string int2str(const int number);
int str2int(const string number);

int main() { 
    int number = 1;
    do {
        ++number;
    } while (!correct(number));
    cout << "> " << number << endl;
}

bool correct(const int number) {
    string cmp = int2str(number);
    for(int i = 2; i <= 6; ++i) {
        string newnumber = int2str(i*number);
        for(int k = 0; k < newnumber.size(); ++k) {
            if(cmp.find(newnumber.at(k)) == string::npos) {
                return false;
            }
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
