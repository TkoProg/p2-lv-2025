#include <iostream>

using namespace std;

int funkcija(int *prvi, const int *iza_zadnjeg) {
    int brojac(0);
    while (prvi < iza_zadnjeg) {
        cout<<prvi<<" "<<iza_zadnjeg<<endl;
        if (*prvi > 99 and *prvi < 1000) brojac++;
        prvi++;
    }
    return brojac;
}

int funkcija2(int *prvi, const int *iza_zadnjeg) {
    int brojac(0);
    for (int *pok = prvi; pok < iza_zadnjeg; pok++) {
        cout<<prvi<<" "<<iza_zadnjeg<<endl;
        if (*pok > 99 and *pok < 1000) brojac++;
    }
    return brojac;
}

int main() {
    int niz[]={1,200,300,4,5};
    int broj = funkcija(niz, niz+5);
    cout<<broj<<endl;
    int broj2 = funkcija2(niz, niz+5);
    cout<<broj2;
    return 0;
}
