#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b, rez;
    char o;
    cout<<"Unesite broj: ";
    cin>>a;
    cout<<"Unesite broj: ";
    cin>>b;
    cout<<"Unesite operaciju: ";
    cin>>o;

    if (o == '+') {
        rez = a + b;
    }
    else if (o == '-') {
        rez = a - b;
    }
    else if (o == '*') {
        rez = a * b;
    }
    else if (o == '/') {
        rez = a / b;
    }
    else {
        cout<<"Znak nije ispravan!";
        return 0;
    }

    cout<<setw(7)<<a<<endl<<setw(7)<<b<<" "<<o<<endl<<"---------"<<endl<<setw(7)<<rez;
}
