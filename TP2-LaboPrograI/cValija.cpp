#include "gbl.h"
#include "cValija.h"

// implementacion cValija

// inicializacion atributos estaticos

cValija::cValija(float _peso) {
	// inicializacion de los atributos
	// por cada obj. generado, aumento su capacidad actual
	this->peso = _peso;
}
cValija::~cValija() {
	// por cada obj. destruido, disminuyo su capacidad actual
}

string cValija::to_string() const {
	stringstream stc;
	stc << "Peso: " << peso << endl;
	return stc.str();
}
