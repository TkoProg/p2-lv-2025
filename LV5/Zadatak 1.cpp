#include <iostream>

using namespace std;

template <typename Tip>
void Obrni(Tip *pocetak, Tip *iza_kraja) {
    iza_kraja = iza_kraja - 1;
    while (pocetak < iza_kraja) {
        Tip temp = *pocetak;
        *pocetak = *iza_kraja;
        *iza_kraja = temp;
        pocetak++;
        iza_kraja--;
    }
}

// 1 2 3 4 5
// 5 4 3 2 1

int main() {
    int niz[]={1,2,3,4,5};
    Obrni(niz+1, niz+5);
    for (int i : niz) {
        cout<<i<<endl;
    }
    return 0;
}