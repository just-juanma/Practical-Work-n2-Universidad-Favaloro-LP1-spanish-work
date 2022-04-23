#include "cAvion.h"
cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros){
	try
	{
		this->totalPasajeros = _totalPasajeros;
		this->pesoMaximo = _pesoMaximo;
		this->nPasajeros = _nPasajeros;
		
	}
	catch (const std::exception&)
	{
		throw std::invalid_argument("Error en el constructor");
		//hacer el tema de crear una clase exception para cada caso especifico y hacer el tostring adecuado
	}
	
	
	this->ID = %200;
	//ID no lo utilizo para nada, 
}

cAvion::~cAvion() {
	if (pasajeros != NULL) {
		for (int i = 0; i < nPasajeros; i++) {
			delete[] pasajeros[i];
		}
		delete[] pasajeros;
	}

	//if (aeropuerto != NULL) {
	//	delete[] aeropuerto;
	//}
}

void cAvion::despegar(bool _valor, string* _fecha) {
	this->pedirPermiso(_valor, _fecha);
}

void cAvion::aterrizar(bool _valor, string* _fecha) {
	this->pedirPermiso(_valor, _fecha);
}

void cAvion::pedirPermiso(bool _valor,string* _fecha) {

	try
	{
		this->vuelo.setHorarios(this->getfecha(), *_fecha);
	
		switch (this->estado)
		{
		case volando:
			this->vuelo.setEstado(this->estado);
		case aterrizado:
			bool carga = this->chequearCargaMaxima();
			for (int i = 0; this->nPasajeros <= i; i++) { //chequear como recoría el for el bucle 
				if(!this->vuelo.isValidNVuelo(i)){
					//tirar excepcion;
				}
			}
			this->vuelo.setEstado(this->estado);
		default:
			throw exception();
		}
	}
	catch (const std::exception&)
	{
	  throw std::invalid_argument("Error en pedirPermiso()");
		//hacer el tema de crear una exception para cada caso especifico y hacer el tostring adecuado
	}
	
	
}

bool cAvion::chequearCargaMaxima(){
	try
	{
		int sumatotal = this->nPasajeros * 75 +(4 * 75);
		for (int i = 0; this->nPasajeros <= i; i++) { //chequear como recoría el for el bucle 
			sumatotal += this->pasajeros[0][i].getPesoEquipaje(i);
			
		}
		if (sumatotal > this->pesoMaximo) {
			throw exception();
		}
		else {
			return true;
		}
	}
	catch (const std::exception&)
	{
		throw std::invalid_argument("Error en chequearCargaMaxima()");
		//hacer el tema de crear una exception para cada caso especifico y hacer el tostring adecuado
	}
	
}


void cAvion::setPasajeros(cPasajero** _pasajeros) { this->pasajeros = _pasajeros; }
//void cAvion::setAeropuerto(cAeropuerto* _aeropuerto) { this->aeropuerto = _aeropuerto; }

string cAvion::to_string() {
	stringstream stc;
	stc << "ID:" << ID;
	stc << "Total pasajeros:" << totalPasajeros;
	stc << "Numero de pasajeros:" << nPasajeros;
	stc << "Peso maximo:" << pesoMaximo;
	/*stc << "Ubicacion actual:" << this->aeropuerto[0].getNombre();*/
	stc << "Vuelo actual:" << this->vuelo.getNumeroVuelo();
	stc << "Estado actual:" << this->estado;
	stc << endl;
	return stc.str();
}

void cAvion::imprimir()
{
	cout << to_string();
}