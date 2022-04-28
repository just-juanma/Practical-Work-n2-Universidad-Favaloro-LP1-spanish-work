#include "cAeropuerto.h"

cAeropuerto::cAeropuerto(const unsigned int _ID, unsigned int _capacidadAeropuerto, const string _nombre, cListaVuelo* listaVuelos, cListaAvion* hangar) : ID(_ID), nombre(_nombre) {
	capacidadAeropuerto = _capacidadAeropuerto;
	listaVuelos = NULL;
	hangar = NULL;
}

cAeropuerto::~cAeropuerto() {
}

bool cAeropuerto::darPermiso() {
	//verifico que sea posible agregar un nuevo avion al aeropuerto sin sobrepasar su capacidad maxima, de no ser asi lanzo una excepcion
	try
	{
		if (cAvion::getnAviones() < capacidadAeropuerto)
		{
			return true;
		}
		else throw "ERROR: HANGAR_CAPACIDAD_LLENA";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return false;
	}
	
}

string cAeropuerto::to_string() {
	stringstream stc;
	stc << "ID:" << ID << endl;
	stc << "Nombre:" << nombre << endl;
	stc << "Capacidad:" << capacidadAeropuerto << endl;
	stc << "Numero de aviones:" <<  cAvion::getnAviones << endl;
	stc << "Vuelos disponibles:" << cVuelo::numero << endl;
	stc << endl;
	return stc.str();
}

void cAeropuerto::imprimir()
{
	cout << to_string();
}
