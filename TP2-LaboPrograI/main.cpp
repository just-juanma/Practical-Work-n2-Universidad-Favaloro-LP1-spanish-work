#include "gbl.h"
#include "cVuelo.h"
#include "cPasajero.h"
int main() {
	/* PRUEBA VUELO */

	cVuelo::setDestinosPosibles();

	
	
	cVuelo::eliminarLista();

	
	 //PRUEBA PASAJERO Y VALIJA
	/*cValija* valijaRetirada;
	cPasajero* pasajero1 = new cPasajero("juan", 44789699, 3, 1);
	cValija* valija1 = new cValija(4.3);
	pasajero1->agregarEquipaje(valija1);
	cValija* valija2 = new cValija(7.8);
	pasajero1->agregarEquipaje(valija2);
	pasajero1->eliminarEquipaje(1);
	pasajero1->eliminarEquipaje(0);
	delete valija1;
	delete valija2;
	delete pasajero1;*/
	
	return 0;
}