#pragma once
#include "cAvion.h"
class cListaAvion
{
	
public:

	cListaAvion();
	cListaAvion(int L);
	~cListaAvion();
	void ordenar();
	bool Agregar(cAvion* cubo); 	 //retorna true si fue un �xito 
	cAvion* Quitar(sh posici�n);	 //NULL o puntero al dato quitado
	bool Eliminar(sh posici�n); 	 //retorna true si fue un �xito 
	cAvion* operator[](int posic_i);//retorna puntero a i-esimo dato
	int Buscar(string _id);	             //la clave con la que se busca el avion es ID, ya que es un identificador unico
	void Listar();			//imprime la lista en pantalla

private:
	cAvion** Lista;
	unsigned int ocupados;
	unsigned int capacidad;
	friend class cAvion;
};
