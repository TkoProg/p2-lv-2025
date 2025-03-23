#include <iostream>

using namespace std;

int main() {
    char predmeti[50][50];
    char studenti[50][50];
    int broj_predmeta = 0, broj_studenata = 0;

    cout<<"Unesite broj predmeta: ";
    cin>>broj_predmeta;

    cout<<"Unesitebroj studenata: ";
    cin>>broj_studenata;

    cin.ignore(10000, '\n');

    for (int i = 0; i < broj_predmeta; i++) {
        cout<<"Unesite predmet: ";
        cin.getline(predmeti[i], 50);
    }

    for (int i = 0; i < broj_studenata; i++) {
        cout<<"Unesite studente: ";
        cin.getline(studenti[i], 50);
    }

    int ocjene[50][50];

    for (int i = 0; i < broj_studenata; i++) {
        cout<<"Ocjene za studenta: "<<studenti[i]<<endl;
        for (int j = 0; j < broj_predmeta; j++) {
            cout<<predmeti[j]<<": ";
            cin>>ocjene[i][j];
        }
        cout<<"-------------------------"<<endl;
    }

    for (int i = 0; i < broj_studenata; i++) {
        int prosjek_studenta(0);
        for (int j = 0; j < broj_predmeta; j++) {
            prosjek_studenta += ocjene[i][j];
        }
        cout<<"Prosjek studenta "<<studenti[i]<<" je: "<<double(prosjek_studenta) / broj_predmeta<<endl;
    }

    cout<<"-------------------------"<<endl;

    for (int i = 0; i < broj_predmeta; i++) {
        int prosjek_predmeta(0);
        for (int j = 0; j < broj_studenata; j++) {
            prosjek_predmeta += ocjene[j][i];
        }
        cout<<"Prosjek ocjena "<<predmeti[i]<<" je: "<<double(prosjek_predmeta) / broj_studenata<<endl;
    }

    return 0;
}
