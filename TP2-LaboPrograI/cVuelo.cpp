#include "gbl.h"
#include "cVuelo.h"

// implementacion cVuelo

cVuelo::cVuelo(bool _partidaArribo, unsigned int _numeroDeVuelo, eEstado _estado) {
	this->partidaArribo = _partidaArribo;
	this->numeroDeVuelo = _numeroDeVuelo;
	this->estado = _estado;
	// pido memoria para un array de punteros posibleDestino de tamanio cantPosiblesDestinos
	posibleDestino = new string * [MAXDESTINOS];
	// apunto los punteros posibleDestino a NULL
	for (int i = 0; i < MAXDESTINOS; i++)
		posibleDestino[i] = NULL;
}
cVuelo::~cVuelo() {
	// si se genero posibleDestino correctamente
	if (posibleDestino != NULL) {
		// elimino cada puntero posibleDestino
		for (int i = 0; i < MAXDESTINOS; i++)
			if (posibleDestino[i] != NULL) delete posibleDestino[i];
		// elimino el array de posibleDestino
		delete[] posibleDestino;
	}
}
bool cVuelo::setDestinosPosibles(string* destino) {
	// si existe mi listado de posibleDestino
	if (posibleDestino != NULL)
		for (int i = 0; i < MAXDESTINOS; i++) {
			// si el puntero posibleDestino no contienen basura / otro destino, y ademas se establecio destino en la posicion [i] 
			if (posibleDestino[i] == NULL && &destino[i] != NULL)
				*posibleDestino[i] = destino[i];
			// si el puntero posibleDestino contiene algo, o no se establecio destino en la posicion [i]
			else return false;
		}
	// si no existe la lista posibleDestino, retorno falso
	else return false;

	return true;
}
//void cVuelo::bool validarPasajero() {
//
//}
//
//void cVuelo::bool agregarPasajero() {
//
//}
//
//void cVuelo::bool cambiarPasajero() {
//
//}
//
//void cVuelo::bool eliminarPasajero() {
//
//}