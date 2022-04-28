#include "cAvion.h"
#include "cAeropuerto.h"

#pragma region Constructor y destructor + variables estaticas
cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros,string _ID) {
	this->totalPasajeros = _totalPasajeros; 
	this->pesoMaximo = _pesoMaximo; 
	this->nPasajeros = _nPasajeros; // remplazar por 0, ya que no hay nadie en el avion caundo se termine de construir este
	this->permiso = -1;
	this->ID = _ID; 
	nAviones++;
}


cAvion::~cAvion() {
	nAviones--;
}

int cAvion::nAviones = 0;
#pragma endregion


#pragma region funcionalidad propia de la clase
bool cAvion::chequearCargaMaxima() {
	try {
		float pesotot = (float)this->nPasajeros * 75 + (float)(4 * 75);
		for (int i = 0; i < this->nPasajeros; i++) {
			pesotot += this->Listapasajeros[0][i]->getPesoTotalEquipaje();
		}
		if (pesotot < this->pesoMaximo) {
			return true;
		}
		else {
			throw "Peso mayo al debido";
		}
		
	}
	catch (const char* msg) {
		cout << msg << endl;

	}
	

}

eEstado cAvion::pedirPermiso() {
	return this->estado;
}

void cAvion::recibirPermiso(cAvion* avion) { //cambiar los dos 10 por el numero de aviones en aeropuerto
	sh i, j;
	avion->estado = aterrizado;
	try
	{
		for (i = 0; i < cVuelo::numero; i++)
		{
			if (cAeropuerto::listaVuelos->listaVuelo[i]->avion->getid() == this->ID)
			{
				cAeropuerto::listaVuelos->listaVuelo[i]->estado = aterrizado; break;
			}		
		}
		if (i == 10); throw "AVION_NO_REGISTRADO";
	}catch (const char* msg)
	{
		cout << msg << endl;
	}
	
	//vuelo.setavion(avion)
	//vuelo.setestado();
}

void cAvion::despegar() {
	this->pedirPermiso(); //ver finalmente como es el tema de cambiar el estado quiza es reiterativo 
	this->estado = volando;
}

void cAvion::aterrizar() {
	this->estado = aterrizado; //ver si llamo a la funcion pedirPermiso()
}

#pragma endregion

#pragma region setters
void cAvion::setListaPasajero(cListaPasajero* _pasajeros, int _nPasajeros) {
	//this->nPasajeros = this->Listapasajeros->cantidad; // que me devuelva la cantidad de pasajeros agregados en la lista
	this->Listapasajeros = _pasajeros;
	this->nPasajeros = _nPasajeros;
}

void cAvion::setestado(eEstado _estado) {
	this->estado = _estado;
}

#pragma endregion

#pragma region getters
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
#pragma endregion

string cAvion::to_string() {
	stringstream stc;
	stc << "ID: " << this->ID << endl;
	stc << "Total pasajeros: " << this->totalPasajeros << endl;
	stc << "nPasajeros: " << this->nPasajeros << endl;
	stc << "estado: " << this->estado << endl;
	return stc.str();
	for (int i = 0; i < this->nPasajeros; i++) {
		this->Listapasajeros[0][i]->imprimir();
	}
	
}



void cAvion::imprimir() {
	cout << to_string();
}



