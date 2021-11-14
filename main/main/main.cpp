#include "Hotel.h"

int main() {
    
    Rezervacija r1("18/01/2021", 7);
    Rezervacija r2("17/01/2021", 3);

    vector<Prostor*> prostori;

    JavniProstor jp1(r1, "Bazen", 200);
    jp1.addReservation(r2);
    Soba s1(r2, 2);
    prostori.push_back(&jp1);
    prostori.push_back(&s1);

    
    Hotel hotel;
    hotel.dodajProstore(prostori);
    hotel.ispis();
}

