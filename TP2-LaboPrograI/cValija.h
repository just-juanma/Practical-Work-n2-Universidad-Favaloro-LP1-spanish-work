#ifndef _CVALIJA_H
#define _CVALIJA_H
#include "gbl.h"
class cValija
{
public:
	#pragma region constructor y destructor
	/// <summary>
	/// Constructor parametrizado
	/// </summary>
	/// <param name="_peso">Recibira un peso (en kilogramos) </param>
	cValija(double _peso = 0);
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cValija();
	#pragma endregion

	#pragma region getters y setters
	/// <summary>
	/// Retorna el peso de la valija
	/// </summary>
	/// <returns>Peso de la valija</returns>
	double getPeso()const {
		return peso;
	}

	#pragma enderegion
	
	#pragma region metodos
	// metodos pedidos por el Trabajo Practico
	string to_string();
	void imprimir();
	#pragma endregion
private:
	// local
	double peso;
};

#endif // _CVALIJA_H
