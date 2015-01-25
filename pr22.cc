#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
using namespace std;

const int ASCII = 64;

bool readFile(const string tiedosto);
void parseName(string& parsed);
int getLength(const string name);
int getSum(const map<string, int> cardfile);

int main(int argc, char** argv) {
    if(argc != 2) {
        cout << "FILE OPEN FAIL" << endl;
        return EXIT_FAILURE;
    }
    if(!readFile(argv[1])) {
        cout << "File could not be read." << endl;
    }
}

bool readFile(const string tiedosto) {
    string name = "";
    ifstream flow(tiedosto.c_str());
    map<string, int> cardfile;
    if(!flow) {
        return false;
    }
    while(flow >> name) {
        parseName(name);
        pair<string, int> namelength = make_pair(name, getLength(name));
        cardfile.insert(namelength);
    }
    cout << "> " << getSum(cardfile) << endl;
    return true;
}

void parseName(string& parsed) {
    parsed.erase(parsed.begin());
    parsed.erase(parsed.end()-1);
}

int getLength(const string name) {
    int length = 0;
    for(unsigned int i = 0; i < name.size(); ++i) {
        length += name.at(i) - ASCII;
    }
    return length;
}

int getSum(const map<string, int> cardfile) {
    int counter = 1; int sum = 0;
    for(map<string, int>::const_iterator iter = cardfile.begin(); iter != cardfile.end(); ++iter) {
        sum += iter->second * counter;
        ++counter;
    }
    return sum;
}
