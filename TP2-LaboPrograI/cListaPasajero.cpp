#include "cListaPasajero.h"

// implementacion cListaPasajero

cListaPasajero::cListaPasajero(ush size, bool _checkEliminar) {
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
	this->listaPasajero[cPasajero::cantActual] = pasajero;
	return true;
}

bool cListaPasajero::modificar(short pos, cPasajero* nuevoPasajero) {
	for (ush i = 0; i < cPasajero::cantActual; i++) {
		if (pos >= 0 && this->listaPasajero[pos]) {
			cPasajero* aux = this->listaPasajero[pos];
			this->listaPasajero[i] = nuevoPasajero;
			delete aux;
			return true;
		}
	}
	return false;
}

bool cListaPasajero::eliminar(short pos) {
	if (pos >= 0 && this->listaPasajero[pos]) {
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
			swap(listaPasajero[j], listaPasajero[j + 1]);
			checkSwap = true;
		}
		if (!checkSwap)
			break;
	}
}



