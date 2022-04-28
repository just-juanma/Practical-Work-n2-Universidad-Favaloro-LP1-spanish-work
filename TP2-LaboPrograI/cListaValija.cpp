#include "cListaValija.h"

// implementacion cListaPasajero

cListaValija::cListaValija(sh size, bool _checkEliminar) {
	// inicializacion de los atributos
	this->checkEliminar = _checkEliminar;
	try {
		this->listaValija = new cValija * [size];
	}
	catch (bad_alloc&) {
		cout << "Error: Fallo en la asignacion de memoria dinamica de la lista de valijas. El programa se termina";
		abort();
	}
	cValija::cantTotal = size;
	for (ush i = 0; i < cValija::cantActual; i++)
		this->listaValija[i] = NULL;
}

cListaValija::~cListaValija() {
	try {
		if (checkEliminar) {
			for (ush i = 0; i < cValija::cantTotal; i++)
				if (this->listaValija[i])
					delete listaValija[i];
			delete[] this->listaValija;
			cValija::cantTotal = 0;

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
		if (cValija::cantActual >= cValija::cantTotal)
			throw "Error: la cantidad actual de valijas supera a la total permitida";
		if (!listaValija[cValija::cantActual]) {
			this->listaValija[cValija::cantActual] = valija;
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


