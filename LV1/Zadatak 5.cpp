#include <iostream>

using namespace std;

int main() {
    int n, pamti, najvise, broj_najvecih(0);
    while (true) {
        cin>>n;
        if (n == 0) break;
        int brojac(0);
        pamti = n;
        while (true) {
            if (n == 0) break;
            if((n%10) % 2 != 0) brojac++;
            n = n / 10;
        }
        if (brojac > broj_najvecih) {
            broj_najvecih = brojac;
            najvise = pamti;
        }
    }
    cout<<najvise;
    return 0;
}
