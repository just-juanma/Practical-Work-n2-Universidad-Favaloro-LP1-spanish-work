#include "cAeropuerto.h"

cAeropuerto::cAeropuerto(string _ID, unsigned int _capacidadAeropuerto, string _nombre) : ID(_ID), nombre(_nombre) {
	this->capacidadAeropuerto = _capacidadAeropuerto;
	this->listaVuelos = NULL;
	this->hangar = NULL;
}

cAeropuerto::~cAeropuerto() {
}

bool cAeropuerto::darPermiso(cAvion* avion) {
	//verifico que sea posible agregar un nuevo avion al aeropuerto sin sobrepasar su capacidad maxima, de no ser asi lanzo una excepcion
	sh i;
	try
	{
		if (cAvion::getnAviones() < capacidadAeropuerto)
		{
			try
			{
				for ( i = 0; i < cVuelo::numero; i++)
				{
					if (this->listaVuelos->listaVuelo[i]->avion->getid() == avion->getid())
					{
						this->listaVuelos->listaVuelo[i]->estado = aterrizado; break;
					}
				}
				if (i == cVuelo::numero); throw "AVION_NO_REGISTRADO";
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}

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

ush cAeropuerto::cantAterrizados(cFecha* fecha)
{
	ush cont = 0;
	for (ush i = 0; i < cVuelo::numero  ; i++)
	{
		if (listaVuelos->listaVuelo[i]->estado == eEstado::aterrizado &&
			listaVuelos->listaVuelo[i]->arribo->dia == fecha->dia &&
			listaVuelos->listaVuelo[i]->arribo->mes == fecha->mes)
			cont++;
	}
	return cont;
}

ush cAeropuerto::cantDespegados(cFecha* fecha)
{
	ush cont = 0;
	for (ush i = 0; i < cVuelo::numero; i++)
	{
		if (listaVuelos->listaVuelo[i]->estado == eEstado::volando &&
			listaVuelos->listaVuelo[i]->arribo->dia == fecha->dia &&
			listaVuelos->listaVuelo[i]->arribo->mes == fecha->mes)
			cont++;
	}
	return cont;
}

float porcentajeHorarioPartida()
{
	ush cont = 0;
	for(ush i=0; i < cVuelo::numero; i++)
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

