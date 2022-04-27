#ifndef _CLISTAPASAJERO_H
#define _CLISTAPASAJERO_H
#include "gbl.h"
#include "cPasajero.h"
class cListaPasajero
{
	friend class cVuelo;
public:
	cListaPasajero(sh size = MAX, bool _checkEliminar = false);
	~cListaPasajero();
	bool agregar(cPasajero* pasajero);
	bool modificar(sh pos, cPasajero* nuevoPasajero);
	bool eliminar(sh pos);
	void ordenar();
	cPasajero* operator[](sh pos) {
		if (pos >= 0 && pos < cPasajero::cantActual)
			return listaPasajero[pos];
		return NULL;
	}
	string to_string();
	void imprimir() { cout << to_string() << endl; }
private:
	bool checkEliminar;
	cPasajero** listaPasajero;
};
#endif // _CLISTAPASAJERO_H