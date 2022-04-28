#ifndef _CVUELO_H
#define _CVUELO_H
#include "gbl.h"
#include "cAvion.h"
#include "cAeropuerto.h"
#include "cFecha.h"
#include "cListaPasajero.h"
#include "cPasajero.h"


class cVuelo {
	friend class cListaVuelo;
	friend class cAeropuerto;
	friend class cAvion;
public:
#pragma region constructor y destructor
	/// <summary>
	/// Constructor parametrizado
	/// </summary>
	/// <param name="_PoA">: (true) partida, (false) arribo</param>
	/// <param name="_estado">: Estado del vuelo</param>
	cVuelo(bool _PoA = false, eEstado _estado = sinEstado, ePosiblesDestinos _ciudad = sinDestino);
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cVuelo();
#pragma endregion
	bool agregarPasajero(cPasajero* pasajeroAdd) { 
		if (claselistaPasajero->agregar(pasajeroAdd))
			return true;
		return false;
	}
	bool modificarPasajero(sh pos, cPasajero* nuevoPasajero) { 
		if (claselistaPasajero->modificar(pos, nuevoPasajero))
			return true;
		return false;
	}
	bool eliminarPasajero(sh pos) {
		if (claselistaPasajero->eliminar(pos))
			return true;
		return false;
	}
	cPasajero* filtrar(string* _DNI) {
		if (_DNI) 
			for (ush i = 0; i < cPasajero::cantActual; i++) 
				if (*_DNI == claselistaPasajero->listaPasajero[i]->DNI)
					return claselistaPasajero->listaPasajero[i];
	}
	string to_string() const;
	void setFecha(cFecha* _vuelo, cFecha* _destino) {
		vuelo = _vuelo;
		destino = _destino;
	}
	//float getPesoTotal();
	void setAvion(cAvion* _avion) { this->avion = _avion; }
	void setAeropuerto(cAeropuerto* _aeropuerto) { this->aeropuerto = _aeropuerto; }
	void setEstadoVuelo() {	/*estado = avion->getEstado();*/ }
private:
	static ush numero;
	static sh cantTotal;
	eEstado estado;
	ePosiblesDestinos ciudad;
	bool PoA; // Partida O Arribo
	cFecha* vuelo;
	cFecha* destino;
	cAvion* avion; 
	cAeropuerto* aeropuerto;
	cListaPasajero* claselistaPasajero;
};

ostream& operator << (ostream& out, const cVuelo& _vuelo) { out << _vuelo.to_string(); }

#endif //_CVUELO_H