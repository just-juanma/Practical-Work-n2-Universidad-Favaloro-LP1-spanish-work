//#include "gbl.h"
//#include "cVuelo.h"
//#include "cPasajero.h"
//#include "cListaAvion.h"
//#include "cAvion.h"
//int main() {
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
//	/*cPasajero* pasajero1= new cPasajero("juan", 44789699, 3, 1);
//	cPasajero* pasajero2 = new cPasajero("juan", 44789699, 3, 1);
//	cAvion* avion1 = new cAvion(15,175);*/
//	cListaAvion aviones = cListaAvion(3);
//	cListaPasajero pasajeros = cListaPasajero(10,true);
//	cAvion* avion1 = new cAvion(3,2000,0,"def");
//	aviones.Agregar(avion1);
//	//cAeropuerto* EZEIZA = new cAeropuerto(1,2, 0, 0,"ezeiza");
//	//avion1->setAeropuerto(EZEIZA);
//
//	/*SISTEMA DE PERMISOS*/
//	eEstado estadoActual = avion1->pedirPermiso(); //esto solo devuelve el estado actual del avion
//	if (estadoActual == volando)
//	{
//		bool permiso = aeropuerto1.darPermiso();  //aca se da el permiso y se setea el vuelo
//		if (permiso == true)
//			avion1->recibirPermiso();	//esto setea al avion una vez que tiene el ok
//										//Aca solo se setea el avion no el vuelo OJOOOO
// }
//  else
//  {
//		avion1->recibirPermiso(cFecha partida);//Ya que el aeropuerto recibe el permiso, el avion chequea por su cuenta si el 
//								               // pesoMaximo no fue superado, entonces despega
//		aca se maneja el despegue
//  }
//	
//	return 0;
//}