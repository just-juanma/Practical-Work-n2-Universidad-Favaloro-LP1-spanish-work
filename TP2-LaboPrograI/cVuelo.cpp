#include "gbl.h"
#include "cVuelo.h"
#include "cPasajero.h"

// implementacion cVuelo

// inicializacion atributos estaticos
ush cVuelo::numero = 0;
sh cVuelo::cantTotal = 0;

cVuelo::cVuelo(bool _PoA, eEstado _estado, ePosiblesDestinos _ciudad) {
	// inicializacion de los atributos
	// por cada obj. generado, aumento su capacidad actual
	numero++;
	this->PoA = _PoA;
	this->estado = _estado;
	this->ciudad = _ciudad;
	this->vuelo = NULL; 
	this->destino = NULL;
}

cVuelo::~cVuelo() {
	// por cada obj. destruido, disminuyo su capacidad actual
	numero--;
}

string cVuelo::to_string()const {
	stringstream stc;
	stc << "Cantidad de vuelos: " << numero << endl;
	stc << "Estado del vuelo: " << this->estado << endl;
	stc << "Partida (true) o arribo (false): " << this->PoA << endl;
	stc << "Fecha y hora del vuelo: " << this->vuelo << endl;
	stc << "Fecha y hora del destino: " << this->destino << endl;
	return stc.str();
}