#include "gbl.h"
#include "cVuelo.h"

// implementacion cFecha

cVuelo::cVuelo(unsigned int _numeroDeVuelo, eEstado _estado, bool _partidaArribo, unsigned int _cantPosiblesDestinos) {
	this->numeroDeVuelo = _numeroDeVuelo;
	this->estado = _estado;
	this->partidaArribo = _partidaArribo;
	if (_cantPosiblesDestinos < _NVUELOS) {
		this->cantPosiblesDestinos = _cantPosiblesDestinos;
		posibleDestino = new string * [cantPosiblesDestinos];
		for (int i = 0; i < cantPosiblesDestinos; i++) posibleDestino[i] = NULL;
	}
}
cVuelo::~cVuelo() {
	if (posibleDestino != NULL) 
		for (int i = 0; i < cantPosiblesDestinos; i++) 
			if (posibleDestino[i] != NULL) delete posibleDestino[i];
	delete[] posibleDestino;
}
void cVuelo::establecerDestinos() {
	if(posibleDestino != NULL)
		for(int i = 0; i < cantPosiblesDestinos; i++)
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