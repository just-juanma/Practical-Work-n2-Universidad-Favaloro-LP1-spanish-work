#ifndef _CLISTAVUELO_H
#define _CLISTAVUELO_H
#include "gbl.h"
#include "cVuelo.h"

class cListaVuelo
{
	
	#pragma region Friend classes 

	friend class cAeropuerto;
	friend class cAvion;

	#pragma endregion

public:

	#pragma region Constructor y destructor

	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="size">Tamanio de la lista, macro MAX por defecto</param>
	/// <param name="_checkEliminar">: La lista se puede eliminar (true), false en caso contrario</param>
	cListaVuelo(sh size = MAX, bool _checkEliminar = false);

	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cListaVuelo();

	#pragma endregion

	#pragma region Metodos

	/// <summary>
	/// Agrega una valija a la lista
	/// </summary>
	/// <param name="pasajero">: Valija a agregar</param>
	/// <returns>True en caso de poder agregarlo, false en caso contrario</returns>
	bool agregar(cVuelo* vuelo);

	/// <summary>
	/// Elimina un pasajero de la lista
	/// </summary>
	/// <param name="pos">: Posicion a eliminar</param>
	/// <returns>True en caso de poder eliminar al pasajero, false en caso contrario</returns>
	bool eliminar(sh pos);

	/// <summary>
	/// Ordenamiento mediante el metodo Bubble Sort mas optimo segun Geeks for Geeks
	/// </summary>	
	void ordenar();

	/// <summary>
	/// Concatena a un solo string los atributos pertinentes
	/// </summary>
	/// <returns>String concatenado</returns>
	string to_string()const;

	/// <summary>
	/// Imprime to_string()
	/// </summary>
	void imprimir()const { cout << to_string() << endl; }

	#pragma endregion

private:

	#pragma region Atributos

	// interno clases
	cVuelo** listaVuelo;

	// interno
	bool checkEliminar;

	#pragma endregion
};

#endif // _CLISTAPASAJERO_H