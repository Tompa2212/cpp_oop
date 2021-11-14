#include "Prostor.h"

class Hotel {
private:
	vector<Prostor*> prostori;
public:
	Hotel(){}
	Hotel(Prostor* p) { prostori.push_back(p); }

	void dodajProstore(vector<Prostor*> p) {
		for (auto prostor : p)
			prostori.push_back(prostor);
	}

	void ispis() {
		for (auto prostor : prostori) {
			prostor->ispisi();
		}
	}
};

