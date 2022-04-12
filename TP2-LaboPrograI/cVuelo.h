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
	cVuelo(bool _partidaArribo, eEstado _estado = sinEstado);
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cVuelo();
	#pragma endregion

	#pragma region metodos	

	static void setDestinosPosibles();

	// TAREA PARA EL JUANMA DEL FUTURO: VERIFICAR QUE LA HORA SEA VALIDA
	bool setHorarios(string* horaPartida, string* horaArribo) {
		// * solo se puede cuando el es una partida, no arribo
		// * verifico que haya lugar para establecer una partida, y un arribo 
		if (!partidaArribo && partida == NULL && arribo == NULL) {
			partida->setFecha(horaPartida);
			arribo->setFecha(horaArribo);
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
		for (int i = 0; i < MAXDESTINOS; i++)
			// si encuentra una concidencia
			if (*posibleDestino[i] == _posibleDestino && aeropuertoDestino == NULL) {
				this->aeropuertoDestino = &_posibleDestino;
				return false;
			}
	}

	unsigned int getNumeroVuelo() {
		if (numeroVuelo > 0) 
			return numeroVuelo;
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
	eEstado estadoVuelo;
	//cAvion avion;
	cFecha* partida;
	cFecha* arribo;
	//cAeropuerto aeropuerto; //si esta volando induca el aeropuerto que llega y si aterriza 
	
	string* aeropuertoDestino;
	eEstado estado;
	bool partidaArribo;
	unsigned int numeroVuelo;

	
};

#endif //_CVUELO_H