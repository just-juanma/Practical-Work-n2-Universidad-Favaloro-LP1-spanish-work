#include "gbl.h"
#include "cVuelo.h"

// implementacion cVuelo
string** cVuelo::posibleDestino;
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
void cVuelo::setDestinosPosibles() {
	// si existe mi listado de posibleDestino
	if (posibleDestino != NULL)
		for (int i = 0; i < MAXDESTINOS; i++)
			if (posibleDestino[i] == NULL) {
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
				}
			}
	

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