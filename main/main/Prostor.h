#include "Rezervacija.h"
class Iznimka {
public:
	void ispisIznimke() {
		cout << "Nije moguca rezevacija u tom terminu\n";
	}
};

class Prostor {
private:
	vector<Rezervacija> rezervacije;
public:
	Prostor(){}
	Prostor(Rezervacija& r) { rezervacije.push_back(r); }
	Prostor(vector<Rezervacija>& r) {
		for (auto i : r) rezervacije.push_back(i);
	}
	void addReservation(Rezervacija& r);
	vector<Rezervacija>& getReservations() { return rezervacije; }
	bool isFree(Rezervacija& r);

	//POLIMORFIZAM
	virtual void ispisi() = 0;
};


class JavniProstor : public Prostor {
private:
	string kategorija;
	int kapacitet;
public:
	JavniProstor(string cat, int cap) : kategorija(cat), kapacitet(cap){}
	JavniProstor(Rezervacija& r, string cat, int cap) : Prostor(r), kategorija(cat), kapacitet(cap) {}
	JavniProstor(vector<Rezervacija>& r, string cat, int cap) : Prostor(r), kategorija(cat), kapacitet(cap) {}

	void setCategory(string cat) { kategorija = cat; }
	void setCapacity(int cap) { kapacitet = cap; }

	string getCategory() { return kategorija; }
	int getCapacity() { return kapacitet; }

	//POLIMORFIZAM
	void ispisi();
};

class Soba : public Prostor {
private:
	int brKreveta;
public:
	Soba(int br) : brKreveta(br){}
	Soba(Rezervacija& r, int br) : Prostor(r), brKreveta(br) {}
	Soba(vector<Rezervacija>& r, int br) : Prostor(r), brKreveta(br) {}

	void setBrKreveta(int br) { brKreveta = br; }

	int getBrKreveta() { return brKreveta; }

	//POLIMORFIZAM
	void ispisi();
};


