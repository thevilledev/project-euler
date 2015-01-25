#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

const int ASCII = 64;

bool readFile(const string& tiedosto);
void parseName(string& parsed);
int getLength(const string word);
bool isTriangle(const int length, const vector<int> triangles);

int main(int argc, char** argv) {
    if(argc != 2) {
        cout << "Argument fail." << endl;
        return EXIT_FAILURE;
    }
    if(!readFile(argv[1])) {
        cout << "File open fail." << endl;
    }
    return EXIT_SUCCESS;
}

bool readFile(const string& tiedosto) {
    string word = "";
    ifstream flow(tiedosto.c_str());
    int answer = 0;
    vector<int> values; vector<int> triangles;

    if(!flow) {
        return false;
    }
    while(flow >> word) {
        parseName(word);
        values.push_back(getLength(word));
    }
    for(int n = 1; n <= 19; ++n) {
        double coeff = 0.5*n;
        double num = coeff*(n+1);
        triangles.push_back(static_cast<int>(num));
    }
    for(vector<int>::iterator iter = values.begin(); iter != values.end(); ++iter) {
        if(isTriangle(*iter, triangles)) {  ++answer; }
    }
    cout << "> " << answer << endl;
    return true;
}

void parseName(string& parsed) {
    parsed.erase(parsed.begin());
    parsed.erase(parsed.end()-1);
}

int getLength(const string word) {
    int length = 0;
    for(int i = 0; i < word.size(); ++i) {
        length += word.at(i)-ASCII;
    }
    return length;
}

bool isTriangle(const int length, const vector<int> triangles) {
    for(int i = 0; i < triangles.size(); ++i) {
        if(triangles.at(i) == length) {
            return true;
        }
    }
    return false;
}
