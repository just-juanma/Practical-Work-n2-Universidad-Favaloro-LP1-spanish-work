#ifndef _CVUELO_H
#define _CVUELO_H
#include "gbl.h"
#include "cAvion.h"
#include "cAeropuerto.h"
#include "cFecha.h"
#include "cListaPasajero.h"
#include "cPasajero.h"

class cVuelo {

	#pragma region Friend classes

	friend class cListaVuelo;
	friend class cAeropuerto;
	friend class cAvion;

	#pragma endregion

public:

	#pragma region Constructor y destructor

	/// <summary>
	/// Constructor parametrizado
	/// </summary>
	/// <param name="_PoA">: (true) partida, (false) arribo</param>
	/// <param name="_estado">: Estado del vuelo</param>
	/// <param name="_ciuad">: Ciudad donde se dirige el vuelo</param>
	cVuelo(bool _PoA = false, eEstado _estado = sinEstado, ePosiblesDestinos _ciudad = sinDestino);

	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cVuelo();

	#pragma endregion

	#pragma region Metodos
	
	/// <summary>
	/// Agrega un pasajero a la lista 
	/// </summary>
	/// <param name="pasajeroAdd">: Posible pasajero a agregar</param>
	/// <returns>True en caso de poder agregar el pasajero, false en caso contrario</returns>
	bool agregarPasajero(cPasajero* pasajeroAdd) { 
		// el control de errores se realiza en agregar
		if (claselistaPasajero->agregar(pasajeroAdd))
			return true;
		return false;
	}

	/// <summary>
	/// Modifica un pasajero de la lista
	/// </summary>
	/// <param name="pos">: Posicion del pasajero dentro de la lista a modificar</param>
	/// <param name="nuevoPasajero">: Nuevo pasajero</param>
	/// <returns>True en caso de poder modificar el pasajero, false en caso contrario</returns>
	bool modificarPasajero(sh pos, cPasajero* nuevoPasajero) { 
		// el control de errores se realiza en modificar
		if (claselistaPasajero->modificar(pos, nuevoPasajero))
			return true;
		return false;
	}

	/// <summary>
	/// Elimina un pasajero de la lista
	/// </summary>
	/// <param name="pos">: Posicion del pasajero dentro de la lista a eliminar</param>
	/// <returns>True en caso de poder eliminar al pasajero, false en caso contrario</returns>
	bool eliminarPasajero(sh pos) {
		// el control de errores se realiza en eliminar
		if (claselistaPasajero->eliminar(pos))
			return true;
		return false;
	}

	/// <summary>
	/// Busca a un pasajero por su DNI, y lo retorna en caso de encontrarlo
	/// </summary>
	/// <param name="_DNI">: DNI a comparar con la lista</param>
	/// <returns>El pasajero en caso de encontrarlo, NULL en caso contrario</returns>
	cPasajero* filtrar(string* _DNI) {
		if (_DNI) 
			for (ush i = 0; i < cPasajero::cantActual; i++) 
				if (*_DNI == claselistaPasajero->listaPasajero[i]->DNI)
					return claselistaPasajero->listaPasajero[i];
		return NULL;
	}

	/// <summary>
	/// Concatena a un solo string los atributos pertinentes
	/// </summary>
	/// <returns>String concatenado</returns>
	string to_string() const;

	/// <summary>
	/// Setea las fechas del vuelo
	/// </summary>
	/// <param name="_vuelo">: Fecha y hoario del vuelo</param>
	/// <param name="_destino">: Fecha y horario del destino</param>
	void setFecha(cFecha* _vuelo, cFecha* _destino) {
		vuelo = _vuelo;
		arribo = _destino;
	}

	/// <summary>
	/// Setea el avion asociado al vuelo
	/// </summary>
	/// <param name="_avion">: Avion a setear</param>
	void setAvion(cAvion* _avion) { this->avion = _avion; }

	/// <summary>
	/// Setea el aeropuerto asociado al vuelo
	/// </summary>
	/// <param name="_aeropuerto">: Aeropuerto a setear</param>
	void setAeropuerto(cAeropuerto* _aeropuerto) { this->aeropuerto = _aeropuerto; }

	// consultar bato 
	void setEstadoVuelo() {	/*estado = avion->getEstado();*/ }

	ush cantPasajerosDia() {
		ush cont = 0;
		for (ush i = 0; i < cPasajero::cantActual; i++) 
			if (claselistaPasajero->listaPasajero[i]->fecha->dia == vuelo->dia)
				cont++;
		return cont;
	}

	#pragma endregion

private:

	#pragma region Atributos

	// static
	static ush numero;
	static sh cantTotal;

	// interno clases
	eEstado estado;
	ePosiblesDestinos ciudad;
	cFecha* vuelo;
	cFecha* arribo;
	cAvion* avion; 
	cAeropuerto* aeropuerto;
	cListaPasajero* claselistaPasajero;

	// interno
	bool PoA; // Partida O Arribo

	#pragma endregion
};

#pragma region Sobrecarga

/// <summary>
/// Sobrecarga el operador << para la clase vuelo
/// </summary>
/// <param name="out">: Flujo de salida</param>
/// <param name="_vuelo">: Impresion del vuelo indicado</param>
/// <returns>Nuevo flujo de salida</returns>
ostream& operator << (ostream& out, const cVuelo& _vuelo) { out << _vuelo.to_string(); }

#pragma endregion

#endif //_CVUELO_H