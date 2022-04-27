#include "cListaVuelo.h"

// implementacion cListaVuelo

cListaVuelo::cListaVuelo(sh size, bool _checkEliminar) {
	this->checkEliminar = _checkEliminar;
	this->listaVuelo = new cVuelo * [size];
	cVuelo::cantTotal = size;
	for (ush i = 0; i < cVuelo::numero; i++)
		this->listaVuelo[i] = NULL;
}

cListaVuelo::~cListaVuelo() {
	if (checkEliminar)
		for (ush i = 0; i < cVuelo::cantTotal; i++)
			if (this->listaVuelo[i])
				delete listaVuelo[i];
	delete[] this->listaVuelo;
	cVuelo::cantTotal;
}

bool cListaVuelo::agregar(cVuelo* vuelo) {
	if (cVuelo::numero >= cVuelo::cantTotal)
		return false;
	this->listaVuelo[cVuelo::numero] = vuelo;
	return true;
}

bool cListaVuelo::eliminar(sh pos) {
	if (pos >= 0 && this->listaVuelo[pos]) {
		delete this->listaVuelo[pos];
		this->listaVuelo[pos] = NULL;
		ordenar();
		return true;
	}
	return false;
}

void cListaVuelo::ordenar() {
	for (ush i = 0; i < cVuelo::numero - 1; i++) {
		bool checkSwap = false;
		for (ush j = 0; j < cVuelo::numero - i - 1; j++) {
			swap(this->listaVuelo[j], this->listaVuelo[j + 1]);
			checkSwap = true;
		}
		if (!checkSwap)
			break;
	}
}
string cListaVuelo::to_string() {
	stringstream stc;
	stc << "Checkeo de eliminar (true / si) (false / no): " << checkEliminar << endl;
	stc << "Referencia de ciudades: (0) sin destino, (1) Jerusalen, (2) Beerseva, (3) Eilat" << endl;
	for (ush i = 0; i < cVuelo::numero; i++)
		if(listaVuelo[i])
			stc << "Ciudad destino del vuelo [" << i << "]: " << listaVuelo[i]->ciudad << endl;
	return stc.str();
}


