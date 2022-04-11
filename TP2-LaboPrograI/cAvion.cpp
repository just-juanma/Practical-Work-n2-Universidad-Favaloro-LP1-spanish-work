#include "cAvion.h"

unsigned int cAvion::ID;
cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros){
	if (_totalPasajeros >= 0 && _pesoMaximo >= 0 && _nPasajeros >= 0) {
		this->totalPasajeros = _totalPasajeros;
		this->pesoMaximo = _pesoMaximo;
		this->nPasajeros = _nPasajeros;
	}
	else {
		//tirar exepcion
	}
	
	this->ID = rand()%200;
}

void cAvion::despegar() {
	/// <summary>
	/// se le solicita permiso al aeropuerto asignado al avion en el vuelo asignado para chequear que los 
	/// pasajeros a bordo sean los correctos (chequear consigna quiza la  clase vuelo cumple esta funcion
	/// y la clase avion es mas simple) 
	/// </summary>
	this->pedirPermiso();
	bool carga = this->chequearCargaMaxima();
	for (int i = 0; this->nPasajeros <= i; i++) { //chequear como recoría el for el bucle 
		if (this->pasajeros[i].fecha != this->fechavuelo || this->pasajeros[i].vuelo != this->ID) {
			//tirar excepcion;
		}
	}
	this->estado =this->vuelo.cambiarestado();
	
}

void cAvion::aterrizar() {
	this->pedirPermiso();
}

void cAvion::pedirPermiso() {
	/// <summary>
	/// Luego de que se haya aceptado el ingreso del avion al aeropuerto se le asigna una nueva fecha
	/// En caso de ser la fecha de despegue, se corrobora y se afirma la misma fecha en caso contrario
	/// tira exception
	/// </summary>
	if (this->aeropuerto->DarPermiso() == true) {
		this->fechavuelo = aeropuerto->DarFecha(); 
	}

	switch (this->estado)
	{
	case volando:
		this->aterrizar();
	case aterrizado: 
		this->despegar();
	default:
		//tirar excepcion que no se pudo volar porque el estado del avion esta mal
	}
	
}

bool cAvion::chequearCargaMaxima() {

	/// <summary>
	/// chequeo que la suma no se exceda 
	/// </summary>
	/// <returns></returns>
	try
	{
		int sumatotal = this->nPasajeros * 75 + 4 * 75;
		for (int i = 0; this->nPasajeros <= i; i++) { //chequear como recoría el for el bucle 
			sumatotal += this->pasajeros[i].sumaquipaje();
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
		//hacer el tema de crear una exception para cada caso especifico y hacer el tostring adecuado
	}
	
}