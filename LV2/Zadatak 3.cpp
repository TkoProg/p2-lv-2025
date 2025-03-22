#include <iostream>

using namespace std;

int main() {
    int n, najveca(0), broj(0), proba(0), holding(0), place;
    cout<<"Unesite broj: ";
    cin>>n;
    for (int i = 0; i < n; i++) {
        int brojac(0);
        cin>>proba;
        place = proba;
        while (proba != 0) {
            if (proba % 10 > najveca) najveca = proba % 10;
            proba /= 10;
        }
        proba = place;
        while (proba != 0) {
            if (proba % 10 == najveca) brojac++;
            proba /= 10;
        }
        if (brojac > holding) {
            broj = place;
            holding = brojac;
        }
    }
    cout<<"Trazeni broj je: "<<broj;
    return 0;
}
