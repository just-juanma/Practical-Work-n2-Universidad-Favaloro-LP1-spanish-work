#include "gbl.h"
#include "cPasajero.h"

// implementacion cPasajero

cPasajero::cPasajero(string _nombre, string _DNI, sh _numeroVuelo, sh _asiento) : nombre(_nombre), DNI(_DNI) {
	this->numeroVuelo = _numeroVuelo;
	this->asiento = _asiento;
	this->equipaje = NULL;
	this->fecha = NULL;
}

cPasajero::~cPasajero() {
	// no tengo algo que eliminar
}

string cPasajero::to_string()const {
	stringstream stc;
	stc << "Nombre: " << this->nombre << endl;
	stc << "DNI: " << this->DNI << endl;
	stc << "Fecha: ";
	if (fecha) {
		stc << this->fecha->dia << "/";
		stc << this->fecha->mes << "/";
		stc << this->fecha->anio << endl;
		stc << "Hora: " << this->fecha->hora << endl;
	}
	stc << "Numero de vuelo: " << this->numeroVuelo << endl;
	stc << "Asiento: " << this->asiento << endl;
	stc << "Equipaje del pasajero: " << endl;
	stc << this->equipaje->to_string();
	stc << endl;
	return stc.str();
}

