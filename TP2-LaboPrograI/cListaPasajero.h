#ifndef _CLISTAPASAJERO_H
#define _CLISTAPASAJERO_H
#include "gbl.h"
#include "cPasajero.h"
class cListaPasajero
{
public:
	cListaPasajero(ush size = MAX, bool _checkEliminar = false);
	~cListaPasajero();
	bool agregar(cPasajero* pasajero);
	bool modificar(short pos, cPasajero* nuevoPasajero);
	bool eliminar(short pos);
	void ordenar();
	/* PROBAR DESPUES 
	string to_string();
	void imprimir(); */
private:
	bool checkEliminar;
	cPasajero** listaPasajero;
};
#endif // _CLISTAPASAJERO_H
