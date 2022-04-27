#include "gbl.h"
#include "cVuelo.h"
#include "cPasajero.h"

// implementacion cVuelo

ush cVuelo::numero = 0;
sh cVuelo::cantTotal = 0;
cVuelo::cVuelo(bool _PoA, eEstado _estado, ePosiblesDestinos _ciudad) {
	numero++;
	this->PoA = _PoA;
	this->estado = _estado;
	this->ciudad = _ciudad;
	this->vuelo = NULL;
	this->destino = NULL;
}

cVuelo::~cVuelo() {
	numero--;
}

//float cVuelo::getPesoTotal(cListaPasajero* _listaPasajerosAvion) {
//	float pesoValijasVuelo = 0;
//	if (_listaPasajerosAvion) {
//		//for (ush i = 0; i < avion->getCantPasajeros(); i++)
//			//pesoValijasVuelo += _listaPasajerosAvion->listaPasajero[i]->pesoTotalEquipaje->peso;
//		return pesoValijasVuelo;
//	}
//}


string cVuelo::to_string()const {
	stringstream stc;
	stc << "Cantidad de vuelos: " << numero << endl;
	stc << "Estado del vuelo: " << this->estado << endl;
	stc << "Partida (true) o arribo (false): " << this->PoA << endl;
	stc << "Fecha y hora del vuelo: " << this->vuelo << endl;
	stc << "Fecha y hora del destino: " << this->destino << endl;
	return stc.str();
}