#include <iostream>

using namespace std;

template <typename Tip>

void f(Tip a[], int n, Tip x[]) {
    // Dakle ideja je formirati 2 niza, jedan niz gdje su
    // elementi proizvod lijevo od broja, drugi su desno
    /// a = {2,3,4,5,6}
    /// b = {1,2,6,24,120}
    /// c = {360,120,30,6,1}
    int b[100];
    b[0] = 1;
    for (int i = 1; i < n; i++) {
        b[i] = b[i-1] * a[i-1];
    }
    int c[100];
    c[n-1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        c[i] = c[i+1] * a[i+1];
    }
    for (int i = 0; i < n; i++) x[i] = b[i] * c[i];
}

int main() {
    int niz[] = {2,3,4,5,6};
    int rez[] = {0,0,0,0,0};
    f(niz, 5, rez);
    for (int i = 0; i < 5; i++) {
        cout<<rez[i]<<endl;
    }
    return 0;
}
