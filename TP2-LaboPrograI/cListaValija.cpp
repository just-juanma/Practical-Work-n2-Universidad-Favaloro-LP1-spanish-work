#include "cListaValija.h"

// implementacion cListaPasajero

cListaValija::cListaValija(sh size, bool _checkEliminar) {
	// inicializacion de los atributos
	this->checkEliminar = _checkEliminar;
	try {
		this->listaValija = new cValija * [size];
		this->capacidad = size;
		this->ocupados = 0;
	}
	catch (bad_alloc&) {
		cout << "Error: Fallo en la asignacion de memoria dinamica de la lista de valijas. El programa se termina";
		abort();
	}
	for (ush i = 0; i < size; i++)
		this->listaValija[i] = NULL;
}

cListaValija::~cListaValija() {
	try {
		if (checkEliminar) {
			for (ush i = 0; i < this->ocupados; i++)
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
		if (this->ocupados <= this->capacidad)
			throw "Error: la cantidad actual de valijas supera a la total permitida";
		if (!listaValija[ocupados]) {
			this->listaValija[ocupados] = valija;
			this->ocupados++;
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
	for (ush i = 0; i < this->capacidad; i++)
		if (this->listaValija[i] && this->listaValija[i] == valija) {
			delete this->listaValija[i];
			this->listaValija[i] = NULL;
			this->ocupados--;
			ordenar();
			return true;
		}
	return false;
}

void cListaValija::ordenar() {
	for (ush i = 0; i < this->ocupados; i++) {
		bool checkSwap = false;
		for (ush j = 0; j < this->ocupados - i - 1; j++) {
			swap(this->listaValija[j], this->listaValija[j + 1]);
			checkSwap = true;
		}
		if (!checkSwap)
			break;
	}
}

string cListaValija::to_string() const {
	stringstream stc;
	stc << "Checkeo de eliminar la lista (1 / si) (0 / no): " << this->checkEliminar << endl;
	for (ush i = 0; i < this->ocupados; i++)
		stc << "Peso Valija [" << i << "]: " << this->listaValija[i]->peso << endl;
	return stc.str();
}


