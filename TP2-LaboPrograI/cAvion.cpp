#include "cAvion.h"
cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros){
	try
	{
		if (_totalPasajeros >= 0 && _pesoMaximo >= 0 && _nPasajeros >= 0) {
			this->totalPasajeros = _totalPasajeros;
			this->pesoMaximo = _pesoMaximo;
			this->nPasajeros = _nPasajeros;
		}
		else {
			throw exception();
		}
	}
	catch (const std::exception&)
	{
		throw std::invalid_argument("Error en el constructor");
		//hacer el tema de crear una clase exception para cada caso especifico y hacer el tostring adecuado
	}
	
	
	this->ID = rand()%200;
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

void cAvion::despegar() {
	/// <summary>
	/// se le solicita permiso al aeropuerto asignado al avion en el vuelo asignado para chequear que los 
	/// pasajeros a bordo sean los correctos, luego se chequea el peso y del equipaje y tripalacion no 
	/// supere el peso que el avion puede soportar
	/// </summary>
	this->pedirPermiso();	
}

void cAvion::aterrizar() {
	/// <summary>
	/// Se le solicita permiso al aeropuerto asigando que chequee la disposicion en el hangar para poder asi
	/// realizar el aterrizaje
	/// </summary>
	this->pedirPermiso();
}



void cAvion::pedirPermiso() {
	/// <summary>
	/// Luego de que se haya aceptado el ingreso del avion al aeropuerto se le asigna una nueva fecha.
	/// En caso contrario la clase aeropuerto tirara la excepcion correspondiente
	/// En caso de ser la fecha de despegue, se corrobora y se afirma la misma fecha en caso contrario
	/// tira exception 
	/// </summary>
	//try
	//{
	//	if (this->aeropuerto.darPermiso() == true){
	//		this->vuelo.cambiarfecha(aeropuerto->DarFecha());
	//	}
	//	switch (this->estado)
	//	{
	//	case volando:
	//		this->estado = this->vuelo.cambiarestado();
	//	case aterrizado:
	//		bool carga = this->chequearCargaMaxima();
	//		for (int i = 0; this->nPasajeros <= i; i++) { //chequear como recoría el for el bucle 
	//			if(!this->pasajeros[i].isValidNVuelo()) {
	//				//tirar excepcion;
	//			}
	//		}
	//		this->estado = this->vuelo.cambiarestado();
	//	default:
	//		throw exception();
	//	}
	//}
	//catch (const std::exception&)
	//{
	//  throw std::invalid_argument("Error en pedirPermiso()");
	//	//hacer el tema de crear una exception para cada caso especifico y hacer el tostring adecuado
	//}
	//
	
}

bool cAvion::chequearCargaMaxima() {

	/// <summary>
	/// chequeo que la suma del peso no se exceda de lo permitido 
	/// </summary>
	/// <returns></returns>
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