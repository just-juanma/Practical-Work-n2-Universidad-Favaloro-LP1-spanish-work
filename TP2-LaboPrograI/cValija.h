#ifndef _CVALIJA_H
#define _CVALIJA_H
#include "gbl.h"
class cValija
{

	#pragma region Friend classes

	friend class cListaValija;
	friend class cPasajero;
	friend class cVuelo;
	
	#pragma endregion

public:

	#pragma region Constructor y destructor

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

	#pragma region Metodos

	/// <summary>
	/// Concatena a un solo string los atributos pertinentes
	/// </summary>
	/// <returns></returns>
	string to_string() const;

	/// <summary>
	/// Imprime to_string()
	/// </summary>
	void imprimir() const { cout << to_string() << endl; }

	#pragma endregion

private:

	#pragma region Atributos

	// interno
	float peso;

	#pragma endregion

};

#endif // _CVALIJA_H
