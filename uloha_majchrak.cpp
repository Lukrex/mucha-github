#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Kniha {
private:
    string nazov;
    string autor;
    int rokVydania;
    int pocetStran;

public:
    Kniha(string n, string a, int rok, int strany) {
        nazov = n;
        autor = a;
        rokVydania = rok;
        pocetStran = strany;
    }

    void vypisInfo() {
        cout << "Názov: " << nazov << endl;
        cout << "Autor: " << autor << endl;
        cout << "Rok vydania: " << rokVydania << endl;
        cout << "Počet strán: " << pocetStran << endl;
    }

    bool jeStara() {
        time_t cas = time(nullptr);
        int aktualnyRok = localtime(&cas)->tm_year + 1900;
        return (aktualnyRok - rokVydania) > 50;
    }
};

int main() {
    Kniha k1("1984", "George Orwell", 1949, 328);
    Kniha k2("Malý princ", "Antoine de Saint-Exupéry", 1943, 96);
    Kniha k3("Harry Potter a Kameň mudrcov", "J. K. Rowlingová", 1997, 336);

    Kniha knihy[] = { k1, k2, k3 };

    for (Kniha& k : knihy) {
        k.vypisInfo();
        if (k.jeStara()) {
            cout << "Táto kniha je stará!" << endl;
        } else {
            cout << "Táto kniha nie je stará." << endl;
        }
        cout << "------------------------" << endl;
    }

    return 0;
}