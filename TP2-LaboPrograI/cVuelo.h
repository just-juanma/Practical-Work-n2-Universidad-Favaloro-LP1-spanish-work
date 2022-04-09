#ifndef _CVUELO_H
#define _CVUELO_H
#include "gbl.h"

class cVuelo {
public:
	#pragma region constructor y destructor
	/// <summary>
	/// Constructor parametrizado
	/// </summary>
	/// <param name="_numeroDeVuelo">: Numero reservado para el vuelo</param>
	/// <param name="_estado">: Estado del vuelo</param>
	/// <param name="_partidaArribo">: Describe si el vuelo esta en estado de partida (true) o arribo (false)</param>
	/// <param name="_cantPosiblesDestinos">: #define que contiene la cantidad de destintos</param>
	cVuelo(unsigned int _numeroDeVuelo = 0, eEstado _estado = sinEstado, bool _partidaArribo = false, 
		  unsigned int _cantPosiblesDestinos = _NVUELOS);
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cVuelo();
	#pragma endregion

	#pragma region metodos
    
	void establecerDestinos();

	//bool validarPasajero();
    
	//bool agregarPasajero();
    
	//bool cambiarPasajero();
    
	//bool eliminarPasajero();
	#pragma endregion
private: 
    unsigned int numeroDeVuelo;
	unsigned int cantPosiblesDestinos;
    eEstado estado;
    bool partidaArribo;
    static string** posibleDestino;
};

#endif //_CVUELO_H