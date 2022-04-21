#ifndef _CVUELO_H
#define _CVUELO_H
#include "gbl.h"
#include "cFecha.h"
#include "cPasajero.h"
//#include "cAvion.h"
//#include "cAeropuerto.h"

class cVuelo {
public:
	#pragma region constructor y destructor
	/// <summary>
	/// Constructor parametrizado
	/// </summary>
	/// <param name="_partidaArribo">: (true) partida, (false) arribo</param>
	/// <param name="_estado">: Estado del vuelo</param>
	cVuelo(bool _partidaArribo = false, eEstado _estado = sinEstado);
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cVuelo();
	#pragma endregion

	#pragma region metodos globales
	/// <summary>
	/// Crea la lista global con los posibles destinos
	/// </summary>
	static void crearLista();
	/// <summary>
	/// Elimina la lista de posibles destinos
	/// </summary>
	static void eliminarLista();
	/// <summary>
	/// Setea los destinos posibles en la lista global
	/// </summary>
	static void setDestinosPosibles();
	#pragma endregion

	#pragma region getters y setters
	/// <summary>
	/// Permite obtener la cantidad total de numeros de vuelo
	/// </summary>
	/// <returns>Cantidad obtenida</returns>
	unsigned short getNumeroVuelo()const { return generadorNumerosDeVuelo; }
	/// <summary>
	/// Permite cambiar el estado del vuelo
	/// </summary>
	/// <param name="estado_">: Nuevo estado del vuelo</param>
	void setEstado(eEstado estado_) { this->estado = estado_; }
	/// <summary>
	/// Setea los horarios de un vuelo segun como este el vuelo
	/// </summary>
	/// <param name="horaPartida">: Hora de partida del vuelo</param>
	/// <param name="horaArribo">: Hora de arribo del vuelo</param>
	/// <returns></returns>
	bool setHorarios(string horaPartida, string horaArribo) {
		// si es partida, y se tiene el aeropuerto
		if (partidaArribo && aeropuertoDestino != NULL) {
			// seteo las fechas pertinentes
			partida->setFecha(&horaPartida);
			arribo->setFecha(&horaArribo);
			return true;
		}
		return false;
	}
	/// <summary>
	/// Setea el destino, en caso de encontrarlo en la lista de posibles destinos
	/// </summary>
	/// <param name="_posibleDestino">: recibe un aeropuerto en formato "X", siendo X el nombre del destino</param>
	/// <returns></returns>
	bool setDestino(string _posibleDestino) {
		// si aun no existe el aeropuerto
		if (aeropuertoDestino == NULL) {
			// buscamos dentro de la lista de posibles destinos
			for (unsigned short i = 0; i < MAXDESTINOS; i++)
				// si encuentra una concidencia
				if (*posibleDestino[i] == _posibleDestino) {
					// guardamos el aeropuerto destino
					this->aeropuertoDestino = &_posibleDestino;
					return true;
				}
		}
		return false;

	}
	#pragma endregion

	#pragma region metodos
	/// <summary>
	/// Mediante un DNI, guarda el peso del equipaje del pasajero
	/// </summary>
	/// <param name="_DNI">DNI a buscar</param>
	/// <returns>True en caso de que el peso de el equipaje sea > 0, false en caso contrario</returns>
	bool datosPasajero(unsigned short _DNI) {
		// si existe la lista de pasajeros
		if (listaPasajero != NULL) {
			for (unsigned short i = 0; i < nPasajero; i++) {
				// si se encuentra una coincidencia entre el DNI parametro y algun pasajero
				if (_DNI == listaPasajero[i]->getDNI()) {
					// recorro todas sus valijas y las voy sumando
					for (unsigned short j = 0; j < listaPasajero[i]->getNValijas(); j++) 
						this->pesoObtenido = listaPasajero[i]->getPesoEquipaje(j);
					// si es un peso valido
					if (pesoObtenido > 0) 
						return true;
				} 
				// si no se encuentra el DNI
				else return false;
			}
		}
		return false;
	}
	/// <summary>
	/// Agrega un pasajero a lista de pasajeros
	/// </summary>
	/// <param name="posiblePasajero">: Posible pasajero a agregar a la lista</param>
	/// <returns>True en caso de poder agregarlo, false en caso contrario</returns>
	bool agregarPasajero(cPasajero* posiblePasajero);
	/// <summary>
	/// Cambia la posicion de un pasajero por otro
	/// </summary>
	/// <param name="pos">: Posicion a cambiar</param>
	/// <param name="nuevoPasajero">: Datos del pasajero nuevo</param>
	/// <returns>True en caso de poder cambiarlo, false en caso contrario</returns>
	bool cambiarPasajero(unsigned short pos, cPasajero* nuevoPasajero);
	/// <summary>
	/// Quitar pasajero de la lista
	/// </summary>
	/// <param name="pos">: Posicion a quitar</param>
	/// <returns>Pasajero quitado, NULL si no se quita nada</returns>
	cPasajero* quitarPasajero(unsigned short pos);
	/// <summary>
	/// Eliminar al pasajero de la lista
	/// </summary>
	/// <param name="pos">: Posicion a eliminar</param>
	/// <returns>True en caso de eliminarlo, false en caso contrario</returns>
	bool eliminarPasajero(unsigned short pos);
	/// <summary>
	/// Verifica que el numero de vuelo del pasajero [pos] coincida con algun numero de vuelo de los generados
	/// </summary>
	/// <param name="pos">Posicion del pasajero en la lista</param>
	/// <returns>True en caso de encontrar una coincidencia, false en caso contrario</returns>
	bool isValidNVuelo(unsigned short pos) {
		for (unsigned short i = 0; i < generadorNumerosDeVuelo; i++) 
			if (listaPasajero[pos]->getNVuelo() == i)
				return true;
		return false;
	}
	// metodos pedidos por el Trabajo Practico
	string to_string();
	void imprimir();
	#pragma endregion
private: 

	// global
    static unsigned short generadorNumerosDeVuelo;
    static string** posibleDestino;
	static bool verificarDestino;

	// clases
	eEstado estado;
	cFecha* partida;
	cFecha* arribo;
	cPasajero** listaPasajero;
	
	// locales
	unsigned short nPasajero;
	double pesoObtenido;
	string* aeropuertoDestino;
	bool partidaArribo;
};

#endif //_CVUELO_H