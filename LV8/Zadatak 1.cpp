#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class StavkaNarudzbe {
public:
    string nazivArtikla;
    double kolicina;
    double cijena;

    StavkaNarudzbe(
            string aNazivArtikla,
            double aKolicina,
            double aCijena
            ):
            nazivArtikla(aNazivArtikla),
            kolicina(aKolicina),
            cijena(aCijena) {

    }
};

class Narudzba {
private:
    string nazivKupca;
    time_t datumNarudzbe; // tip podatka za datum + vrijeme
    time_t datumIsporuke;
protected:
    vector<StavkaNarudzbe> stavke;
public:
    string komercijalista;
    string adresaKupca;
    string mjestoKupca;
    string drzavaKupca;

    Narudzba() {
        cout<<"Kreiram se bez parametara...\n";
    }

    Narudzba(string aKomercijalista,
             string aNazivKupca,
             string aAdresaKupca,
             string aMjestoKupca,
             string aDrzavaKupca,
             time_t aDatumIsporuke):
             komercijalista(aKomercijalista),
             nazivKupca(aNazivKupca),
             adresaKupca(aAdresaKupca),
             mjestoKupca(aMjestoKupca),
             drzavaKupca(aDrzavaKupca),
             datumIsporuke(aDatumIsporuke){
        // drzavaKupca = aDrzavaKupca; Ovo je isto kao i gore sto je
        datumNarudzbe = time(NULL); // Ovo znaci da uzmemo trenutno vrijeme (datum)

    }

    ~Narudzba() {
        cout << "Unistavam se...\n";
    }

    string getNazivKupca() {
        if (true) // ima pravo?
            return nazivKupca;
        return "Nepoznat";
    }

    void setNazivKupca(string aNazivKupca) {
        cout<<"Dolazi do promjene naziva kupca! Paznja!"<<endl;
        nazivKupca = aNazivKupca;
    }

    time_t getDatumIsporuke() {
        return datumIsporuke; // Isporuka za 5 dana
    }

    // Ispisi je metoda (Metode se pisu malim slovima po konvenciji
    void ispisi() {
        cout<<"Komercijalista: "<<komercijalista<<endl;
        cout<<"Kupac: "<<nazivKupca<<endl;
        // cout<<"Datum narudzbe: "<<datumNarudzbe<<endl; ne moze

        struct tm d = *localtime(&datumNarudzbe);
        cout<<"Datum narudzbe: "<<d.tm_mday<<"."<<1 + d.tm_mon<<"."<<1900+ d.tm_year<<"."<<endl;
        auto di = getDatumIsporuke();
        d = *localtime(&di);
        cout<<"Datum isporuke: "<<d.tm_mday<<"."<<1 + d.tm_mon<<"."<<1900+ d.tm_year<<"."<<endl;
        cout<<"Iznos: "<<iznosNarudzbe()<<endl;
        auto brojac(0);
        for (auto &s: stavke) {
            cout<< ++brojac <<". "<<s.nazivArtikla<<" "<<s.kolicina<<" "<<s.cijena<<endl;
        }
    }

    double iznosNarudzbe() {
        auto suma(0.0);
        for(auto &s: stavke) {
            suma += s.kolicina * s.cijena;
        }
        return suma;
    }

    bool validnaNarudzba() {
        return (datumNarudzbe != 0) &&
        (komercijalista.size() != 0) &&
        (nazivKupca.size() != 0) &&
        (stavke.size() != 0);
    }

    void dodajStavku(StavkaNarudzbe &sn) {
        stavke.push_back(sn);
    }

    void izmjeniStavku(int pozicija, StavkaNarudzbe &sn) {
        stavke[pozicija] = sn;
    }

    void obrisiStacku(int pozicija) {
        stavke.erase(stavke.begin()+pozicija);
    }

    friend ostream& operator<<(ostream &os, Narudzba &n) {
        os<<"Komercijalista: "<<n.komercijalista<<endl;
        os<<"Kupac: "<<n.nazivKupca<<endl;
        // cout<<"Datum narudzbe: "<<datumNarudzbe<<endl; ne moze

        struct tm d = *localtime(&n.datumNarudzbe);
        os<<"Datum narudzbe: "<<d.tm_mday<<"."<<1 + d.tm_mon<<"."<<1900+ d.tm_year<<"."<<endl;
        auto di = n.getDatumIsporuke();
        d = *localtime(&di);
        os<<"Datum isporuke: "<<d.tm_mday<<"."<<1 + d.tm_mon<<"."<<1900+ d.tm_year<<"."<<endl;
        os<<"Iznos: "<<n.iznosNarudzbe()<<endl;
        auto brojac(0);
        for (auto &s: n.stavke) {
            cout<< ++brojac <<". "<<s.nazivArtikla<<" "<<s.kolicina<<" "<<s.cijena<<endl;
        }
    }
};

int main() {
    // auto n = Narudzba();
    // Narudzba n;
    /* Narudzba n = Narudzba();
    n.komercijalista = "Ime i prezime";
    n.nazivKupca = "KomercImport d.o.o. Sarajevo";
    cout<<"Komercijalista = "<<n.komercijalista<<endl; */
    auto n = Narudzba("Ime i prezime","KomercImport d.o.o. Sarajevo", "Ulica neka bb", "Sarajevo", "BiH", time(NULL));
    // n.dodajStavku(StavkaNarudzbe("A4 papir", 10, 8.5));
    // n.dodajStavku(StavkaNarudzbe("Toner", 1, 35));
    // n.dodajStavku(StavkaNarudzbe("Plavi marker", 5, 2));
    auto sn = StavkaNarudzbe("Stampac", 1, 300);
    n.dodajStavku(sn);
    n.ispisi();
    n.ispisi();
    cout<<n.getNazivKupca()<<endl;
    // Ovo bi bio problem
    // n.stavke = vector<StavkaNarudzbe>();
    cout<<n;
    return 0;
}
