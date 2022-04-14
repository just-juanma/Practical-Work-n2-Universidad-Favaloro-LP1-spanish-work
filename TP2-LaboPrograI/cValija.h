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
	/// <param name="_peso">Recibira un peso (en kilogramos). El peso promedio de una valija es de 2.5 kilogramos </param>
	cValija(double _peso = 2.5);
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cValija();
	#pragma endregion

	#pragma region metodos
	/// <summary>
	/// Retorna el peso de la valija
	/// </summary>
	/// <returns>Peso de la valija</returns>
	double getPeso()const {
		return peso;
	}


	string to_string();
	string imprimir();

	#pragma endregion
private:
	double peso;
};

#endif // _CVALIJA_H
