#pragma once
// incluir header global, sacar pragma once y hacerlo con IFNDEF
#include "cAvion.h"
class cListaAvion
{
	friend class cAvion;
	friend class cAeropuerto;
public:

	cListaAvion();
	cListaAvion(int L=MAX);
	~cListaAvion();
	/// <summary>
	/// organizar la lista con el algoritmo buble sort
	/// </summary>
	void ordenar();
	/// <summary>
	/// Se agrega el elemento avion a las lista de aviones
	/// </summary>
	/// <param name="avion">Puntero a un objeto de tipo cAvion</param>
	/// <returns>Devuelve true si fue exitoso</returns>
	bool Agregar(cAvion* avion); 	
	/// <summary>
	/// Retira el objeto de la lista
	/// </summary>
	/// <param name="posición"></param>
	/// <returns>Devuelve el objeto solicitado</returns>
	cAvion* Quitar(ush posición);	
	/// <summary>
	/// Elimina el objeto solicitado
	/// </summary>
	/// <param name="posición"></param>
	/// <returns>Devuelve true si fue exitoso</returns>
	bool Eliminar(sh posición); 	 //retorna true si fue un éxito 
	/// <summary>
	/// Con doble corchete "accedo" a la i-esima posicion de la lista
	/// </summary>
	/// <param name="posic_i"></param>
	/// <returns>Devuelve el puntero de la posicion solicitada en la lista</returns>
	cAvion* operator[](int posic_i);//retorna puntero a i-esimo dato
	/// <summary>
	/// Busca el avion solicitado mediante el ID del mismo
	/// </summary>
	/// <param name="_id"></param>
	/// <returns>La posicion en que se encuentra ese objeto</returns>
	int Buscar(string _id);	             //la clave con la que se busca el avion es ID, ya que es un identificador unico y que devuelva
										 // el ID
	
	/// <summary>
	/// imprime en pantalla toda la lista
	/// </summary>
	void Listar();			//imprime la lista en pantalla



private:
	cAvion** ListaAviones;
	unsigned int MetidosEnLista;
	unsigned int capacidad;

};