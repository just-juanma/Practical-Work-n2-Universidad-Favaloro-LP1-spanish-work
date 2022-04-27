#include "cListaPasajero.h"

// implementacion cListaPasajero

cListaPasajero::cListaPasajero(sh size, bool _checkEliminar) {
	this->checkEliminar = _checkEliminar;
	this->listaPasajero = new cPasajero * [size];
	cPasajero::cantTotal = size;
	for (ush i = 0; i < cPasajero::cantActual; i++)
		this->listaPasajero[i] = NULL;
}

cListaPasajero::~cListaPasajero() {
	if (checkEliminar)
		for (ush i = 0; i < cPasajero::cantTotal; i++)
			if (this->listaPasajero[i])
				delete listaPasajero[i];
	delete[] this->listaPasajero;
	cPasajero::cantTotal;
}

bool cListaPasajero::agregar(cPasajero* pasajero) {
	if (cPasajero::cantActual >= cPasajero::cantTotal)
		return false;
	if (!listaPasajero[cPasajero::cantActual]) {
		this->listaPasajero[cPasajero::cantActual] = pasajero;
		return true;
	}
	return false;
}

bool cListaPasajero::modificar(sh pos, cPasajero* nuevoPasajero) {
	if (pos >= 0 && this->listaPasajero[pos] && pos < cPasajero::cantActual) {
		cPasajero* aux = this->listaPasajero[pos];
		this->listaPasajero[pos] = nuevoPasajero;
		delete aux;
		return true;
	}
	return false;
}

bool cListaPasajero::eliminar(sh pos) {
	if (pos >= 0 && this->listaPasajero[pos] && pos < cPasajero::cantActual) {
		delete this->listaPasajero[pos];
		this->listaPasajero[pos] = NULL;
		ordenar();
		return true;
	}
	return false;
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

string cListaPasajero::to_string() {
	stringstream stc;
	stc << "Checkeo de eliminar (true / si) (false / no): " << checkEliminar << endl;
	for (ush i = 0; i < cPasajero::cantActual; i++)
		if(listaPasajero[i])
			stc << "DNI pasajero [" << i << "]: " << listaPasajero[i]->nombre << endl;
	return stc.str();
}


