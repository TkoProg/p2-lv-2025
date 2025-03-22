#include <iostream>

using namespace std;

void binarno(int n) {
    int bin(0), pamti(1);
    while (n > 0) {
        bin += (n % 2) * pamti;
        n /= 2;
        pamti *= 10;
    }
    cout<<bin;
}

int main() {
    binarno(11);
    return 0;
}
