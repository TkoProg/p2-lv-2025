#include <iostream>

using namespace std;

void foo(int niz[], int n, int &negativni, int &razliciti) {
    negativni = 0;
    razliciti = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] < 0) negativni++;
    }
    for (int i = 0; i < n; i++) {
        bool postoji = false;
        for (int j = 0; j < i; j++) {
            postoji = true;
            break;
        }
        if (!postoji) razliciti++;
    }
}

int main() {
    int niz[] = { 1, -70, 3, -88, 13, 1 };
    int n = sizeof(niz) / sizeof(niz[0]);

    int negativni, razliciti;
    foo(niz, n, negativni, razliciti);

    cout << "Broj negativnih brojeva: " << negativni << endl;
    cout << "Broj različitih elemenata: " << razliciti << endl;

    return 0;
}
