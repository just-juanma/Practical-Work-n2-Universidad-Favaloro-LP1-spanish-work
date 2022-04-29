#include "gbl.h"
#include "cListaVuelo.h"
#include "cListaAvion.h"
#include "cVuelo.h"
#include "cAvion.h"
#include "cPasajero.h"
#include "cAeropuerto.h"

void sistemaPermisos(cAvion* avion1,cAeropuerto* aeropuerto1);
void setearvuelos(cListaVuelo* vuelos, cAeropuerto* aeropuerto1);
void SeteoAvionAVuelo(cListaVuelo* vuelos, cAeropuerto* aeropuerto1, cListaAvion* aviones, ush nvuelos);

int main() {
		/* PRUEBA PASAJERO Y VALIJA */
	cPasajero* pasajero1 = new cPasajero("Bautista", "448594595", 1, 0);
	cValija* valija1 = new cValija(2);
	cValija* valija2 = new cValija(4);


		 /*PRUEBA AVION*/

	cPasajero* pasajero2 = new cPasajero("juan", "43444444", 123, 12);
	cPasajero* pasajero3 = new cPasajero("juan", "44789699", 3, 1);
	cListaAvion* aviones = new cListaAvion(3);
	cAvion* avion2 = new cAvion(3, 2000, 0, "def");
	cAvion* avion1 = new cAvion(10, 2000, 0, "wrandom");
	cVuelo* vuelo1 = new cVuelo(false, aterrizado, Jerusalen);
	vuelo1->setAvion(avion2);
	vuelo1->setID("def");
	cFecha* fecha1 = new cFecha(1, 1, 2022, 1);
	cFecha* fecha2 = new cFecha(1, 1, 2022, 2);
	vuelo1->setFecha(fecha1, fecha2);
	avion1->setestado(aterrizado);
	avion2->setestado(volando);
	//pasajero1+(objvalija)
	/*Seteo fecha vuelo*/

	/*INICIALIZACION DE AEROPARQUE*/
	aviones->Agregar(avion1);
	aviones->Agregar(avion2);
	cAeropuerto* aeropuerto1 = new cAeropuerto("11", 10, "aeroparque");
	aeropuerto1->setcapacidadAeropuerto(2);
	cListaVuelo* Vuelos = new cListaVuelo(aeropuerto1->getcapacidadAeropuerto(), true);
	Vuelos->agregar(vuelo1);
	aeropuerto1->setListaVuelos(Vuelos);
	aeropuerto1->setHangar(aviones);

	/*SISTEMA DE SETEO DEL AVION AL VUELO*/
	SeteoAvionAVuelo(Vuelos, aeropuerto1, aviones, vuelo1->getCantActual());//remplazar el 1 por el getter de la cantidad de vuelos

   /*SISTEMA DE PERMISOS*/

	sistemaPermisos(avion2, aeropuerto1);
	aviones->Eliminar(0);
	
	system("pause");
	return 0;
}



void sistemaPermisos(cAvion* avion1,cAeropuerto* aeropuerto1) {//que sucede si esta sinestado el avion? OJO
	eEstado estadoActual = avion1->pedirPermiso(); //esto solo devuelve el estado actual del avion
	if (estadoActual == volando) {

		cFecha* aux = new cFecha(19, 11, 2022, 11); //remplazar por una funcion que retorna el tiempo del proximo vuelo
		bool permiso = aeropuerto1->darPermiso(avion1);  //aca se da el permiso y se setea el vuelo
		if (permiso == true)
			avion1->recibirPermiso(aux);	//esto setea al avion una vez que tiene el ok
	}else if (estadoActual == aterrizado){
		cFecha* partida = new cFecha(19, 11, 2022, 11);
		avion1->recibirPermiso(partida);//Ya que el aeropuerto recibe el permiso, el avion chequea por su cuenta si el 
											   // pesoMaximo no fue superado, entonces despega

	}
	else if (estadoActual == sinEstado){
	cout << "nuevito" << endl;
	}
}
 
void setearvuelos(cListaVuelo* vuelos,cAeropuerto* aeropuerto1) {
	aeropuerto1->setListaVuelos(vuelos);
}

void SeteoAvionAVuelo(cListaVuelo* vuelos, cAeropuerto* aeropuerto1, cListaAvion* aviones,ush nvuelos) {
	
	for (int i = 0; i < nvuelos;i++) {
		for (int j = 0; j < cAvion::getnAviones(); j++) {
			if (vuelos[0][i]->getID() == aviones[0][i]->getid()) {
				vuelos[0][i]->setAvion(aviones[0][j]);
			}
		}
	}

}