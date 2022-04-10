#ifndef _CVUELO_H
#define _CVUELO_H
#include "gbl.h"


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
    eEstado estado;
    bool partidaArribo;
    static string** posibleDestino;
};

#endif //_CVUELO_H