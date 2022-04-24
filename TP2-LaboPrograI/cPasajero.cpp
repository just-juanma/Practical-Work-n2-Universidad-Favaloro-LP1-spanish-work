#include "gbl.h"
#include "cPasajero.h"

// implementacion cPasajero

cPasajero::cPasajero(string _nombre, string _DNI, sh _numeroVuelo, sh _asiento): nombre(_nombre), DNI(_DNI) {
	this->numeroVuelo = _numeroVuelo;
	this->asiento = _asiento;
	this->fecha = NULL;
}

cPasajero::~cPasajero() { }



string cPasajero::to_string() {
	stringstream stc;
	stc << "Nombre: " << this->nombre << endl;
	stc << "DNI: " << this->DNI << endl;
	stc << "Fecha: ";
	stc << this->fecha->dia << "/";
	stc << this->fecha->mes << "/";
	stc << this->fecha->anio << endl;
	stc << "Numero de vuelo: " << this->numeroVuelo << endl;
	stc << "Asiento: " << this->asiento << endl;
	return stc.str();
}

