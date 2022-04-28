#include "gbl.h"
#include "cPasajero.h"

// implementacion cPasajero
ush cPasajero::cantActual = 0;
sh cPasajero::cantTotal = 0;
cPasajero::cPasajero(string _nombre, string _DNI, sh _numeroVuelo, sh _asiento) : nombre(_nombre), DNI(_DNI) {
	cantActual++;
	this->numeroVuelo = _numeroVuelo;
	this->asiento = _asiento;
	this->pesoTotalEquipaje = NULL;
	this->equipaje = NULL;
	this->fecha = NULL;
}

cPasajero::~cPasajero() {
	cantActual--;
}

string cPasajero::to_string()const {
	stringstream stc;
	stc << "Nombre: " << this->nombre << endl;
	stc << "DNI: " << this->DNI << endl;
	stc << "Fecha: ";
	stc << this->fecha->dia << "/";
	stc << this->fecha->mes << "/";
	stc << this->fecha->anio << endl;
	stc << "Hora: " << this->fecha->hora << endl;
	stc << "Numero de vuelo: " << this->numeroVuelo << endl;
	stc << "Asiento: " << this->asiento << endl;
	return stc.str();
}

