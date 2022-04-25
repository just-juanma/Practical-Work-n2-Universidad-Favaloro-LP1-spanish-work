#include "cAvion.h"
cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros) {
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


	this->ID = rand() % 200;
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

void cAvion::despegar() {
	this->estado = volando;
}

void cAvion::aterrizar() {
	this->estado = aterrizado;
}

void cAvion::pedirPermiso(string* _fecha,cListaPasajero pasajeros) { //agregar argumento ,clistapasajeros lista){

	try
	{


		switch (this->estado)
		{
		case volando:
			this->vuelo.setEstado(aterrizado); //si se 
		case aterrizado:
			this->chequearCargaMaxima();
			//this->setlistapasajeros(lista);
			this->vuelo.setHorarios(this->getfecha(), *_fecha);
			this->despegar();
			this->setPasajeros(pasajeros);
			//EL PROCESO INFERIOR QUE ES CHEQUEAR QUE LOS PASAJEROS 
			// SEAN LOS CORRECTOS ESTO LO TIENE QUE HACER EL AEROPUERTO O CLASE VUELO, NO EL AVION
			//for (int i = 0; this->nPasajeros <= i; i++) { 
			//	if(!this->vuelo.isValidNVuelo(i)){
			//		//tirar excepcion;
			//	}
			//}
		case sinEstado:

		}
	}
	catch (const std::exception&)
	{
		throw std::invalid_argument("Error en pedirPermiso()");
		//hacer el tema de crear una exception para cada caso especifico y hacer el tostring adecuado
	}


}

bool cAvion::chequearCargaMaxima() {
	try
	{
		int sumatotal = this->nPasajeros * 75 + (4 * 75);
		for (int i = 0; i < this->nPasajeros; i++) { //chequear como recoría el for el bucle 
			sumatotal += this->pasajeros[0][i].getPesoEquipaje(i);

		}
		//if(this->ListaPasajeros.pesoTot() > this.pesoMaximo){
		// throw exeption("Hay mucho peso para despegar");
		// }
		//
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


void cAvion::setPasajeros(cListaPasajero* _pasajeros) { this->pasajeros = _pasajeros; }
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