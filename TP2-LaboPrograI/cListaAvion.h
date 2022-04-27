#pragma once
// incluir header global, sacar pragma once y hacerlo con IFNDEF
#include "cAvion.h"
class cListaAvion
{
	friend class cAvion;
public:

	cListaAvion();
	cListaAvion(int L);
	~cListaAvion();
	void ordenar();
	bool Agregar(cAvion* cubo); 	 //retorna true si fue un éxito 
	cAvion* Quitar(sh posición);	 //NULL o puntero al dato quitado
	bool Eliminar(sh posición); 	 //retorna true si fue un éxito 
	cAvion* operator[](int posic_i);//retorna puntero a i-esimo dato
	int Buscar(string _id);	             //la clave con la que se busca el avion es ID, ya que es un identificador unico y que devuelva
										 // el ID
	void Listar();			//imprime la lista en pantalla

private:
	cAvion** Lista;
	unsigned int ocupados;
	unsigned int capacidad;
};