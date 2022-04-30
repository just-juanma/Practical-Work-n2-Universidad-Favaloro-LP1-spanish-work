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

	cListaValija* valijasPasajero1 = new cListaValija(2, true);

	pasajero1->setLista(valijasPasajero1);

	cValija* valija1 = new cValija(2);
	*pasajero1 + *valija1;

	cValija* valija2 = new cValija(4);
	*pasajero1 + *valija2;

	

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
	aeropuerto1->setAvionesAeropuerto(aviones);

	/*SISTEMA DE SETEO DEL AVION AL VUELO*/
	SeteoAvionAVuelo(Vuelos, aeropuerto1, aviones, vuelo1->getCantActual());//remplazar el 1 por el getter de la cantidad de vuelos

    /*SISTEMA INTERNACIONAL OFICIAL DE PERMISOS AEROPORTUARIOS*/
	sistemaPermisos(avion2, aeropuerto1);
	aviones->Listar();
	system("pause");

	delete fecha1; delete fecha2;
	delete avion1; delete avion2;
	delete pasajero1; delete pasajero2; delete pasajero3;
	delete vuelo1;
	delete aeropuerto1;
	//delete[] aviones; delete[] Vuelos; estas dos lineas de codigo, rompen el destructor de las clases, porque 
	//liberan memoria que se va a comprobar que se use

	return 0;
}



void sistemaPermisos(cAvion* avion1,cAeropuerto* aeropuerto1,cFecha* llegada, cFecha* partida) {//que sucede si esta sinestado el avion? OJO
	eEstado estadoActual = avion1->pedirPermiso(); //esto solo devuelve el estado actual del avion
	if (estadoActual == volando) {
		bool permiso = aeropuerto1->darPermiso(avion1);  //aca se da el permiso y se setea el vuelo
		if (permiso == true)
			avion1->recibirPermiso(llegada,partida); //esto setea al avion una vez que tiene el ok

	}else if (estadoActual == aterrizado){
		try {
			avion1->recibirPermiso(llegada,partida);//Ya que el aeropuerto recibe el permiso, el avion chequea por su cuenta si el 
										// pesoMaximo no fue superado, entonces despega
		}
		catch (const char* msg) {
			cout << msg << endl;
			cout << "Este avion no puede volar... Por favor verifique sus pasajeros!" << endl;
		}
	}
	else if (estadoActual == sinEstado){
	cout << "Este avion no deberia estar volando... Por favor verifique sus parametros elementales!" << endl;
	abort();
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