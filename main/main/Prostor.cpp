#include "Prostor.h"
void Prostor::addReservation(Rezervacija& r) {
	try {
		if (isFree(r)) {
			rezervacije.push_back(r);
		}
	}
	catch (Iznimka& i) {
		i.ispisIznimke();
	}
}

bool Prostor::isFree(Rezervacija& r) {
	int check = 1;
	for (int i = 0; i < this->rezervacije.size(); i++) {
		if (r.getMjesec() == this->rezervacije[i].getMjesec()) {

			int danNoveRezervacije = r.getDan();
			int duljinaNoveRezervacije = (r.getDan() + r.getTrajanje()) % 31;

			int danRezervacije = this->rezervacije[i].getDan();
			int duljinjaRezervacije = (this->rezervacije[i].getDan() + this->rezervacije[i].getTrajanje()) % 31;

			
			if ((danNoveRezervacije >= danRezervacije && danNoveRezervacije <= duljinjaRezervacije) ||
				(duljinaNoveRezervacije >= danRezervacije && duljinaNoveRezervacije <= duljinjaRezervacije)) {
				check = 0;
				throw Iznimka();
			}
		}
	}
	return check;
}



void JavniProstor::ispisi() {
	cout << "Kategorija: " << kategorija << ", kapacitet: " << kapacitet << endl;

	cout << "Rezervacije\n";
	for (auto i : this->getReservations()) {
		cout << i << endl;
	}
}

void Soba::ispisi() {
	cout << "Kategorija: Soba\n";
	cout << "Broj kreveta u sobi: " << brKreveta << endl;

	cout << "Rezervacije\n";
	for (auto i : this->getReservations()) {
		cout << i << endl;
	}
}

