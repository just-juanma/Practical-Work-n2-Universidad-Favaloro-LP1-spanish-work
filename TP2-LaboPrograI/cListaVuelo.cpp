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
	try {
		if (cVuelo::numero >= cVuelo::cantTotal)
			throw "Error: la cantidad actual de vuelos supera a la total permitida";
		if (!listaVuelo[cVuelo::numero]) {
			this->listaVuelo[cVuelo::numero] = vuelo;
			return true;
		}
		else
			throw "Error: Ya existe un vuelo en la posicion donde se lo esta intentando agregar de la lista";
	}
	catch (const char* msg) {
		cout << msg << endl;
		return false;
	}
}

bool cListaVuelo::eliminar(sh pos) {
	try {
		if (pos >= 0 && this->listaVuelo[pos] && pos < cVuelo::numero) {
			delete this->listaVuelo[pos];
			this->listaVuelo[pos] = NULL;
			ordenar();
			return true;
		}
		else
			throw "Error: No se puede eliminar una posicion que no existe en la lista de vuelo";
	}
	catch (const char* msg) {
		cout << msg << endl;
		return false;
	}
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

string cListaVuelo::to_string()const {
	stringstream stc;
	stc << "Checkeo de eliminar (true / si) (false / no): " << checkEliminar << endl;
	stc << "Referencia de ciudades: (0) sin destino, (1) Jerusalen, (2) Beerseva, (3) Eilat" << endl;
	for (ush i = 0; i < cVuelo::numero; i++)
		if(listaVuelo[i])
			stc << "Ciudad destino del vuelo [" << i << "]: " << listaVuelo[i]->ciudad << endl;
	return stc.str();
}

cVuelo* cListaVuelo::operator[](int posic_i) {
	if (posic_i >= 0) {
		return this->listaVuelo[posic_i];
	}return NULL;

}
