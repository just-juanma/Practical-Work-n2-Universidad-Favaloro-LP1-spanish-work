#include "gbl.h"
#include "cListaVuelo.h"
#include "cListaAvion.h"
#include "cVuelo.h"
#include "cAvion.h"
#include "cPasajero.h"
#include "cAeropuerto.h"

void sistemaOficialDePermisosComunitariosFederales(cAvion* avion1,cAeropuerto* aeropuerto1, cFecha* llegada, cFecha* partida);
void setearvuelos(cListaVuelo* vuelos, cAeropuerto* aeropuerto1);
void SeteoAvionAVuelo(cListaVuelo* vuelos, cAeropuerto* aeropuerto1, cListaAvion* aviones, ush nvuelos);

int main() {

	/* INICIALIZACION AEROPARQUE */

	cAeropuerto* aeropuerto = new cAeropuerto("11", 10, "aeroparque");
	aeropuerto->setcapacidadAeropuerto(2);


	/* INICIALIZACION VUELOS */

	cListaVuelo* vuelos = new cListaVuelo(aeropuerto->getCapacidadAeropuerto(), true);

	cVuelo* vuelo1 = new cVuelo(false, aterrizado, Jerusalen);
	vuelos->agregar(vuelo1);

	cVuelo* vuelo2 = new cVuelo(false, aterrizado, Haifa);
	vuelos->agregar(vuelo2);

	cFecha* salida1 = new cFecha(1, 1, 2022, 1);
	cFecha* llegada1 = new cFecha(1, 1, 2022, 2);
	
	cFecha* salida2 = new cFecha(2, 1, 2022, 1);
	cFecha* llegada2 = new cFecha(2, 1, 2022, 2);

	vuelo1->setFecha(salida1, llegada1);

	vuelo2->setFecha(salida2, llegada2);


	/* INICIALIZACION VALIJAS */

	// equipaje de Vicenta 
	cListaValija* valijasA = new cListaValija(2, true);
	cValija* valija1A = new cValija(10.7);
	cValija* valija2A = new cValija(12.32);

	// equipaje de Teodoro
	cListaValija* valijasB = new cListaValija(1, true);
	cValija* valija1B = new cValija(5);

	// equipaje de Carmen 
	cListaValija* valijasC = new cListaValija(3, true);
	cValija* valija1C = new cValija(0.13);
	cValija* valija2C = new cValija(6);
	cValija* valija3C = new cValija(8.2);

	// equipaje de Carlos 
	cListaValija* valijasD = new cListaValija(2, true);
	cValija* valija1D = new cValija(9.02);
	cValija* valija2D = new cValija(3.5);

	// equipaje de Mauricio
	cListaValija* valijasE = new cListaValija(1, true);
	cValija* valija1E = new cValija(2.5);


	/* INICIALIZACION DE PASAJEROS */
	
	cListaPasajero* pasajerosVuelo1 = new cListaPasajero(4, true);
	cListaPasajero* pasajerosVuelo2 = new cListaPasajero(1, true);

	cPasajero* pasajeroA = new cPasajero("Vicenta", "37549682", 1, 1);
	pasajeroA->setFecha(salida1);
	cPasajero* pasajeroB = new cPasajero("Teodoro", "42589147", 1, 2);
	pasajeroB->setFecha(salida1);
	cPasajero* pasajeroC = new cPasajero("Carmen", "41365214", 1, 3);
	pasajeroC->setFecha(salida1);
	cPasajero* pasajeroD = new cPasajero("Carlos", "44985257", 1, 4);
	pasajeroD->setFecha(salida1);
	cPasajero* pasajeroE = new cPasajero("Mauricio", "41258971", 2, 1);
	pasajeroE->setFecha(salida2);

	/* AGREGAR VALIJAS A CADA PASAJERO */

	pasajeroA->setLista(valijasA);
	*pasajeroA + *valija1A;
	*pasajeroA + *valija2A;
	valijasA->imprimir();

	pasajeroB->setLista(valijasB);
	*pasajeroB + *valija1B;
	valijasB->imprimir();

	pasajeroC->setLista(valijasC);
	*pasajeroC + *valija1C;
	*pasajeroC + *valija2C;
	*pasajeroC + *valija3C;
	*pasajeroC - *valija2C;
	valijasC->imprimir();

	pasajeroD->setLista(valijasD);
	*pasajeroD + *valija1D;
	*pasajeroD + *valija2D;
	valijasD->imprimir();

	pasajeroE->setLista(valijasE);
	*pasajeroE + *valija1E;
	valijasD->imprimir();
	

	/* AGREGAR PASAJEROS AL VUELO */

	vuelo1->setListaPasajero(pasajerosVuelo1);

	vuelo1->agregarPasajero(pasajeroA);
	vuelo1->agregarPasajero(pasajeroB);
	vuelo1->agregarPasajero(pasajeroC);
	vuelo1->agregarPasajero(pasajeroD);

	vuelo2->setListaPasajero(pasajerosVuelo2);
	vuelo2->agregarPasajero(pasajeroE);

	pasajerosVuelo1[0][0]->imprimir();


	/* INICIALIZACION AVIONES */

	cListaAvion* aviones = new cListaAvion(3);

	cAvion* avion1 = new cAvion(10, 2000, 0, "wrandom");
	cAvion* avion2 = new cAvion(4, 2000, 0, "def");
	cAvion* avion3 = new cAvion(2, 2000, 0, "El Macho");

	avion1->setestado(aterrizado);
	avion2->setestado(volando);
	avion3->setestado(volando);

	/* ASIGNACION DE AVIONES A LA LISTA */
	//La lista de aviones recibe todos los aviones, quienes estan volando y quienes estan aterrizados
	aviones->Agregar(avion1);
	aviones->Agregar(avion2);
	aviones->Agregar(avion3);
	/* ASIGNACION DE AVIONES AL VUELO */

	vuelo1->setAvion(avion2);
	vuelo1->setID("def");

	vuelo2->setAvion(avion3);
	vuelo2->setID("El Macho");

	cout << vuelo1;

	cout << "La cantidad de pasajeros que volaron en el dia fueron: " << vuelos->cantPasajerosDia(salida1) << endl;

	/* ASGINACION DE VUELOS Y AVIONES AL AEROPUERTO */

	aeropuerto->setListaVuelos(vuelos);
	aeropuerto->setAvionesAeropuerto(aviones);

	/* SISTEMA DE SETEO DEL AVION AL VUELO */

	SeteoAvionAVuelo(vuelos, aeropuerto, aviones, vuelo1->getCantActual());

    /* SISTEMA INTERNACIONAL OFICIAL DE PERMISOS AEROPORTUARIOS COMUNITARIOS FEDERALES */

	sistemaOficialDePermisosComunitariosFederales(avion2, aeropuerto, llegada1, salida1);

	sistemaOficialDePermisosComunitariosFederales(avion3, aeropuerto, llegada2, salida2);

	aviones->Listar();

	cout << "La cantidad de vuelos que despegaron y aterrizaron en el dia fueron: " << aeropuerto->cantAterrizadosDia(salida1) << endl;

	cout << "El porcentaje de vuelos que despegaron y aterrizaron en horario fueron: " << aeropuerto->porcentajeHorarioPartida() << "%" << endl;

	delete salida1; delete llegada1;
	delete avion1; delete avion2;
	delete vuelo1;
	delete aeropuerto;
	delete valija1A, delete valija2A;
	delete valija1B;
	delete valija1C; delete valija3C;
	delete valija1D; delete valija2D;
	delete pasajeroA; delete pasajeroB; delete pasajeroC; delete pasajeroD;

	system("pause");
	return 0;
}

void sistemaOficialDePermisosComunitariosFederales(cAvion* avion1,cAeropuerto* aeropuerto1, cFecha* llegada, cFecha* partida) {//que sucede si esta sinestado el avion? OJO
	try
	{
		if (avion1 == NULL || aeropuerto1 == NULL) throw "AVION_O_AEROPUERTO_NULL";
		eEstado estadoActual = avion1->pedirPermiso(); //esto solo devuelve el estado actual del avion
		if (estadoActual == volando) {
			bool permiso = aeropuerto1->darPermiso(avion1);  //aca se da el permiso y se setea el vuelo
			if (permiso == true)
				avion1->recibirPermiso(llegada, partida); //esto setea al avion una vez que tiene el ok

		}
		else if (estadoActual == aterrizado) {
			try {
				avion1->recibirPermiso(llegada, partida);//Ya que el aeropuerto recibe el permiso, el avion chequea por su cuenta si el 
											// pesoMaximo no fue superado, entonces despega
			}
			catch (const char* msg) {
				cout << msg << endl;
				cout << "Este avion no puede volar... Por favor verifique sus pasajeros!" << endl;
			}
		}
		else if (estadoActual == sinEstado) {
			cout << "Este avion no deberia estar volando... Por favor verifique sus parametros elementales!" << endl;
			abort();
		}
	}
	catch (const char& msg)
	{
		cout << msg << endl;
	}
	
}
 
void setearvuelos(cListaVuelo* vuelos,cAeropuerto* aeropuerto1) {
	try
	{
		if (vuelos == NULL || aeropuerto1 == NULL) throw "VUELOS_O_AEROPUERTO_NULL";
		aeropuerto1->setListaVuelos(vuelos);
	}
	catch (const char& msg)
	{
		cout << msg << endl;
	}
	

}

void SeteoAvionAVuelo(cListaVuelo* vuelos, cAeropuerto* aeropuerto1, cListaAvion* aviones,ush nvuelos) {
	try
	{
		if (vuelos == NULL || aeropuerto1 == NULL || aviones == NULL) throw "VUELOS_O_AEROPUERTO_O_AVIONES_NULL";
		for (int i = 0; i < nvuelos; i++) {
			for (int j = 0; j < cAvion::getnAviones(); j++) {
				if (vuelos[0][i]->getID() == aviones[0][i]->getid()) {
					vuelos[0][i]->setAvion(aviones[0][j]);
				}
			}
		}
	}
	catch (const char& msg)
	{
		cout << msg << endl;
	}

}