/*
Solamente nos interesa el peso de la valija, y se encuentra en la presente clase
*/
#ifndef _CVALIJA_H
#define _CVALIJA_H
#include "gbl.h"
class cValija
{

	#pragma region friend classes

	friend class cListaValija;
	friend class cPasajero;
	friend class cVuelo;
	
	#pragma endregion

public:

	#pragma region constructor y destructor

	/// <summary>
	/// Constructor parametrizado
	/// </summary>
	/// <param name="_peso">Recibira un peso (en kilogramos) </param>
	cValija(float _peso = 0);
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cValija();

	#pragma endregion

	#pragma region metodos

	/// <summary>
	/// Concatena a un solo string los atributos pertinentes a la fecha
	/// </summary>
	/// <returns></returns>
	string to_string() const;

	/// <summary>
	/// Imprime to_string()
	/// </summary>
	void imprimir() const { cout << to_string() << endl; }

	#pragma endregion

private:

	// static
	static ush cantActual;
	static sh cantTotal;

	// interno de la clase
	float peso;

};

#endif // _CVALIJA_H
