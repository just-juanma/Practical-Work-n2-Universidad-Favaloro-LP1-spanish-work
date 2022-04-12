#ifndef _CVUELO_H
#define _CVUELO_H
#include "gbl.h"
#include "cAvion.h"
#include "cAeropuerto.h"

class cVuelo {
public:
	#pragma region constructor y destructor
	/// <summary>
	/// Constructor parametrizado
	/// </summary>
	/// <param name="_partidaArribo">: (true) partida, (false) arribo</param>
	/// <param name="_numeroDeVuelo">: Numero reservado para el vuelo</param>
	/// <param name="_estado">: Estado del vuelo</param>
	cVuelo(bool _partidaArribo, unsigned int _numeroDeVuelo = 0, eEstado _estado = sinEstado);
	cVuelo();
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cVuelo();
	#pragma endregion

	#pragma region metodos	

	static void setDestinosPosibles();

	//bool setAvion

	//bool validarPasajero();
    
	//bool agregarPasajero();
    
	//bool cambiarPasajero();
    
	//bool eliminarPasajero();
	#pragma endregion
private: 
    unsigned int numeroDeVuelo;
    
    static string** posibleDestino;

	cAvion avion;
	eEstado estadoVuelo;
	bool partidaArribo;
	bool tipo;//1 si vuela, 0 si no.
	cFecha partida;
	cFecha arribo;
	//cAeropuerto aeropuerto; //si esta volando induca el aeropuerto que llega y si aterriza 
	
};

#endif //_CVUELO_H