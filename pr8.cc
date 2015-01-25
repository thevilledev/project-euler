#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

string readfile(string filename);
int  getproduct(const string num);

int main(int argc, char** argv) {
    int max = 0;
    string data = readfile(argv[1]);
    for(int i = 99999; i >= 10000; --i) {
        stringstream flow; flow << i; string num_str = flow.str();
        if(data.find(num_str) != string::npos) {
            int product = getproduct(num_str);
            if(product > max) {
                max = product;
            }
        }
    }
    cout << "> " << max << endl;
    return EXIT_SUCCESS;
}

string readfile(string filename) {
    string content = ""; string tmp = "";
    ifstream flow(filename.c_str());
    while(getline(flow, tmp)) {
        content += tmp;
    }
    return content;
}

int getproduct(const string num) {
    int tulo = 1;
    for(int i = 0; i < num.size(); ++i) {
        stringstream flow; flow << num.at(i);
        int num_int = 0; flow >> num_int;
        tulo *= num_int;
    }
    return tulo;
}
