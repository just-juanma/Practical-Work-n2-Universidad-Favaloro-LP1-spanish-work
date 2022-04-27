#include "cAvion.h"
#include "cAeropuerto.h"

cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros,string _ID) {
	this->totalPasajeros = _totalPasajeros; 
	this->pesoMaximo = _pesoMaximo; 
	this->nPasajeros = _nPasajeros; 
	this->permiso = -1;
	this->ID = _ID; 
}

void cAvion::setListaPasajero(cListaPasajero* _pasajeros) {
	//this->nPasajeros = this->Listapasajeros->cantidad; // que me devuelva la cantidad de pasajeros agregados en la lista
	this->Listapasajeros = _pasajeros;
}

bool cAvion::chequearCargaMaxima() {
	int pesotot = this->nPasajeros * 75 + 4 * 75;
	if (pesotot < this->pesoMaximo) {
		return true; 
	}
	return false;

	//agregar lo que corresponde a valijas
}

void cAvion::pedirPermiso() {
	switch (this->estado)
	{
	case aterrizar: 
		int i = 0;
	case volando: 
		this->permiso = 0; 
		if (cAeropuerto::darPermiso() == true)
		{

			// buscar vuelo via ID -> obtener la pos del vuelo en la lista
			// listaVuelo[pos].estado = aterrizado;		cambio el estado en lista de vuelo del vuelo en la posicion del vuelo especifico.
			// fijarse si hay que agregar el avion al aeropuerto

		}
	default:
		break;
	}
}

void cAvion::despegar() {
	this->estado = volando;
}

void cAvion::aterrizar() {
	this->estado = aterrizado; 
}

string cAvion::getid() {
	return this->ID;
}

string cAvion::to_string() {
	stringstream stc;
	stc << "ID: " << this->ID << endl;
	stc << "Total pasajeros: " << this->totalPasajeros << endl;
	stc << "nPasajeros: " << this->nPasajeros << endl;
	stc << "estado: " << this->estado << endl;
	return stc.str();
	//this->Listapasajeros.imprimir();
}

void cAvion::imprimir() {
	cout << to_string();
}



