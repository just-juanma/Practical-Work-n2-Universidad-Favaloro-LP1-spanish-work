#include "cAeropuerto.h"
// implementation cAeropuerto 


unsigned int cAeropuerto::numeroAeropuerto = 0; // inicializo lo estatico
cAeropuerto::cAeropuerto(const unsigned int _ID, unsigned int _capacidadAeropuerto, unsigned int _nVuelos, unsigned int _nAviones, const string _nombre): ID(_ID), nombre(_nombre) {
	numeroAeropuerto++;
	capacidadAeropuerto = _capacidadAeropuerto;
}

cAeropuerto::~cAeropuerto() {
}

bool cAeropuerto::darPermiso(){
	//verifico que sea posible agregar un nuevo avion al aeropuerto sin sobrepasar su capacidad maxima, de no ser asi lanzo una excepcion
	try
	{
		//for(i=0;i<nvuelos;i++)
		// if vuelo[i].estado == aterrizado -> cont++)
		//cont >= capacidadAerop
		//lanzar la excepcion
		/*if ( = > capacidadAeropuerto)
			throw NO_HAY_LUGAR;*/
	}
	catch (const std::exception&)
	{

	}
	
}

string cAeropuerto::to_string() {
	stringstream stc;
	stc << "ID:" << ID << endl;
	stc << "Nombre:" << nombre << endl;
	stc << "Capacidad:" << capacidadAeropuerto << endl;
	stc << "Numero de aviones:" << listaAvionAeropuerto << endl;
	stc << "Vuelos disponibles:" << nVuelos << endl;
	stc << endl;
	return stc.str();
}

void cAeropuerto::imprimir()
{
	cout << to_string();
}
