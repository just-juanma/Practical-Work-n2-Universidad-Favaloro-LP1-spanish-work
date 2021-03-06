#include "cListaValija.h"

// implementacion cListaPasajero

cListaValija::cListaValija(sh size, bool _checkEliminar) {
	// inicializacion de los atributos
	this->checkEliminar = _checkEliminar;
	this->cantActual = 0;
	try {
		this->listaValija = new cValija * [size];
	}
	catch (bad_alloc&) {
		cout << "Error: Fallo en la asignacion de memoria dinamica de la lista de valijas. El programa se termina";
		abort();
	}
	this->cantTotal = size;
	if (listaValija) 
		for (ush i = 0; i < this->cantTotal; i++)
			this->listaValija[i] = NULL;
}

cListaValija::~cListaValija() {
	try {
		if (checkEliminar) {
			for (ush i = 0; i < this->cantActual; i++)
				if (this->listaValija[i])
					delete listaValija[i];
			delete[] this->listaValija;
		}
		else
			throw "Error: No se puede destruir el objeto de la lista de valijas si no se le da el permiso para eliminarlo. El programa se termina";
	}
	catch (const char* msg) {
		cout << msg << endl;
		abort();
	}
}

bool cListaValija::agregar(cValija* valija) {
	try {
		if (this->cantActual > this->cantTotal)
			throw "Error: la cantidad actual de valijas supera a la total permitida";
		else if (!valija)
			throw "Error: la valija ingresada no existe";
		else if (!this->listaValija[this->cantActual]) {
			this->listaValija[this->cantActual++] = valija;
			return true;
		}
		else
			throw "Error: Ya existe una valija en la posicion donde se lo esta intentando agregar de la lista";
	}
	catch (const char* msg) {
		cout << msg << endl;
		return false;
	}
}

bool cListaValija::eliminar(cValija* valija) {
	if (valija) 
		for (ush i = 0; i < this->cantActual; i++)
			if (this->listaValija[i] && this->listaValija[i] == valija) {
				delete this->listaValija[i];
				this->listaValija[i] = NULL;
				ordenar();
				this->cantActual--;
				return true;
			}
	return false;
}

void cListaValija::ordenar() {
	for (ush i = 0; i < this->cantActual; i++) 
		for (ush j = i; j < this->cantActual - 1; j++) 
			if (!this->listaValija[i]) 
				swap(this->listaValija[j], this->listaValija[j + 1]);		
}

string cListaValija::to_string() const {
	stringstream stc;
	stc << "Checkeo de eliminar la lista (1 / si) (0 / no): " << this->checkEliminar << endl;
	for (ush i = 0; i < this->cantActual; i++)
		stc << "Peso Valija [" << i << "]: " << this->listaValija[i]->peso << endl;
	return stc.str();
}


