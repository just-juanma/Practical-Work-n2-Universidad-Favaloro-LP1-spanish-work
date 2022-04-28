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
	for(int i = 0; i < this->capacidad; i++) {
		Listalocal[i] = NULL;
	}
	this->Lista = Listalocal;

}

cListaAvion::cListaAvion()
{
	this->capacidad = MAX;
	this->ocupados = 0;
	this->Lista;
	cAvion** Listalocal;
	Listalocal = new cAvion * [capacidad];
	for (int i = 0; i < this->capacidad; i++) {
		Listalocal[i] = NULL;

	}
	this->Lista = Listalocal;
}

cListaAvion::~cListaAvion()
{
	if (this->Lista != NULL) {
		for (int i = 0; i < ocupados; i++)
		{
			if (Lista[i] != NULL)
				delete Lista[i]; //libera memoria de objetos Tipodato
			}
			delete[]Lista; //libera memoria del array de punteros Tipodato**
		}

	
}
bool cListaAvion::Agregar(cAvion* _avion) {
	if (cListaAvion::ocupados >= cListaAvion::capacidad)
		return false;
	this->Lista[cListaAvion::ocupados] = _avion;
	return true;
}

cAvion* cListaAvion::Quitar(sh posición) {
	cAvion* aux = NULL; 
	if (posición < this->ocupados) {
		aux = this->Lista[posición];
		this->Eliminar(posición);
		this->ordenar();
		return aux;
	}return NULL;
	
}	 


bool cListaAvion::Eliminar(sh posición) {
	if (posición >= 0 && this->Lista[posición]) {
		delete this->Lista[posición];
		this->Lista[posición] = NULL;
		ordenar();
		return true;
	}
	return false;
}
int cListaAvion::Buscar(string _id) {
	for (int i = 0; i < this->ocupados; i++) {
		string aux; 
		aux = this->Lista[i]->getid();
		if (aux==_id) {
			return i;
		}
	}
	return -1;
}          



void cListaAvion::ordenar() {
	for (ush i = 0; i < this->ocupados - 1; i++) {
		bool checkSwap = false;
		for (ush j = 0; j < this->ocupados - i - 1; j++) {
			swap(this->Lista[j], this->Lista[j + 1]);
			checkSwap = true;
		}
		if (!checkSwap)
			break;
	}
}

void cListaAvion::Listar() {
	for (sh i = 0; i < this->ocupados; i++) {
		this->Lista[i]->imprimir();
	}
}


cAvion* cListaAvion::operator[](int posic_i) {
	if (posic_i >= 0 && posic_i < this->ocupados) {
		return this->Lista[posic_i];
	}return NULL;

}