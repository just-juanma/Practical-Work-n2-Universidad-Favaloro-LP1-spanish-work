#ifndef _CVUELO_H
#define _CVUELO_H
#include "gbl.h"
#include "cFecha.h"
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

	string to_string();
	string imprimir();

	#pragma endregion

	#pragma region metodos	

	static void crearLista();

	static void eliminarLista();

	static void setDestinosPosibles();

	void setEstado(eEstado estado_) {
		this->estado = estado_;
	}
	/// <summary>
	/// Setea los horarios de un vuelo segun como este el vuelo
	///	* solo se puede cuando el es una partida, no arribo
	///	* previo a setear horarios, debe existir un aeropuerto destino
	/// </summary>
	/// <param name="horaPartida">: Hora de partida del vuelo</param>
	/// <param name="horaArribo">: Hora de arribo del vuelo</param>
	/// <returns></returns>
	bool setHorarios(string horaPartida, string horaArribo) {
		if (!partidaArribo && aeropuertoDestino != NULL) {
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
		// buscamos dentro de una lista, en este caso en la lista de posibles destinos
		if (aeropuertoDestino == NULL) {
			for (int i = 0; i < MAXDESTINOS; i++)
				// si encuentra una concidencia
				if (*posibleDestino[i] == _posibleDestino) {
					aeropuertoDestino = &_posibleDestino;
					return true;
				}
		}
		return false;
		
	}

	unsigned int getNumeroVuelo()const {
			return generadorNumerosDeVuelo;
		return 0;
	}

	//bool setAvion

	//bool validarPasajero();
    
	//bool agregarPasajero();
    
	//bool cambiarPasajero();
    
	//bool eliminarPasajero();
	#pragma endregion
private: 
	// global
    static unsigned int generadorNumerosDeVuelo;
    static string** posibleDestino;
	static bool verificarDestino;

	// clases
	//cAvion avion;
	cFecha* partida;
	cFecha* arribo;
	//cAeropuerto aeropuerto; //si esta volando induca el aeropuerto que llega y si aterriza 
	
	string* aeropuertoDestino;
	eEstado estado;
	bool partidaArribo;
};

#endif //_CVUELO_H