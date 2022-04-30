#ifndef _CLISTAVALIJA_H
#define _CLISTAVALIJA_H
#include "gbl.h"
#include "cValija.h"

class cListaValija
{

	#pragma region Friend classes

	friend class cPasajero;
	
	#pragma endregion

public:

	#pragma region Constructor y destructor

	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="size">Tamanio de la lista, macro MAX por defecto</param>
	/// <param name="_checkEliminar">: La lista se puede eliminar (true), false en caso contrario</param>
	cListaValija(sh size = MAX, bool _checkEliminar = false);

	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cListaValija();

	#pragma endregion

	#pragma region Metodos

	/// <summary>
	/// Agrega una valija a la lista
	/// </summary>
	/// <param name="pasajero">: Valija a agregar</param>
	/// <returns>True en caso de poder agregarlo, false en caso contrario</returns>
	bool agregar(cValija* valija);

	/// <summary>
	/// Elimina una valija de la lista
	/// </summary>
	/// <param name="valija">: Valija a eliminar</param>
	/// <returns>True en caso de poder eliminar al pasajero, false en caso contrario</returns>
	bool eliminar(cValija* valija);

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
	cValija** listaValija;

	// interno
	bool checkEliminar;
	sh cantActual;
	sh cantTotal;

	#pragma endregion
};

#endif // _CLISTAVALIJA_H
