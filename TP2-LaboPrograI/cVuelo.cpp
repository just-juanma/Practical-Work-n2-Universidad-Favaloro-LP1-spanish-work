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

