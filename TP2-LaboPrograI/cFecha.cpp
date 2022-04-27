
#include "gbl.h"
#include "cFecha.h"

// implementacion cFecha

cFecha::cFecha(sh _dia, sh _mes, sh _anio, sh _hora) {
	this->dia = _dia;
	this->mes = _mes;
	this->anio = _anio;
	this->hora = _hora;
}

cFecha::~cFecha() {
	// no tengo nada que eliminar
}