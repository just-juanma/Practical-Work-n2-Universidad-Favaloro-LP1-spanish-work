#ifndef _CVUELO_H
#include "gbl.h"
#define _CVUELO_H

class cVuelo {
public:
	#pragma region constructor y destructor
	/// <summary>
	/// Constructor por defecto
	/// </summary>
	cVuelo();
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cVuelo();
	#pragma endregion

	#pragma region metodos
    
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