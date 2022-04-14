#include "gbl.h"
#include "cVuelo.h"

// implementacion cVuelo
unsigned int cVuelo::generadorNumerosDeVuelo = 0;
string** cVuelo::posibleDestino;
bool cVuelo::verificarDestino = false;

cVuelo::cVuelo(bool _partidaArribo, eEstado _estado) {
	this->partidaArribo = _partidaArribo;
	this->estado = _estado;
	generadorNumerosDeVuelo++;
	this->aeropuertoDestino = NULL;
	this->partida = NULL;
	this->arribo = NULL;
}

cVuelo::~cVuelo() {
	generadorNumerosDeVuelo--;
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

string cVuelo::to_string() {
	stringstream stc;
	stc << "Numero de vuelo:" << generadorNumerosDeVuelo;
	stc << "Estado:" << to_string(estado);
	stc << "Partida:" << partida;
	stc << "Arribo:" << arribo;
	stc << "Destino:" << aeropuertoDestino;
	stc << endl;
	return stc.str();
}

string cVuelo::imprimir()
{
	cout << to_string();
}
