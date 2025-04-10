#include <iostream>
#include <vector>

using namespace std;

void Sortiraj(vector<vector<int>> &vektori) {
    int brojac = 1;
    while (true) {
        for (int i = 1; i < vektori.size(); i++) {
            bool isti = true;
            for (int j = 0; j < vektori[i].size(); j++) {
                if (vektori[i - 1][j] == vektori[i][j]) continue;
                else if (vektori[i - 1][j] > vektori[i][j]) {
                    vector<int> pomocni = vektori[i];
                    vektori[i] = vektori[i - 1];
                    vektori[i - 1] = pomocni;
                    isti = false;
                    break;
                }
                else if (vektori[i - 1][j] < vektori[i][j]){
                    isti = false;
                    break;
                }
            }
            if (isti) {
                if (vektori[i - 1].size() > vektori[i].size()) {
                    vector<int> pomocni = vektori[i];
                    vektori[i] = vektori[i - 1];
                    vektori[i - 1] = pomocni;
                }
            }
        }
        brojac++;
        if (brojac == vektori.size()) break;
    }
}

int main() {
    vector<vector<int>> a{{1,6,3,5,7}, {2,2,5,4,6}, {1,3,8,5,4}, {1,3,8,5,4,2}};
    Sortiraj(a);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
