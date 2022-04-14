#include "cAeropuerto.h"
// implementation cAeropuerto 


unsigned int cAeropuerto::numeroAeropuerto = 0; // inicializo lo estatico
cAeropuerto::cAeropuerto(const unsigned int _ID, unsigned int _capacidadAeropuerto, unsigned int _nVuelos, unsigned int _nAviones, const string _nombre): ID(_ID), nombre(_nombre) {
	numeroAeropuerto++;
	capacidadAeropuerto = _capacidadAeropuerto;
	nVuelos = 0;
	nAviones = 0; 

	// hago dinamico el puntero doble
	listaVuelo = new cVuelo * [1];
	// hago dinamico cada puntero simple
	for (int i = 0; i < 1; i++)
		listaVuelo[i] = new cVuelo;

	//listaAvionAeropuerto = new cAvion * [1];   Agregar cuando Adriel complete la clase cAvion
	//for (int i = 0; i < 1; i++)
	//	listaAvionAeropuerto[i] = new cAvion;
}

cAeropuerto::~cAeropuerto() {
	numeroAeropuerto--;
	if (listaVuelo != NULL) {
		for (int i = 0; i < nVuelos; i++)
			if (listaVuelo[i] != NULL) delete listaVuelo[i];
		delete[] listaVuelo;
	}

	if (listaAvionAeropuerto != NULL) {
		for (int i = 0; i < nAviones; i++)
			if (listaAvionAeropuerto[i] != NULL) delete listaAvionAeropuerto[i];
		delete[] listaAvionAeropuerto;
	}


}

bool cAeropuerto::agregarAvion(cAvion* Avion) {
	if (listaAvionAeropuerto != NULL)
	{
		if (darPermiso()==true) //ver si es necesario ==true
		{
			// genero una lista auxiliar para redefinir la longitud de mi lista
			cAvion** nuevaLista = new cAvion * [nAviones];
			// copio su memoria
			memcpy(nuevaLista, listaAvionAeropuerto, nAviones * sizeof(nAviones));
			// conservo sus datos
			listaAvionAeropuerto = nuevaLista;
			listaAvionAeropuerto[nAviones - 1] = Avion;
			return true;
		}
		
	}
}


cAvion* cAeropuerto::retirarAvion(unsigned int nAvion) {
		cAvion* aux;
		// verifico que no sea un posicion incorrecta
		if (nAvion >= nAviones)
			return NULL;
		// guardo el valor para retornarlo
		aux = listaAvionAeropuerto[nAvion];
		// desde la posicion en adelante, subo los lugares ocupados
		for (int i = nAvion; i < nAviones - 1; i++)
			for (int j = nAvion; j < nAviones - i - 1; j++)
				swap(listaAvionAeropuerto[j], listaAvionAeropuerto[j + 1]);
		// apunto a NULL la posicion
		listaAvionAeropuerto[nAviones - 1] = NULL;
		// lo retiro de la lista
		nAviones--;
		return aux;
}


bool cAeropuerto::darPermiso() {
	//verifico que sea posible agregar un nuevo avion al aeropuerto sin sobrepasar su capacidad maxima
	if (nAviones < capacidadAeropuerto)
		return true;
	else return false;
}

string cAeropuerto::to_string() {
	stringstream stc;
	stc << "ID:" << ID;
	stc << "Nombre:" << nombre;
	stc << "Capacidad:" << capacidadAeropuerto;
	stc << "Numero de aviones:" << nAviones;
	stc << "Vuelos disponibles:" << nVuelos;
	stc << endl;
	return stc.str();
}

string cAeropuerto::imprimir()
{
	cout << to_string();
}
