#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n(0), r(0), pomocna(0);
    cin>>n;
    pomocna = n;
    while (true) {
        if (n == 0) {
            r /= 10;
            break;
        }
        r += n % 10;
        r *= 10;
        n = n / 10;
    }
    cout<<abs(pomocna-r);
    return 0;
}
