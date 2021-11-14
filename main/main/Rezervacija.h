#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Rezervacija {
private:
	string datum_vrijeme;
	int trajanje = 0;
public:
	Rezervacija(){}
	Rezervacija(string d, int t) : datum_vrijeme(d), trajanje(t){}

	void setDatum(string d) { datum_vrijeme = d; }
	void setTrajanje(int t) { trajanje = t; }

	string getDatum() const { return datum_vrijeme; }
	int getTrajanje() const { return trajanje; }

	int getDan();
	int getMjesec();

	friend ostream& operator <<(ostream& izlaz, Rezervacija& r);
};

ostream& operator <<(ostream& izlaz, Rezervacija& r);

