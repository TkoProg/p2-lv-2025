#include <iostream>
#include <cmath>

using namespace std;

double funkcija(double niz[], int n) {
    double suma(0);
    for (int i = n - 1; i >= 0; i--) {
        if (suma + niz[i] < 0) throw "Podkorijena vrijednost manja od 0";
        suma = sqrt(suma + niz[i]);
    }
    return suma;
}

int main() {
    double niz[5]={1,2, 3};
    try {
        cout<<funkcija(niz, 3);
    }
    catch (const char* e) {
        cout << "Greska: " << e << endl;
    }
    catch(...) {
        cout<<"Greska..."<<endl;
    }
    cout<<"Ovdje bi dalje isao nastavak programa!";
    return 0;
}
