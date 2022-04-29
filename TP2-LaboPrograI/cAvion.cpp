#include "cAvion.h"

// implementacion cAvion

// inicializacion atributos estaticos
int cAvion::nAviones = 0;

#pragma region Constructor y destructor + variables estaticas
cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros,string _ID) {
	// inicializacion de los atributos
	this->totalPasajeros = _totalPasajeros; 
	this->pesoMaximo = _pesoMaximo; 
	this->nPasajeros = _nPasajeros; // remplazar por 0, ya que no hay nadie en el avion caundo se termine de construir este
	this->permiso = -1;
	this->ID = _ID; 
	this->Listapasajeros = NULL;
	nAviones++;
}


cAvion::~cAvion() {

	nAviones--;
}


#pragma endregion


#pragma region funcionalidad propia de la clase


void cAvion::recibirPermiso(cFecha* fecha) { //cambiar los dos 10 por el numero de aviones en aeropuerto
	this->chequearCargaMaxima();
	this->setfecha(fecha);
	this->despegar();
}

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

eEstado cAvion::pedirPermiso() { //Debido a que el "pedir permiso" se ejecuta "automaticamente" en el main 
								 //
	return this->estado;
}


void cAvion::despegar() {
	//this->pedirPermiso(); //ver finalmente como es el tema de cambiar el estado quiza es reiterativo 
	this->estado = volando;
}

void cAvion::aterrizar() {
	this->estado = aterrizado; 
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

void cAvion::setfecha(cFecha* _fecha) {
	this->partida = _fecha;
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

cFecha* cAvion::getfecha() {
	return this->partida;
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

ush cAvion::getnAviones()
{
	return nAviones;
}

void cAvion::imprimir() {
	cout << to_string();
}



