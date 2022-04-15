#include "gbl.h"
#include "cVuelo.h"
#include "cPasajero.h"

// implementacion cVuelo

// inicializacion de atributos estaticos
unsigned int cVuelo::generadorNumerosDeVuelo = 0;
string** cVuelo::posibleDestino;
bool cVuelo::verificarDestino = false;

cVuelo::cVuelo(bool _partidaArribo, eEstado _estado) {
	this->partidaArribo = _partidaArribo;
	this->estado = _estado;
	this->pesoObtenido = 0;
	this->nPasajero = 0;
	generadorNumerosDeVuelo++;
	this->aeropuertoDestino = NULL;
	this->partida = NULL;
	this->arribo = NULL;
	// hago dinamico el puntero doble
	listaPasajero = new cPasajero * [1];
	// hago dinamico cada puntero simple
	for (int i = 0; i < 1; i++)
		listaPasajero[i] = new cPasajero;
}

cVuelo::~cVuelo() {
	// igual que sumo un atributo estatico en el constructor, lo debo restar en el destructor
	generadorNumerosDeVuelo--;
	// si existe la lista
	if (listaPasajero != NULL) {
		for (int i = 0; i < nPasajero + 1; i++)
			delete listaPasajero[i];
		// elimino el puntero doble
		delete[] listaPasajero;
	}
}

void cVuelo::crearLista() {
	posibleDestino = new string * [MAXDESTINOS];
	for (int i = 0; i < MAXDESTINOS; i++)
		posibleDestino[i] = new string;
}

void cVuelo::eliminarLista() {
	// si se genero posibleDestino correctamente
	if (posibleDestino != NULL) {
		// elimino cada puntero posibleDestino
		for (int i = 0; i < MAXDESTINOS; i++)
			if (posibleDestino[i] != NULL) delete posibleDestino[i];
		// elimino el array de posibleDestino
		delete[] posibleDestino;
	}
}
void cVuelo::setDestinosPosibles() {
	crearLista();
	// si existe mi listado de posibleDestino
	if (posibleDestino != NULL && !verificarDestino) {
		for (int i = 0; i < MAXDESTINOS; i++)
			if (posibleDestino[i] != NULL) {
				switch (i) {
				case 0:
					*posibleDestino[i] = "Jerusalen";
					break;
				case 1:
					*posibleDestino[i] = "Tel Aviv";
					break;
				case 2:
					*posibleDestino[i] = "Eilat";
					break;
				case 3:
					*posibleDestino[i] = "Beerseva";
					break;
				case 4:
					*posibleDestino[i] = "Haifa";
					break;
				// si se llega a modificar el valor de MAXDESTINOS, entrara aca
				default: verificarDestino = false;
				}
			}
		verificarDestino = true;
	}
	else verificarDestino = false;
}

bool cVuelo::agregarPasajero(cPasajero* posiblePasajero) {
	// si existe la lista
	if (listaPasajero != NULL) {
		for (int i = 0; i < nPasajero + 1; i++) {
			// si existe el puntero simple
			if (listaPasajero[i] != NULL) {
				nPasajero++;
				// genero una lista auxiliar para redefinir la longitud de mi lista
				cPasajero** nuevaLista = new cPasajero * [nPasajero];
				// copio su memoria
				memcpy(nuevaLista, listaPasajero, nPasajero * sizeof(nPasajero));
				// conservo sus datos
				listaPasajero = nuevaLista;
				listaPasajero[nPasajero - 1] = posiblePasajero;
				return true;
			}
		}
	}
	return false;
}

bool cVuelo::cambiarPasajero(unsigned int pos, cPasajero* nuevoPasajero) {
	if (listaPasajero != NULL && listaPasajero[pos] != NULL) {
		listaPasajero[pos] = nuevoPasajero;
		return true;
	}
	return false;
}

cPasajero* cVuelo::quitarPasajero(unsigned int pos) {
	cPasajero* aux;
	// verifico que no sea un posicion incorrecta
	if (pos >= nPasajero)
		return NULL;
	// guardo el valor para retornarlo
	aux = listaPasajero[pos];
	// desde la posicion en adelante, subo los lugares ocupados
	for (int i = nPasajero; i < nPasajero - 1; i++)
		for (int j = nPasajero; j < nPasajero - i - 1; j++)
			swap(listaPasajero[j], listaPasajero[j + 1]);
	// apunto a NULL a la ultima posicion
	listaPasajero[nPasajero - 1] = NULL;
	// lo retiro de la lista
	nPasajero--;
	return aux;
}

bool cVuelo::eliminarPasajero(unsigned int pos) {
	// si no se puede retirar el equipaje
	if (NULL == quitarPasajero(pos))
		return false;
	listaPasajero[pos]->~cPasajero();
	return true;
}