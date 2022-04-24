#include "cListaValija.h"

// implementacion cListaPasajero

cListaValija::cListaValija(sh size, bool _checkEliminar) {
	this->checkEliminar = _checkEliminar;
	this->listaValija = new cValija * [size];
	cValija::cantTotal = size;
	
	for (ush i = 0; i < cValija::cantActual; i++)
		this->listaValija[i] = NULL;
}

cListaValija::~cListaValija() {
	if (checkEliminar)
		for (ush i = 0; i < cValija::cantTotal; i++)
			if (this->listaValija[i])
				delete listaValija[i];
	delete[] this->listaValija;
	cValija::cantTotal;
}

bool cListaValija::agregar(cValija* pasajero) {
	if (cValija::cantActual >= cValija::cantTotal)
		return false;
	this->listaValija[cValija::cantActual] = pasajero;
	return true;
}

bool cListaValija::eliminar(sh pos) {
	if (pos >= 0 && this->listaValija[pos]) {
		delete this->listaValija[pos];
		this->listaValija[pos] = NULL;
		ordenar();
		return true;
	}
	return false;
}

void cListaValija::ordenar() {
	for (ush i = 0; i < cValija::cantActual - 1; i++) {
		bool checkSwap = false;
		for (ush j = 0; j < cValija::cantActual - i - 1; j++) {
			swap(listaValija[j], listaValija[j + 1]);
			checkSwap = true;
		}
		if (!checkSwap)
			break;
	}
}




