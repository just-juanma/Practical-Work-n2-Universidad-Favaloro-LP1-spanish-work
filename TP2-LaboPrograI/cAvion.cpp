//#include "cAvion.h"
//
//unsigned int cAvion::ID;
//cAvion::cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros){
//	try
//	{
//		if (_totalPasajeros >= 0 && _pesoMaximo >= 0 && _nPasajeros >= 0) {
//			this->totalPasajeros = _totalPasajeros;
//			this->pesoMaximo = _pesoMaximo;
//			this->nPasajeros = _nPasajeros;
//		}
//		else {
//			throw exception();
//		}
//	}
//	catch (const std::exception&)
//	{
//		//hacer el tema de crear una exception para cada caso especifico y hacer el tostring adecuado
//	}
//	
//	
//	this->ID = rand()%200;
//}
//void cAvion::despegar() {
//	/// <summary>
//	/// se le solicita permiso al aeropuerto asignado al avion en el vuelo asignado para chequear que los 
//	/// pasajeros a bordo sean los correctos, luego se chequea el peso y del equipaje y tripalacion no 
//	/// supere el peso que el avion puede soportar
//	/// </summary>
//	this->pedirPermiso();	
//}
//
//void cAvion::aterrizar() {
//	/// <summary>
//	/// Se le solicita permiso al aeropuerto asigando que chequee la disposicion en el hangar para poder asi
//	/// realizar el aterrizaje
//	/// </summary>
//	this->pedirPermiso();
//}
//
//void cAvion::pedirPermiso() {
//	/// <summary>
//	/// Luego de que se haya aceptado el ingreso del avion al aeropuerto se le asigna una nueva fecha.
//	/// En caso contrario la clase aeropuerto tirara la excepcion correspondiente
//	/// En caso de ser la fecha de despegue, se corrobora y se afirma la misma fecha en caso contrario
//	/// tira exception 
//	/// </summary>
//	try
//	{
//		if (this->aeropuerto->DarPermiso() == true) {
//			this->vuelo.cambiarfecha(aeropuerto->DarFecha());
//		}
//		switch (this->estado)
//		{
//		case volando:
//			this->estado = this->vuelo.cambiarestado();
//		case aterrizado:
//			bool carga = this->chequearCargaMaxima();
//			for (int i = 0; this->nPasajeros <= i; i++) { //chequear como recoría el for el bucle 
//				if (this->pasajeros[i].getfecha() != this->vuelo.getfecha() || this->pasajeros[i].vuelo != this->ID) {
//					//tirar excepcion;
//				}
//			}
//			this->estado = this->vuelo.cambiarestado();
//		default:
//			throw exception();
//		}
//	}
//	catch (const std::exception&)
//	{
//		//hacer el tema de crear una exception para cada caso especifico y hacer el tostring adecuado
//	}
//	
//	
//}
//
//bool cAvion::chequearCargaMaxima() {
//
//	/// <summary>
//	/// chequeo que la suma del peso no se exceda de lo permitido 
//	/// </summary>
//	/// <returns></returns>
//	try
//	{
//		int sumatotal = this->nPasajeros * 75 + 4 * 75;
//		for (int i = 0; this->nPasajeros <= i; i++) { //chequear como recoría el for el bucle 
//			sumatotal += this->pasajeros[i].sumaquipaje();
//		}
//		if (sumatotal > this->pesoMaximo) {
//			throw exception();
//		}
//		else {
//			return true;
//		}
//	}
//	catch (const std::exception&)
//	{
//		//hacer el tema de crear una exception para cada caso especifico y hacer el tostring adecuado
//	}
//	
//}