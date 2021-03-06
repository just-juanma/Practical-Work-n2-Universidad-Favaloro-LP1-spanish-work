#include "cListaPasajero.h"

// implementacion cListaPasajero

cListaPasajero::cListaPasajero(sh size, bool _checkEliminar) {
	// inicializacion de los atributos
	this->cantActual = 0;
	this->checkEliminar = _checkEliminar;
	try {
		this->listaPasajero = new cPasajero * [size];
	}
	catch (bad_alloc&) {
		cout << "Error: Fallo en la asignacion de memoria dinamica de la lista de pasajeros. El programa se termina";
		abort();
	}
	this->cantTotal = size;
	if (this->listaPasajero) 
		for (ush i = 0; i < this->cantTotal; i++)
			this->listaPasajero[i] = NULL;
	
}

cListaPasajero::~cListaPasajero() {
	try {
		if (this->checkEliminar) {
			for (ush i = 0; i < this->cantActual; i++)
				if (this->listaPasajero[i])
					delete this->listaPasajero[i];
			delete[] this->listaPasajero;
		}
		else
			throw "Error: No se puede destruir el objeto de la lista de pasajero si no se le da el permiso para eliminarlo. El programa se termina";
	}
	catch (const char* msg) {
		cout << msg << endl;
		abort();
	}
}

bool cListaPasajero::agregar(cPasajero* pasajero) {
	try {
		if (this->cantActual > this->cantTotal)
			throw "Error: la cantidad actual de pasajeros supera a la total permitida";
		else if (!isValidDNI(pasajero->DNI))
			throw "Error: ese DNI ya esta registrado";
		else if (!isValidAsiento(pasajero->asiento))
			throw "Error: ese asiento ya esta ocupado";
		else if (!pasajero)
			throw "Error: no existe el pasajero ingresado";
		if (!listaPasajero[this->cantActual]) {
			this->listaPasajero[this->cantActual++] = pasajero;
			return true;
		}
		else
			throw "Error: Ya existe un pasajero en la posicion donde se lo esta intentando agregar de la lista";
	}
	catch (const char* msg) {
		cout << msg << endl;
		return false;
	}
}

bool cListaPasajero::modificar(sh pos, cPasajero* nuevoPasajero) {
	try {
		if (pos >= 0 && pos < this->cantActual &&			// posicion valida?
			this->listaPasajero[pos] && nuevoPasajero) {	// pasajero valido?
			cPasajero* aux = this->listaPasajero[pos];
			this->listaPasajero[pos] = nuevoPasajero;
			delete aux;
			return true;
		}
		else
			throw "Error: No se puede modificar una posicion que no existe en la lista de pasajero";
	}
	catch (const char* msg) {
		cout << msg << endl;
		return false;
	}
}

bool cListaPasajero::eliminar(sh pos) {
	try {
		if (pos >= 0 && this->listaPasajero[pos] && pos < this->cantActual) {
			delete this->listaPasajero[pos];
			this->listaPasajero[pos] = NULL;
			ordenar();
			this->cantActual--;
			return true;
		} else
			throw "Error: No se puede eliminar una posicion que no existe en la lista de pasajero";
	}
	catch (const char* msg) {
		cout << msg << endl;
		return false;
	}
}

void cListaPasajero::ordenar() {
	for (ush i = 0; i < this->cantActual; i++)
		for (ush j = i; j < this->cantActual - 1; j++)
			if (!this->listaPasajero[i])
				swap(this->listaPasajero[j], this->listaPasajero[j + 1]);
}

string cListaPasajero::to_string()const {
	stringstream stc;
	stc << "Checkeo de eliminar (true / si) (false / no): " << this->checkEliminar << endl;
	for (ush i = 0; i < this->cantActual; i++)
		if(this->listaPasajero[i])
			stc << "DNI pasajero [" << i << "]: " << this->listaPasajero[i]->nombre << endl;
	return stc.str();
}

bool cListaPasajero::isValidDNI(string DNI) {
	for (ush i = 0; i < this->cantActual; i++) {
		if (DNI == this->listaPasajero[i]->DNI)
			return false;
	}
	return true;
}

bool cListaPasajero::isValidAsiento(sh num) {
	for (ush i = 0; i < this->cantActual; i++) {
		if (num == this->listaPasajero[i]->asiento)
			return false;
	}
	return true;
}