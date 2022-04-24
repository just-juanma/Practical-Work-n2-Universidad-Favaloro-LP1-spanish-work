#ifndef _CLISTAPASAJERO_H
#define _CLISTAPASAJERO_H
#include "gbl.h"
#include "cPasajero.h"
class cListaPasajero
{
public:
	cListaPasajero(sh size = MAX, bool _checkEliminar = false);
	~cListaPasajero();
	bool agregar(cPasajero* pasajero);
	bool modificar(sh pos, cPasajero* nuevoPasajero);
	bool eliminar(sh pos);
	void ordenar();
	cPasajero* operator[](sh pos) {
		if (pos >= 0)
			return listaPasajero[pos];
		return NULL;
	}
	/* PROBAR DESPUES 
	string to_string();
	void imprimir(); */
private:
	bool checkEliminar;
	cPasajero** listaPasajero;
};
#endif // _CLISTAPASAJERO_H
