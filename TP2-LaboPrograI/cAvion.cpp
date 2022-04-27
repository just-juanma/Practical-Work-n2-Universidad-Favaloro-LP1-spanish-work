#include "cAvion.h"
#include "cAeropuerto.h"

cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros,string _ID) {
	this->totalPasajeros = _totalPasajeros; 
	this->pesoMaximo = _pesoMaximo; 
	this->nPasajeros = _nPasajeros; // remplazar por 0, ya que no hay nadie en el avion caundo se termine de construir este
	this->permiso = -1;
	this->ID = _ID; 
}

void cAvion::setListaPasajero(cListaPasajero* _pasajeros,int _nPasajeros) {
	//this->nPasajeros = this->Listapasajeros->cantidad; // que me devuelva la cantidad de pasajeros agregados en la lista
	this->Listapasajeros = _pasajeros;
	this->nPasajeros = _nPasajeros;
}

bool cAvion::chequearCargaMaxima() {
	float pesotot = (float)this->nPasajeros * 75 +(float)(4 * 75);
	for (int i = 0; i < this->nPasajeros; i++) {
		pesotot += this->Listapasajeros[0][i]->getPesoTotalEquipaje();
	}
	if (pesotot < this->pesoMaximo) {
		return true; 
	}
	return false;

}

void cAvion::pedirPermiso() {
	switch (this->estado)
	{
		case aterrizado: 
			cAeropuerto::darPermiso();	
			this->estado = volando;
		case volando: 
			this->permiso = 0; 
			this->recibirPermiso(); //veo que recibo o como
	default:
		break;
	}
}

void cAvion::recibirPermiso() {
	//if (cAeropuerto::darPermiso() == true){
	//		//cAeropuerto::numgetVuelo() 
	//		// buscar vuelo via ID -> obtener la pos del vuelo en la lista
	//		// listaVuelo[pos].estado = aterrizado;		cambio el estado en lista de vuelo del vuelo en la posicion del vuelo especifico.
	//		// fijarse si hay que agregar el avion al aeropuerto
	//} //cambiar esta parte por una funcion recibir permiso
}

void cAvion::despegar() {
	this->pedirPermiso();
	this->estado = volando;
}

void cAvion::aterrizar() {
	this->estado = aterrizado; 
}

int cAvion::getcantpasajeros() {
	return this->nPasajeros;
}

cListaPasajero* cAvion::getListaPasajero() {
	return this->Listapasajeros;
}

eEstado cAvion::getestado() {
	return this->estado;
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



