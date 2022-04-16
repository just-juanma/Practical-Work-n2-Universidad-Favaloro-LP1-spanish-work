#include "gbl.h"
#include "cVuelo.h"
#include "cPasajero.h"
#include "cAvion.h"
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


   /*PRUEBA AVION*/
	cPasajero* pasajero1= new cPasajero("juan", 44789699, 3, 1);
	cPasajero* pasajero2 = new cPasajero("juan", 44789699, 3, 1);
	cAvion* avion1 = new cAvion(15,175);
	cAeropuerto* EZEIZA = new cAeropuerto(1,2, 0, 0,"ezeiza");
	avion1->setAeropuerto(EZEIZA);

	return 0;
}