#include <iostream>

using namespace std;

int main() {
    int n;
    cout<<"Unesite broj: ";
    cin>>n;
    for (int i = 0; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            cout<<" ";
        }
        for (int k = 0; k < i; k++) {
            cout<<"* ";
        }
        cout<<endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            cout<<" ";
        }
        for (int j = n - i; j > 0; j--) {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
