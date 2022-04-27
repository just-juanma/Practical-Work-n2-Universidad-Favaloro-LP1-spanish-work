#ifndef _CLISTAVALIJA_H
#define _CLISTAVALIJA_H
#include "gbl.h"
#include "cValija.h"
class cListaValija
{
	friend class cPasajero;
public:
#pragma region constructor y destructor
	cListaValija(sh size = MAX, bool _checkEliminar = false);
	~cListaValija();
#pragma endregion

#pragma region metodos
	bool agregar(cValija* valija);
	bool eliminar(cValija* valija);
	void ordenar();
	// Impresion de datos
	string to_string() const;
	void imprimir() const { cout << to_string() << endl; }
#pragma endregion

private:
	bool checkEliminar;
	cValija** listaValija;
};
#endif // _CLISTAVALIJA_H
