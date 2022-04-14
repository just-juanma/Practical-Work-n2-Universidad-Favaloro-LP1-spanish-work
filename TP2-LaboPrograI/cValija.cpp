#include "gbl.h"
#include "cValija.h"

// implementacion cValija

cValija::cValija(double _peso) {
	// inicializacion de los atributos
	this->peso = _peso;
}
cValija::~cValija() {
	// no tengo nada que eliminar
}

string cValija::to_string() {
	stringstream stc;
	stc << "Peso:" << peso;
	stc << endl;
	return stc.str();
}

string cValija::imprimir()
{
	cout << to_string();
}
