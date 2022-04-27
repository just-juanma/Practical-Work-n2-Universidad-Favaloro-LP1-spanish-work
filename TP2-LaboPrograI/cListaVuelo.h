#ifndef _CLISTAVUELO_H
#define _CLISTAVUELO_H
#include "gbl.h"
#include "cVuelo.h"
class cListaVuelo
{
	friend class cAvion;
public:
	cListaVuelo(sh size = MAX, bool _checkEliminar = false);
	~cListaVuelo();
	bool agregar(cVuelo* vuelo);
	bool eliminar(sh pos);
	void ordenar();
	string to_string();
	void imprimir() { cout << to_string() << endl; }
private:
	bool checkEliminar;
	cVuelo** listaVuelo;
};
#endif // _CLISTAPASAJERO_H