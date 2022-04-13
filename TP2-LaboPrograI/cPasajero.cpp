#include "gbl.h"
#include "cPasajero.h"

// implementacion cPasajero

// inicializo lo estatico
unsigned int cPasajero::numeroAsiento = 0;
cPasajero::cPasajero(string _nombre, unsigned int _DNI): nombre(_nombre), DNI(_DNI) {
	// le asigno un numero de asiento. La idea es que por cada objeto pasajero que se crea, asignarle numero de asiento + 1
	numeroAsiento++;
	// JUANMA no esta seguro de la siguiente linea, JUANMA se encargara de revisarlo mas tarde
	numeroVuelo = vuelo->getNumeroVuelo();
	this->pesoTotal = 0;
	this->nValijaRetirada = 0;
	// debe iniciar en 1 al menos para comenzar a utilizar memoria dinamica
	this->nValijas = 1;
	// explicacion del manejo de memoria dinamica se va a evitar por el momento
	listaValija = new cValija * [nValijas];
	for (int i = 0; i < nValijas; i++)
		listaValija[i] = new cValija;
	
}

cPasajero::~cPasajero() {
	// le saco el numero a cada pasajero
	numeroAsiento--;
	if (listaValija != NULL) {
		for (int i = 0; i < nValijas; i++)
			if (listaValija[i] != NULL) delete listaValija[i];
		delete[] listaValija;
	}
}

// estoy comentando a las 00:13, me voy a dormir. Saludos al que lea esto. el 13/04 voy a comentar todo lo que se 
// encuentra abajo de esta linea, y lo demas trabajado hasta ahora
bool cPasajero::agregarEquipaje(cValija* posibleValija) {
	if (listaValija != NULL) {
		for(int i = 0; i < nValijas; i++)
			if (listaValija[i] != NULL && pesoTotal < 25) {
				cValija** nuevaLista = new cValija * [nValijas];
				memcpy(nuevaLista, listaValija, nValijas * sizeof(nValijas));
				listaValija = nuevaLista;
				listaValija[nValijas - 1] = posibleValija;
				pesoTotal += posibleValija->getPeso();
				nValijas++;
				return true;
			}
	}
	return false;
}

cValija* cPasajero::retirarEquipaje() {
	nValijaRetirada++;
	if (nValijaRetirada == nValijas || listaValija[nValijaRetirada - 1] == NULL)
		return NULL;
	return listaValija[nValijaRetirada - 1];
}

