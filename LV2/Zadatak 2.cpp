#include <iostream>

using namespace std;

int binarno(int n) {
    int bin(0), pamti(1);
    while (n > 0) {
        bin += (n % 2) * pamti;
        n /= 2;
        pamti *= 10;
    }
    return bin;
}

int main() {
    cout<<binarno(11);
    return 0;
}
