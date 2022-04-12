#include "gbl.h"
#include "cPasajero.h"

// implementacion cPasajero
unsigned int cPasajero::numeroAsiento = 0;
cPasajero::cPasajero(const string _nombre, unsigned int _DNI): nombre(_nombre), DNI(_DNI) {
	this->numeroVuelo = vuelo.getNumeroVuelo();
	numeroAsiento++;
}

cPasajero::~cPasajero() {
	numeroAsiento--;
}

//void cPasajero::agregarEquipaje() {
//
//}

//void cPasajero::retirarEquipaje() {
//
//}

