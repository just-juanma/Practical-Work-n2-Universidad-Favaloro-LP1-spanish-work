#include "gbl.h"
#include "cVuelo.h"
#include "cPasajero.h"

// implementacion cVuelo

ush cVuelo::numero = 0;

cVuelo::cVuelo(bool _PoA, eEstado _estado) {
	numero++;
	this->PoA = _PoA;
	this->estado = _estado;
	this->vuelo = NULL;
	this->destino = NULL;
}

cVuelo::~cVuelo() {
	numero--;
}

string cVuelo::to_string() {
	stringstream stc;
	stc << "Cantidad de vuelos: " << numero << endl;
	stc << "Estado del vuelo: " << this->estado << endl;
	stc << "Partida (true) o arribo (false): " << this->PoA << endl;
	stc << "Fecha y hora del vuelo: " << this->vuelo << endl;
	stc << "Fecha y hora del destino: " << this->destino << endl;
	return stc.str();
}