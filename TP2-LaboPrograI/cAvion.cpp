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

eEstado cAvion::pedirPermiso() {
	return this->estado;
}

void cAvion::recibirPermiso(cAvion* avion) {
	sh i, j;
	avion->estado = aterrizado;
	try
	{
		for (i = 0; i < cVuelo::numero; i++)
		{
			if (cAeropuerto::listaVuelos->listaVuelo[i]->avion->getid() == avion->ID)
			{
				cAeropuerto::listaVuelos->listaVuelo[i]->estado = aterrizado; break;
			}		
		}
		if (i == 10); throw "AVION_NO_REGISTRADO";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	
	//vuelo.setavion(avion)
	//vuelo.setestado();
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



