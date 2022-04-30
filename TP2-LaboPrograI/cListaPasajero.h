#ifndef _CLISTAPASAJERO_H
#define _CLISTAPASAJERO_H
#include "gbl.h"
#include "cPasajero.h"

class cListaPasajero
{
	#pragma region Friend classes

	friend class cVuelo;
	
	#pragma endregion

public:

	#pragma region Constructor y destructor

	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="size">Tamanio de la lista, macro MAX por defecto</param>
	/// <param name="_checkEliminar">: La lista se puede eliminar (true), false en caso contrario</param>
	cListaPasajero(sh size = MAX, bool _checkEliminar = false);

	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cListaPasajero();
	
	#pragma endregion

	#pragma region Metodos
	
	/// <summary>
	/// Agrega un pasajero a la lista
	/// </summary>
	/// <param name="pasajero">: Pasajero a agregar</param>
	/// <returns>True en caso de poder agregarlo, false en caso contrario</returns>
	bool agregar(cPasajero* pasajero);

	/// <summary>
	/// Modifica un pasajero de la lista
	/// </summary>
	/// <param name="pos">: Posicion a modificar de la lista</param>
	/// <param name="nuevoPasajero">: Nuevo pasajero</param>
	/// <returns>True en caso de modificarlo, false en caso contrario</returns>
	bool modificar(sh pos, cPasajero* nuevoPasajero);
	
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

	#pragma region Sobrecarga

	/// <summary>
	/// Sobrecarga del operador [] para retornar la posicion de la lista
	/// </summary>
	/// <param name="pos">: Posicion a obtener</param>
	/// <returns>El elemento de la lista en caso de que se pueda obtener, NULL en caso contrario</returns>
	cPasajero* operator[](sh pos) {
		try {
			if (pos >= 0 && pos < cPasajero::cantActual) 
					return listaPasajero[pos];	
			else
				throw "Error: Posicion invalida al sobrecargar el operador [] de la lista de los pasajeros";
		}
		catch (const char* msg) {
			cout << msg << endl;
			return NULL;
		}
	}


private:

	bool isValidDNI(string DNI);

	bool isValidAsiento(sh num);

	#pragma endregion

	#pragma region Atributos

	// interno clases
	cPasajero** listaPasajero;

	// interno
	bool checkEliminar;

	#pragma endregion

};

#endif // _CLISTAPASAJERO_H