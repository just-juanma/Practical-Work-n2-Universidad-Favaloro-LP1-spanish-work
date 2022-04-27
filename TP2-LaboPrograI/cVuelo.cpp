#include "gbl.h"
#include "cVuelo.h"
#include "cPasajero.h"

// implementacion cVuelo

ush cVuelo::numero = 0;
sh cVuelo::cantTotal = 0;
cVuelo::cVuelo(bool _PoA, eEstado _estado) {
	numero++;
	this->PoA = _PoA;
	this->estado = _estado;
	this->vuelo = NULL;
	this->destino = NULL;
}

cVuelo::~cVuelo() {
	numero--;
}


float cVuelo::getPesoTotal() {
	float pesoValijasVuelo = 0;
	cListaPasajero* listaPasajerosAvion;
	if (listaPasajerosAvion) {
		//for (ush i = 0; i < avion->getCantPasajeros(); i++)
			pesoValijasVuelo += listaPasajerosAvion->listaPasajero[i]->pesoTotalEquipaje->peso;
		//pesoValijasVuelo += avion->getPesoHumano();
		//if(pesoValijasVuelo < avion->getPesoMaximo())
		return pesoValijasVuelo;
	}
}


string cVuelo::to_string() {
	stringstream stc;
	stc << "Cantidad de vuelos: " << numero << endl;
	stc << "Estado del vuelo: " << this->estado << endl;
	stc << "Partida (true) o arribo (false): " << this->PoA << endl;
	stc << "Fecha y hora del vuelo: " << this->vuelo << endl;
	stc << "Fecha y hora del destino: " << this->destino << endl;
	return stc.str();
}