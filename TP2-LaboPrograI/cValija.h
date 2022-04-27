#ifndef _CVALIJA_H
#define _CVALIJA_H
#include "gbl.h"
class cValija
{
	friend class cListaValija;
	friend class cPasajero;
	friend class cVuelo;
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
	// Impresion de datos
	string to_string() const;
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
