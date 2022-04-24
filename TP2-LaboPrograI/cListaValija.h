#ifndef _CLISTAVALIJA_H
#define _CLISTAVALIJA_H
#include "gbl.h"
#include "cValija.h"
class cListaValija
{
	friend class cPasajero;
public:
	cListaValija(sh size = MAX, bool _checkEliminar = false);
	~cListaValija();
	bool agregar(cValija* valija);
	bool eliminar(sh pos);
	void ordenar();
private:
	bool checkEliminar;
	cValija** listaValija;
};
#endif // _CLISTAVALIJA_H
