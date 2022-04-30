#include "gbl.h"
#include "cValija.h"

// implementacion cValija

// inicializacion atributos estaticos
ush cValija::cantActual = 0;
sh cValija::cantTotal = 0;

cValija::cValija(float _peso) {
	// inicializacion de los atributos
	// por cada obj. generado, aumento su capacidad actual
	cantActual++;
	this->peso = _peso;
}
cValija::~cValija() {
	// por cada obj. destruido, disminuyo su capacidad actual
	cantActual--;
}

string cValija::to_string() const {
	stringstream stc;
	stc << "Cantidad total: " << cantTotal << endl;
	stc << "Cantidad actual: " << cantActual << endl;
	stc << "Peso: " << peso << endl;
	return stc.str();
}
