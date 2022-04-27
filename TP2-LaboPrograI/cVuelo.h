#ifndef _CVUELO_H
#define _CVUELO_H
#include "gbl.h"
#include "cAvion.h"
#include "cAeropuerto.h"
#include "cListaPasajero.h"
#include "cPasajero.h"
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

	cPasajero* filtrar(string* _DNI, cListaPasajero* _lista) {
		if (_DNI) 
			for (ush i = 0; i < cPasajero::cantActual; i++) 
				if (*_DNI == _lista->listaPasajero[i]->DNI)
					return _lista->listaPasajero[i];
	}
	string to_string();
	void imprimir() { cout << to_string() << endl; }
	void setFecha(cFecha* _vuelo, cFecha* _destino) {
		vuelo = _vuelo;
		destino = _destino;
	}
	float pesoTotal(cListaPasajero* _lista) {
		float pesoValijasVuelo = 0;
		if (_lista) {
			for (ush i = 0; i < cPasajero::cantActual; i++) {
				pesoValijasVuelo += _lista->listaPasajero[i]->pesoTotalEquipaje->peso;
				/* if(_lista->listaPasajero[i]->numeroVuelo >= numero ||
					  _lista->listaPasajero[i]->numeroVuelo != avion->getNumeroVuelo() ||
				      avion->getNumeroVuelo() <= numero ||
					  pesoValijasVuelo < avion->getPesoHumano()) {
						pesoValijasVuelo -= _lista->listaPasajero[i]->pesoTotalEquipaje->peso; 
							if(					  
					  
					  }


				*/
			}

		}
	}
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