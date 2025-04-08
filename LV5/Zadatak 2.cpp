#include <iostream>

using namespace std;

template <typename Tip>
void SmjestiMinIMax(Tip *pocetak, Tip *iza_kraja, Tip **min, Tip **max) {
    *min = pocetak;
    *max = pocetak;
    for (int *pok = pocetak; pok < iza_kraja; pok++) {
        if (**min > *pok) *min = pok;
        if (**max < *pok) *max = pok;
    }
}

int main() {
    int niz[] = {6,2,4,8,6,1,3};
    int *min, *max;
    SmjestiMinIMax(niz, niz+7, &min, &max);
    cout<<&min<<endl;
    cout<<&max<<endl;
    cout<<&niz[5]<<endl;
    cout<<&niz[3]<<endl;
    cout<<*min<<endl;
    cout<<*max<<endl;
    return 0;
}
