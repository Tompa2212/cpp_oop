#include "Rezervacija.h"

ostream& operator<<(ostream& izlaz, Rezervacija& r) {
    izlaz << "Datum i vrijeme rezervacije: " << r.datum_vrijeme << endl;
    izlaz << "Trajanje rezervacije: " << r.trajanje << " dana." << endl;

    return izlaz;
}

int Rezervacija::getDan() {
    string str = datum_vrijeme.substr(0, 2);
    return stoi(str);
}

int Rezervacija::getMjesec() {
    string str = datum_vrijeme.substr(3, 5);
    return stoi(str);
}
