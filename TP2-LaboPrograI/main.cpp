#include "gbl.h"
#include "cListaVuelo.h"
#include "cListaAvion.h"
#include "cVuelo.h"
#include "cAvion.h"
#include "cPasajero.h"
#include "cAeropuerto.h"

void sistemaPermisos(cAvion* avion1,cAeropuerto* aeropuerto1);
void setearvuelos(cListaVuelo* vuelos, cAeropuerto* aeropuerto1);

int main() {
//
//	/* PRUEBA VUELO */
//
//
//
//
//	//PRUEBA PASAJERO Y VALIJA
//   /*cValija* valijaRetirada;
//   cPasajero* pasajero1 = new cPasajero("juan", 44789699, 3, 1);
//   cValija* valija1 = new cValija(4.3);
//   pasajero1->agregarEquipaje(valija1);
//   cValija* valija2 = new cValija(7.8);
//   pasajero1->agregarEquipaje(valija2);
//   pasajero1->eliminarEquipaje(1);
//   pasajero1->eliminarEquipaje(0);
//   delete valija1;
//   delete valija2;
//   delete pasajero1;*/
//	
//
//   /*PRUEBA AVION*/
	cPasajero* pasajero1= new cPasajero("juan","43444444",123,12);
	cPasajero* pasajero2 = new cPasajero("juan", "44789699", 3, 1);
	cListaAvion* aviones = new cListaAvion(3);
	cAvion* avion2 = new cAvion(3,2000,0,"def");
	cAvion* avion1 = new cAvion(10, 2000, 0, "wrandom");
	cVuelo* vuelo1 = new cVuelo(false, aterrizado, Jerusalen);
	
	/*INICIALIZACION DE AEROPARQUE*/
	cAeropuerto* aeropuerto1 = new cAeropuerto("11",10,"aeroparque");
	aeropuerto1->setcapacidadAeropuerto(2);
	cListaVuelo* Vuelos = new cListaVuelo(aeropuerto1->getcapacidadAeropuerto(), true);
	
	aeropuerto1->setListaVuelos(Vuelos);
	/*SISTEMA DE PERMISOS*/

	sistemaPermisos(avion1, aeropuerto1);

	return 0;
}

void sistemaPermisos(cAvion* avion1,cAeropuerto* aeropuerto1) {
	eEstado estadoActual = avion1->pedirPermiso(); //esto solo devuelve el estado actual del avion
	if (estadoActual == volando) {

		cFecha* aux = new cFecha(19, 11, 2001, 11);
		bool permiso = aeropuerto1->darPermiso(avion1);  //aca se da el permiso y se setea el vuelo
		if (permiso == true)
			avion1->recibirPermiso(aux);	//esto setea al avion una vez que tiene el ok
	}
	else
	{
		cFecha* partida = new cFecha(19, 11, 2001, 11);
		avion1->recibirPermiso(partida);//Ya que el aeropuerto recibe el permiso, el avion chequea por su cuenta si el 
											   // pesoMaximo no fue superado, entonces despega

	}
}
 
void setearvuelos(cListaVuelo* vuelos,cAeropuerto* aeropuerto1) {
	aeropuerto1->setListaVuelos(vuelos);
}