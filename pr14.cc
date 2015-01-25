#include <iostream>
using namespace std;

int main() {
    long long numero = 0;
    int maxS, maxN = 0;
    for(int i = 3; i < 1000000; i+=2) {
        numero = i;
        int seq = 1;
        while(numero > 1) {
            if(numero%2==0)
                numero = numero/2;
            else
                numero = (numero*3)+1;
            ++seq;
        }
        if(seq > maxS) {
            maxS = seq;
            maxN = i;
        }
    }
    cout << "> " << maxN << endl;
}
