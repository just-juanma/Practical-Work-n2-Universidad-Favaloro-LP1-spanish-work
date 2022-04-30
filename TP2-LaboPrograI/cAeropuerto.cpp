#include "cAeropuerto.h"

// implementacion cAeropuerto

cAeropuerto::cAeropuerto(string _ID, ush _capacidadAeropuerto, string _nombre) : ID(_ID), nombre(_nombre) {
	// inicializacion de los atributos
	this->capacidadAeropuerto = _capacidadAeropuerto;
	this->listaVuelos = NULL;
	this->listaAvionesAeropuerto = NULL;
}

cAeropuerto::~cAeropuerto() {

}

bool cAeropuerto::darPermiso(cAvion* avion) {
	//verifico que sea posible agregar un nuevo avion al aeropuerto sin sobrepasar su capacidad maxima, de no ser asi lanzo una excepcion
	sh i=0;
	try
	{
		if (avion == NULL) throw "AVION_NULL";
		if (this->CantAvionesAeropuerto() < capacidadAeropuerto)
		{
			try
			{
				for ( i = 0; i< cVuelo::numero;i++)
				{
					string intento = this->listaVuelos->listaVuelo[i]->avion->getid();
					if ( intento == avion->getid())
					{
						this->listaVuelos->listaVuelo[i]->estado = aterrizado; 
						this->listaAvionesAeropuerto->Agregar(avion);
						break;
					}
				}
				if (i > cVuelo::numero) throw "ERROR_AVION_SIN_VUELO";
			}
			catch (const char* msg)
			{
				cout << msg << endl;
				return false;
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

ush cAeropuerto::CantAvionesAeropuerto() {
	ush cont = 0;
	for (ush i = 0; i < cAvion::getnAviones(); i++)
	{
		if (listaAvionesAeropuerto[0][i]->getestado() == eEstado::aterrizado)
			cont++;
	}
	return cont;
}

ush cAeropuerto::cantAterrizadosDia(cFecha* fecha)
{	
	try
	{
		if (fecha == NULL) throw "FECHA_NULL";
		ush cont = 0;
		for (ush i = 0; i < cVuelo::numero; i++)
		{
			if (listaVuelos->listaVuelo[i]->estado == eEstado::aterrizado &&
				listaVuelos->listaVuelo[i]->arribo->dia == fecha->dia &&
				listaVuelos->listaVuelo[i]->arribo->mes == fecha->mes)
				cont++;
		}
		return cont;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return 0;
	}
	
}

ush cAeropuerto::cantDespegados(cFecha* fecha)
{
	try
	{
		if (fecha == NULL) throw "FECHA_NULL";
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
	catch (const char* msg)
	{
		cout << msg << endl;
		return 0;
	}
}

//float porcentajeHorarioPartida()
//{
//	ush cont = 0;
//	for(ush i=0; i < cVuelo::numero; i++)
//}

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

