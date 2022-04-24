#ifndef _CVALIJA_H
#define _CVALIJA_H
#include "gbl.h"
class cValija
{
	friend class cListaValija;
	friend class cPasajero;
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
	// metodos pedidos por el Trabajo Practico
	string to_string();
	void imprimir();
	#pragma endregion
private:
	static sh cantActual;
	static sh cantTotal;
	float peso;
};

#endif // _CVALIJA_H
