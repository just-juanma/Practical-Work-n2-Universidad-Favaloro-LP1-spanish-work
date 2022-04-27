#include "cListaValija.h"

// implementacion cListaPasajero

cListaValija::cListaValija(sh size, bool _checkEliminar) {
	this->checkEliminar = _checkEliminar;
	// generacion de la lista dinamica
	this->listaValija = new cValija * [size];
	cValija::cantTotal = size;
	// por cada objeto que exista, apunto un nuevo puntero a NULL (para control de posibles errores)
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

bool cListaValija::agregar(cValija* valija) {
	if (cValija::cantActual >= cValija::cantTotal)
		return false;
	this->listaValija[cValija::cantActual] = valija;
	return true;
}

bool cListaValija::eliminar(cValija* valija) {
	for (ush i = 0; i < cValija::cantActual; i++)
		if (this->listaValija[i] && this->listaValija[i] == valija) {
			delete this->listaValija[i];
			this->listaValija[i] = NULL;
			ordenar();
			return true;
		}
	return false;
}

void cListaValija::ordenar() {
	for (ush i = 0; i < cValija::cantActual - 1; i++) {
		bool checkSwap = false;
		for (ush j = 0; j < cValija::cantActual - i - 1; j++) {
			swap(this->listaValija[j], this->listaValija[j + 1]);
			checkSwap = true;
		}
		if (!checkSwap)
			break;
	}
}

string cListaValija::to_string() const {
	stringstream stc;
	stc << "Checkeo de eliminar (true / si) (false / no)" << this->checkEliminar << endl;
	for (ush i = 0; i < cValija::cantActual; i++)
		stc << "Peso Valija [" << i << "]: " << this->listaValija[i]->peso << endl;
	return stc.str();
}


