#include "cListaAvion.h"


cListaAvion::cListaAvion(int L)
{
	this->capacidad = L;
	this->ocupados = 0; 
	cAvion** Listalocal;
	try {
		Listalocal = new cAvion * [capacidad];
	}
	catch (bad_alloc&) {
		cout << "Error: Fallo en la asignacion de memoria dinamica. El programa se termina";
			abort();
	}
	for(ush i = 0; i < this->capacidad; i++) {
		Listalocal[i] = NULL;
	}
	this->ListaAviones = Listalocal;

}

cListaAvion::cListaAvion()
{
	this->capacidad = MAX;
	this->ocupados = 0;
	this->ListaAviones;
	cAvion** Listalocal;
	Listalocal = new cAvion * [capacidad];
	for (ush i = 0; i < this->capacidad; i++) {
		Listalocal[i] = NULL;

	}
	this->ListaAviones = Listalocal;
}

cListaAvion::~cListaAvion()
{
	if (this->ListaAviones != NULL) {
		for (ush i = 0; i < ocupados; i++)
		{
			if (ListaAviones[i] != NULL)
				delete ListaAviones[i]; //libera memoria de objetos Tipodato
			}
			delete[]ListaAviones; //libera memoria del array de punteros Tipodato**
		}

	
}
bool cListaAvion::Agregar(cAvion* _avion) {
	try {
		if (_avion == NULL) {
			throw "Error en objeto pasado a avion";
		}
		if (cListaAvion::ocupados >= cListaAvion::capacidad)
			return false;
		this->ListaAviones[cListaAvion::ocupados] = _avion;
		cListaAvion::ocupados++;
		return true;
	}
	catch(const char* msg) {
		cout << msg << endl;
		abort();
	}
}

cAvion* cListaAvion::Quitar(ush posición) {
	cAvion* aux = NULL; 
	if (posición < this->ocupados) {
		aux = this->ListaAviones[posición];
		this->ListaAviones[posición] = NULL;
		cListaAvion::ocupados--;
		this->ordenar();
		return aux;
	}return NULL;
	
}	 


bool cListaAvion::Eliminar(sh posición) {
	if (posición >= 0 && this->ListaAviones[posición]) {
		delete this->ListaAviones[posición];
		this->ListaAviones[posición] = NULL;
		cListaAvion::ocupados--;
		ordenar();
		return true;
	}
	return false;
}
int cListaAvion::Buscar(string _id) {
	for (ush i = 0; i < this->ocupados; i++) {
		string aux; 
		aux = this->ListaAviones[i]->getid();
		if (aux==_id) {
			return i;
		}
	}
	return -1;
}          

void cListaAvion::ordenar() {
	for (ush i = 0; i < this->ocupados; i++)
		for (ush j = i; j < this->ocupados - 1; j++)
			if (!this->ListaAviones[i])
				swap(this->ListaAviones[j], this->ListaAviones[j + 1]);
}

void cListaAvion::Listar() {
	for (ush i = 0; i < this->ocupados; i++) {
		this->ListaAviones[i]->imprimir();
	}
}


cAvion* cListaAvion::operator[](int posic_i) {
	if (posic_i >= 0) {
		return this->ListaAviones[posic_i];
	}return NULL;

}