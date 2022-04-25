#include "cAvion.h"

cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros,string _ID) {
	this->totalPasajeros = _totalPasajeros; 
	this->pesoMaximo = _pesoMaximo; 
	this->nPasajeros = _nPasajeros; 

	this->ID = _ID; 
}

void cAvion::setListaPasajero(cListaPasajero* _pasajeros) {
	this->nPasajeros = this->Listapasajeros->cantidad; // que me devuelva la cantidad de pasajeros agregados en la lista
	this->Listapasajeros = _pasajeros;
}

bool cAvion::chequearCargaMaxima() {
	int pesotot = this->nPasajeros * 75 + 4 * 75;
	if (pesotot < this->pesoMaximo) {
		return true; 
	}
	return false;
}

void cAvion::pedirPermiso() {



}

