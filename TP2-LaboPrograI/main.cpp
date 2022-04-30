#include "gbl.h"
#include "cListaVuelo.h"
#include "cListaAvion.h"
#include "cVuelo.h"
#include "cAvion.h"
#include "cPasajero.h"
#include "cAeropuerto.h"

void sistemaOficialDePermisosComunitariosFederales(cAvion* avion1,cAeropuerto* aeropuerto1);
void setearvuelos(cListaVuelo* vuelos, cAeropuerto* aeropuerto1);
void SeteoAvionAVuelo(cListaVuelo* vuelos, cAeropuerto* aeropuerto1, cListaAvion* aviones, ush nvuelos);

int main() {

	/* INICIALIZACION AEROPARQUE */

	cAeropuerto* aeropuerto = new cAeropuerto("11", 10, "aeroparque");
	aeropuerto->setcapacidadAeropuerto(2);

	/* INICIALIZACION VUELOS */

	cListaVuelo* Vuelos = new cListaVuelo(aeropuerto->getcapacidadAeropuerto(), true);

	cVuelo* vuelo1 = new cVuelo(false, aterrizado, Jerusalen);

	cFecha* salida = new cFecha(1, 1, 2022, 1);
	cFecha* llegada = new cFecha(1, 1, 2022, 2);

	vuelo1->setFecha(salida, llegada);

	/* INICIALIZACION VALIJAS */

	// equipaje de Vicenta 
	cListaValija* valijasA = new cListaValija(2, true);
	cValija* valija1A = new cValija(10);
	cValija* valija2A = new cValija(12);

	// equipaje de Teodoro

	// equipaje de Carmen 

	// equipaje de Carlos 

	/* INICIALIZACION DE PASAJEROS */
	
	cListaPasajero* pasajerosVuelo1 = new cListaPasajero(1, true);

	cPasajero* pasajeroA = new cPasajero("Vicenta", "448594595", 1, 1);

	/* AGREGAR VALIJAS A CADA PASAJERO */

	pasajeroA->setLista(valijasA);

	*pasajeroA + *valija1A;
	*pasajeroA + *valija2A;

	/* AGREGAR PASAJEROS AL VUELO */

	vuelo1->setListaPasajero(pasajerosVuelo1);

	vuelo1->agregarPasajero(pasajeroA);

	/* INICIALIZACION AVIONES */

	cListaAvion* aviones = new cListaAvion(3);

	cAvion* avion1 = new cAvion(10, 2000, 0, "wrandom");
	cAvion* avion2 = new cAvion(3, 2000, 0, "def");

	avion1->setestado(aterrizado);
	avion2->setestado(volando);

	/* ASIGNACION DE AVIONES A LA LISTA */

	aviones->Agregar(avion1);
	aviones->Agregar(avion2);
	
	/* ASIGNACION DE AVIONES AL VUELO */

	vuelo1->setAvion(avion2);
	vuelo1->setID("def");

	/* ASIGNACION DE VUELOS A LA LISTA */

	Vuelos->agregar(vuelo1);

	/* ASGINACION DE VUELOS Y AVIONES AL AEROPUERTO */

	aeropuerto->setListaVuelos(Vuelos);
	aeropuerto->setAvionesAeropuerto(aviones);

	/* SISTEMA DE SETEO DEL AVION AL VUELO */

	SeteoAvionAVuelo(Vuelos, aeropuerto, aviones, vuelo1->getCantActual());//remplazar el 1 por el getter de la cantidad de vuelos

    /* SISTEMA INTERNACIONAL OFICIAL DE PERMISOS AEROPORTUARIOS COMUNITARIOS FEDERALES */

	sistemaOficialDePermisosComunitariosFederales(avion2, aeropuerto);
	aviones->Listar();

	delete salida; delete llegada;
	delete avion1; delete avion2;
	delete vuelo1;
	delete aeropuerto;
	//delete[] aviones; delete[] Vuelos; estas dos lineas de codigo, rompen el destructor de las clases, porque 
	//liberan memoria que se va a comprobar que se use

	system("pause");
	return 0;
}



void sistemaOficialDePermisosComunitariosFederales(cAvion* avion1,cAeropuerto* aeropuerto1) {//que sucede si esta sinestado el avion? OJO
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