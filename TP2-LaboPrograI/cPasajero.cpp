#include "gbl.h"
#include "cPasajero.h"

// implementacion cPasajero


cPasajero::cPasajero(string _nombre, unsigned short _DNI, unsigned short _nAsiento, unsigned short _nVuelo): nombre(_nombre), DNI(_DNI) {
	this->nAsiento = _nAsiento;
	this->nVuelo = _nVuelo;
	this->pesoTotal = 0;
	this->nValijas = 0;
	// hago dinamico el puntero doble
	listaValija = new cValija * [1];
	// hago dinamico cada puntero simple
	for (unsigned short i = 0; i < 1; i++)
		listaValija[i] = new cValija;
	
}

cPasajero::~cPasajero() {
	// si existe la lista
	if (listaValija != NULL) {
		for (unsigned short i = 0; i < nValijas + 1; i++)
				delete listaValija[i];
		// elimino el puntero doble
		delete[] listaValija;
	}
}

bool cPasajero::agregarEquipaje(cValija* posibleValija) {
	// si existe la lista
	if (listaValija != NULL) {
		for (unsigned short i = 0; i < nValijas + 1; i++) {
			pesoTotal += posibleValija->getPeso();
			// si existe el puntero simple, y el peso total es menor a 25
			if (listaValija[i] != NULL && pesoTotal < 25) {
				nValijas++;
				// genero una lista auxiliar para redefinir la longitud de mi lista
				cValija** nuevaLista = new cValija * [nValijas];
				// copio su memoria
				memcpy(nuevaLista, listaValija, nValijas * sizeof(nValijas));
				// conservo sus datos
				listaValija = nuevaLista;
				listaValija[nValijas - 1] = posibleValija;
				return true;
			}
			else pesoTotal -= posibleValija->getPeso();

		}
	}
	return false;
}

cValija* cPasajero::retirarEquipaje(unsigned short nEquipaje) {
	cValija* aux;
	// verifico que no sea un posicion incorrecta
	if (nEquipaje >= nValijas) 
		return NULL;
	// guardo el valor para retornarlo
	aux = listaValija[nEquipaje];
	// desde la posicion en adelante, subo los lugares ocupados
	for (unsigned short i = nEquipaje; i < nValijas - 1; i++)
		for (unsigned short j = nEquipaje; j < nValijas - i - 1; j++)
			swap(listaValija[j], listaValija[j + 1]);
	// apunto a NULL a la ultima posicion
	listaValija[nValijas - 1] = NULL;
	// lo retiro de la lista
	nValijas--;
	return aux;
}

bool cPasajero::eliminarEquipaje(unsigned short nEquipaje) {
	// si no se puede retirar el equipaje
	if (NULL == retirarEquipaje(nEquipaje))
		return false;
	listaValija[nValijas]->~cValija();
	return true;
}

string cPasajero::to_string() {
	stringstream stc;
	stc << "Nombre: " << nombre << endl;
	stc << "DNI: " << DNI << endl;
	stc << "Numero de asiento: " << nAsiento << endl;
	stc << "Numero de vuelo: " << nVuelo << endl;
	stc << "Numero de valijas: " << nValijas << endl;
	stc << "Peso total: " << pesoTotal << endl;
	return stc.str();
}

void cPasajero::imprimir()
{
	cout << to_string();
}
