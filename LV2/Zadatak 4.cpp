#include <iostream>

using namespace std;

int main() {
    int n, place, brojac(0), najveca(0), holding(0), broj(0);
    while (cin>>n, n!= 0) {
        place = n;
        while (n != 0) {
            if (n % 10 > najveca) najveca = n % 10;
            n /= 10;
        }
        n = place;
        while (n != 0) {
            if (n % 10 == najveca) brojac++;
            n /= 10;
        }
        if (brojac > holding) {
            broj = place;
            holding = brojac;
        }
    }
    cout<<"Trazeni broj je: "<<broj;
    return 0;
}
