#include "cAvion.h"

// implementacion cAvion

// inicializacion atributos estaticos
int cAvion::nAviones = 0;

#pragma region Constructor y destructor + variables estaticas
cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros,string _ID): ID(_ID) {
	// inicializacion de los atributos
	this->totalPasajeros = _totalPasajeros; 
	this->pesoMaximo = _pesoMaximo; 
	this->nPasajeros = _nPasajeros; // remplazar por 0, ya que no hay nadie en el avion caundo se termine de construir este
	this->permiso = -1;
	this->Listapasajeros = NULL;
	nAviones++;
}


cAvion::~cAvion() {

	nAviones--;
}


#pragma endregion


#pragma region funcionalidad propia de la clase


void cAvion::recibirPermiso(cFecha* llegada,cFecha* partida) { //cambiar los dos 10 por el numero de aviones en aeropuerto
	try {
		if (llegada != NULL && partida != NULL) {
			this->chequearCargaMaxima();
			this->setfecha(llegada, partida);
			this->despegar();
		}
		else {
			throw "ERROR: Ingrese fechas del vuelo";
		}
	}
	catch(const char* msg) {
		cout << msg << endl;
	}
	
}

bool cAvion::chequearCargaMaxima() {
	try {
		if (this->Listapasajeros != NULL) {

			float pesotot = (float)this->nPasajeros * 75 + (float)(4 * 75);
			for (ush i = 0; i < this->nPasajeros; i++) {
				pesotot += this->Listapasajeros[0][i]->getPesoTotalEquipaje();
			}
			if (pesotot < this->pesoMaximo) {
				return true;
			}
			else {
				throw "Peso mayo al debido";
			}
			return false;
		}
		else {
			throw "ERROR: LISTA DE PASAJEROS NULA,HACER QUE LOS PASAJEROS ABORDEN";
		}
	}
	catch (const char* msg) {
		cout << msg << endl;
		return false;
	}
}

eEstado cAvion::pedirPermiso() { //Debido a que el "pedir permiso" se ejecuta "automaticamente" en el main 
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
	if (_pasajeros ==NULL) {
		throw "La lista de pasajeros es nula";
	}
	else {
		this->Listapasajeros = _pasajeros;
	}
	if (_nPasajeros <= this->totalPasajeros) {
		this->nPasajeros = _nPasajeros;
	}
	else {
		throw "Se solicita asignar una cantidad de pasajeros mayor a la permitida";
	}
}

void cAvion::setestado(eEstado _estado) {
	this->estado = _estado;
}

void cAvion::setfecha(cFecha* _llegada, cFecha* _partida) {
	this->partida = _partida;
	this->llegada = _llegada;
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
	for (ush i = 0; i < this->nPasajeros; i++) {
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



