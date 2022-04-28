#include "cListaPasajero.h"

// implementacion cListaPasajero

cListaPasajero::cListaPasajero(sh size, bool _checkEliminar) {
	// inicializacion de los atributos
	this->checkEliminar = _checkEliminar;
	try {
		this->listaPasajero = new cPasajero * [size];
	}
	catch (bad_alloc&) {
		cout << "Error: Fallo en la asignacion de memoria dinamica de la lista de pasajeros. El programa se termina";
		abort();
	}
	cPasajero::cantTotal = size;
	for (ush i = 0; i < cPasajero::cantActual; i++)
		this->listaPasajero[i] = NULL;
}

cListaPasajero::~cListaPasajero() {
	try {
		if (checkEliminar) {
			for (ush i = 0; i < cPasajero::cantTotal; i++)
				if (this->listaPasajero[i])
					delete listaPasajero[i];
			delete[] this->listaPasajero;
			cPasajero::cantTotal = 0;
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
		if (cPasajero::cantActual >= cPasajero::cantTotal)
			throw "Error: la cantidad actual de pasajeros supera a la total permitida";
		if (!listaPasajero[cPasajero::cantActual]) {
			this->listaPasajero[cPasajero::cantActual] = pasajero;
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
		if (pos >= 0 && pos < cPasajero::cantActual && this->listaPasajero[pos]) {
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
		if (pos >= 0 && this->listaPasajero[pos] && pos < cPasajero::cantActual) {
			delete this->listaPasajero[pos];
			this->listaPasajero[pos] = NULL;
			ordenar();
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
	for (ush i = 0; i < cPasajero::cantActual - 1; i++) {
		bool checkSwap = false;
		for (ush j = 0; j < cPasajero::cantActual - i - 1; j++) {
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
	for (ush i = 0; i < cPasajero::cantActual; i++)
		if(listaPasajero[i])
			stc << "DNI pasajero [" << i << "]: " << listaPasajero[i]->nombre << endl;
	return stc.str();
}


