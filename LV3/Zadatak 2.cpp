#include <iostream>
#include <vector>
#include <string>

using namespace std;

int brojStudenataNaPredmetu(const string &predmet, const vector<vector<string>> &predmeti) {
    int brojac(0);
    for (int i = 0; i < predmeti.size(); i++) {
        for (int j = 0; j < predmeti[i].size(); j++) {
            if (predmeti[i][j] == predmet) {
                brojac++;
                break;
            }
        }
    }
    return brojac;
}

void ispisiStudenteNaPredmetu(const string &predmet, const vector<vector<string>> &predmeti, const vector<string> &studenti) {
    for (int i = 0; i < predmeti.size(); i++) {
        for (int j = 0; j < predmeti[i].size(); j++) {
            if (predmeti[i][j] == predmet) {
                cout<<studenti[i]<<" slusa ovaj predmet!"<<endl;
                break;
            }
        }
    }
}

void dodajPredmet(const string &predmet, const string &student, vector<vector<string>> &predmeti, const vector<string> &studenti) {
    int indeks_studenta(0);
    for (int i = 0; i < studenti.size(); i++) {
        if (studenti[i] == student) {
            indeks_studenta = i;
            break;
        }
    }
    predmeti[indeks_studenta].push_back(predmet);
    cout<<"Dodao predmet!"<<endl;
}

int main() {
    vector<string> studenti;
    vector<vector<string>> predmeti;

    while (true) {
        string ime;
        getline(cin, ime); // Unijeti: S1, S2, kraj
        if (ime == "KRAJ") break;
        studenti.push_back(ime);
    }

    for (int i = 0; i < studenti.size(); i++) {
        vector<string> predmeti_po_studentu;

        cout << endl << "------------------------------" << endl;
        cout << "Unesite predmete za studenta: " << studenti[i] << endl;

        while (true) {
            string predmet;
            getline(cin, predmet);
            if(predmet == "KRAJ") break;
            predmeti_po_studentu.push_back(predmet);
        }
        predmeti.push_back(predmeti_po_studentu);
    }

    cout << endl << "------------------------------" << endl;

    cout << endl << "Prije dodavanja predmeta P2 studentu S1." << endl << endl;
    cout << "Studenti na predmetu P2: " << endl;
    ispisiStudenteNaPredmetu("P2", predmeti, studenti);
    cout << endl;
    cout << "Broj studenata na predmetu P2: " << endl << brojStudenataNaPredmetu("P2", predmeti) << endl << endl;

    cout << "------------------------------" << endl << endl;


    dodajPredmet("P2", "S1", predmeti, studenti);
    cout << endl << "------------------------------" << endl;

    cout << endl << "Nakon dodavanja predmeta P2 studentu S1." << endl << endl;
    cout << "Studenti na predmetu P2: " << endl;
    ispisiStudenteNaPredmetu("P2", predmeti, studenti);
    cout << endl;
    cout << "Broj studenata na predmetu P2: " << endl <<brojStudenataNaPredmetu("P2", predmeti) << endl;

    return 0;
}
