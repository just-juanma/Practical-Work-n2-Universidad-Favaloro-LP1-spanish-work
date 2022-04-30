#include "gbl.h"
#include "cVuelo.h"
#include "cPasajero.h"

// implementacion cVuelo

// inicializacion atributos estaticos
ush cVuelo::numero = 0;
sh cVuelo::cantTotal = 0;

cVuelo::cVuelo(bool _PoA, eEstado _estado, ePosiblesDestinos _ciudad) {
	// inicializacion de los atributos
	// por cada obj. generado, aumento su capacidad actual
	numero++;
	this->PoA = _PoA;
	this->estado = _estado;
	this->ciudad = _ciudad;
	this->vuelo = NULL;
	this->arribo = NULL;
}

cVuelo::~cVuelo() {
	// por cada obj. destruido, disminuyo su capacidad actual
	numero--;
}

string cVuelo::to_string()const {
	stringstream stc;
	stc << "ID: " << this->ID << endl;
	stc << "Cantidad de vuelos: " << numero << endl;
	stc << "Cantidad total de vuelos: " << cantTotal << endl;
	stc << "Estado del vuelo: " << this->estado << endl;
	stc << "Partida (true) o arribo (false): " << this->PoA << endl;
	stc << "Fecha y hora del vuelo: " << this->vuelo->to_string() << endl;
	stc << "Fecha y hora del destino: " << this->arribo->to_string() << endl;
	stc << "Avion asociado:" << endl << this->avion->to_string() << endl;
	stc << "Lista de pasajeros asociada al vuelo: " << endl << this->claselistaPasajero->to_string() << endl;
	return stc.str();
}

ostream& operator << (ostream& out, cVuelo* _vuelo) {
	out << _vuelo->to_string();
	return out;
}