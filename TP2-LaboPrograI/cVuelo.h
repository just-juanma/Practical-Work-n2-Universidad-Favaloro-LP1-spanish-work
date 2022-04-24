#ifndef _CVUELO_H
#define _CVUELO_H
#include "gbl.h"
#include "cAvion.h"
#include "cAeropuerto.h"
#include "cFecha.h"


class cVuelo {
public:
	#pragma region constructor y destructor
	/// <summary>
	/// Constructor parametrizado
	/// </summary>
	/// <param name="_PoA">: (true) partida, (false) arribo</param>
	/// <param name="_estado">: Estado del vuelo</param>
	cVuelo(bool _PoA = false, eEstado _estado = sinEstado);
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cVuelo();
	#pragma endregion

	string to_string();
	/* void filtrar(string DNI) {

	}*/

private: 
	static ush numero;
	eEstado estado;
	bool PoA; // Partida O Arribo
	cFecha* vuelo;
	cFecha* destino;
	// cAvion* avion; esperar a que avion este totalmente en funcionamiento
	// cAeropuerto* aeropuerto;

	
};

#endif //_CVUELO_H