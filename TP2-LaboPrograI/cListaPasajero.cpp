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
	for (ush i = 0; i < this->cantTotal; i++)
		this->listaPasajero[i] = NULL;
}

cListaPasajero::~cListaPasajero() {
	try {
		if (checkEliminar) {
			for (ush i = 0; i < this->cantActual; i++)
				if (this->listaPasajero[i])
					delete listaPasajero[i];
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
		if (!listaPasajero[this->cantActual]) {
			this->listaPasajero[this->cantActual] = pasajero;
			cantActual++;
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
		if (pos >= 0 && pos < this->cantActual && this->listaPasajero[pos]) {
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
			cantActual--;
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
	for (ush i = 0; i < this->cantActual - 1; i++) {
		bool checkSwap = false;
		for (ush j = 0; j < this->cantActual - i - 1; j++) {
			swap(this->listaPasajero[j], this->listaPasajero[j + 1]);
			checkSwap = true;
		}
		if (!checkSwap)
			break;
	}
}

string cListaPasajero::to_string()const {
	stringstream stc;
	stc << "Checkeo de eliminar (true / si) (false / no): " << checkEliminar << endl;
	for (ush i = 0; i < this->cantActual; i++)
		if(listaPasajero[i])
			stc << "DNI pasajero [" << i << "]: " << listaPasajero[i]->nombre << endl;
	return stc.str();
}

bool cListaPasajero::isValidDNI(string DNI) {
	for (ush i = 0; i < this->cantActual; i++) {
		if (DNI == listaPasajero[i]->DNI)
			return false;
	}
	return true;
}

bool cListaPasajero::isValidAsiento(sh num) {
	for (ush i = 0; i < this->cantActual; i++) {
		if (num == listaPasajero[i]->asiento)
			return false;
	}
	return true;
}