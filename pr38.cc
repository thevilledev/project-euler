#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool isLegit(const string concat);
string int2str(const int number);
int str2int(const string number);

int main() {
    int max = 0;
    for(int i = 9999; i >= 1; --i) {
        string concat = "";
        int counter = 1;
        while(concat.length() < 9) {
            int multiplic = i * counter;
            concat += int2str(multiplic);
            ++counter;
        }
        if(isLegit(concat)) {
            int answer = str2int(concat);
            if(answer > max) {
                max = answer;
            }
        }
    }
    cout << "> " << max << endl;
}

bool isLegit(const string concat) {
    if(concat.find("0") == string::npos) {
        const string numbers = "123456789";
        for(int i = 0; i < numbers.size(); ++i) {
            if(concat.find(numbers.at(i)) == string::npos) {
                return false;
            }
        }
        return true;
    }
    return false;
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
