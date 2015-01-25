#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

vector<int> readFile(const string filename);
vector<int> decrypt(const vector<int> numbers, const int a, const int b, const int c);
string getStory(const vector<int> decrypted);
bool validStory(const string story);
int getSum(const string story);
int str2int(const string number);

int main(int argc, char** argv) {
    if(argc != 2) {
        cout << "Argument fail." << endl;
        return EXIT_FAILURE;
    }
    vector<int> numbers = readFile(argv[1]);
    for(int a = 97; a <= 122; ++a) {
        for(int b = 97; b <= 122; ++b) {
            for(int c = 97; c <= 122; ++c) {
                vector<int> decrypted = decrypt(numbers, a, b, c);
                string story = getStory(decrypted);
                if(validStory(story)) {
                    cout << "***" << endl;
                    cout << story << endl;
                    cout << "***" << endl;
                    cout << "Key: " << static_cast<char>(a) << static_cast<char>(b) << static_cast<char>(c) << endl;
                    cout << "Sum: " << getSum(story) << endl;
                    return EXIT_SUCCESS;
                }
            }
        }
    }
    return EXIT_FAILURE;
}

vector<int> readFile(const string filename) {
    ifstream flow(filename.c_str());
    string number = ""; char input = ' ';
    vector<int> numbers;
    while(flow >> input) {
        if(input != ',') {
            number += input;
        }
        else {
            numbers.push_back(str2int(number));
            number = "";
        }
    }
    numbers.push_back(str2int(number));
    return numbers;
}

vector<int> decrypt(const vector<int> numbers, const int a, const int b, const int c) {
    const int VARS[] = {a,b,c};
    vector<int> decr;
    int modulo = 0;
    for(unsigned int i = 0; i < numbers.size(); ++i) {
        int number = numbers.at(i);
        int number_decrypted = VARS[modulo % 3] ^ number;
        decr.push_back(number_decrypted); ++modulo;
    }
    return decr;
}

string getStory(const vector<int> decrypted) {
    string answer = "";
    for(unsigned int i = 0; i < decrypted.size(); ++i) {
        answer += static_cast<char>(decrypted.at(i));
    }
    return answer;
}

bool validStory(const string story) {
    if(story.find("beginning") != string::npos) {
        return true;
    }
    return false;
}

int getSum(const string story) {
    int sum = 0;
    for(unsigned int i = 0; i < story.size(); ++i) {
        sum += static_cast<int>(story.at(i));
    }
    return sum;
}

int str2int(const string number) {
    stringstream flow(number);
    int transformed = 0; flow >> transformed;
    return transformed;
}
