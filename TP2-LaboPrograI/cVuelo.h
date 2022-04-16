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
	/// <param name="_aeropuertoDestino">: String formato "Aeropuerto de X"</param>
	/// <param name="_estado">: Estado del vuelo</param>
	cVuelo(bool _partidaArribo = false, eEstado _estado = sinEstado);
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cVuelo();
	// hacer bato
	//string to_string();
	//string imprimir();

	#pragma endregion

	#pragma region metodos	
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
	/// <summary>
	/// Permite cambiar el estado del vuelo
	/// </summary>
	/// <param name="estado_">: Nuevo estado del vuelo</param>
	void setEstado(eEstado estado_) {
		this->estado = estado_;
	}
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
		// buscamos dentro de la lista de posibles destinos
		if (aeropuertoDestino == NULL) {
			for (int i = 0; i < MAXDESTINOS; i++)
				// si encuentra una concidencia
				if (*posibleDestino[i] == _posibleDestino) {
					// guardamos el aeropuerto destino
					this->aeropuertoDestino = &_posibleDestino;
					return true;
				}
		}
		return false;
		
	}
	/// <summary>
	/// Permite obtener la cantidad total de numeros de vuelo
	/// </summary>
	/// <returns>Cantidad obtenida</returns>
	unsigned int getNumeroVuelo()const {
			return generadorNumerosDeVuelo;
	}
	/// <summary>
	/// Mediante un DNI, guarda el peso del equipaje del pasajero
	/// </summary>
	/// <param name="_DNI">DNI a buscar</param>
	/// <returns>True en caso de que el peso de el equipaje sea > 0, false en caso contrario</returns>
	bool datosPasajero(unsigned int _DNI) {
		// si existe la lista de pasajeros
		if (listaPasajero != NULL) {
			for (int i = 0; i < nPasajero; i++) {
				// si se encuentra una coincidencia entre el DNI parametro y el pasajero
				if (_DNI == listaPasajero[i]->getDNI()) {
					// guardo el peso
					this->pesoObtenido = listaPasajero[i]->getPesoEquipaje(i);
					if (pesoObtenido > 0) 
						return true;
				} 
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
	bool cambiarPasajero(unsigned int pos, cPasajero* nuevoPasajero);
	/// <summary>
	/// Quitar pasajero de la lista
	/// </summary>
	/// <param name="pos">: Posicion a quitar</param>
	/// <returns>Pasajero quitado, NULL si no se quita nada</returns>
	cPasajero* quitarPasajero(unsigned int pos);
	/// <summary>
	/// Eliminar al pasajero de la lista
	/// </summary>
	/// <param name="pos">: Posicion a eliminar</param>
	/// <returns>True en caso de eliminarlo, false en caso contrario</returns>
	bool eliminarPasajero(unsigned int pos);
	#pragma endregion
private: 

	// global
    static unsigned int generadorNumerosDeVuelo;
    static string** posibleDestino;
	static bool verificarDestino;

	// clases
	eEstado estado;
	//cAvion avion;
	cFecha* partida;
	cFecha* arribo;
	//cAeropuerto aeropuerto; //si esta volando induca el aeropuerto que llega y si aterriza 
	cPasajero** listaPasajero;
	
	// locales
	unsigned int nPasajero;
	double pesoObtenido;
	string* aeropuertoDestino;
	bool partidaArribo;
};

#endif //_CVUELO_H