#ifndef _CPASAJERO_H
#define _CPASAJERO_H
#include "gbl.h"
#include "cVuelo.h"
#include "cValija.h"
class cPasajero {
public: 
    #pragma region constructor y destructor
    /// <summary>
    /// Constructor parametrizado
    /// </summary>
    /// <param name="_nombre">: Nombre del pasajero</param>
    /// <param name="_DNI">: DNI del pasajero</param>
    cPasajero(string _nombre, unsigned int _DNI, unsigned int _nAsiento, unsigned int _nVuelo);
    /// <summary>
    /// Destructor por defecto
    /// </summary>
    ~cPasajero();
    #pragma endregion 
    
    #pragma region metodos
    /// <summary>
    /// Trata de agregar una valija a la lista de valijas
    /// </summary>
    /// <param name="posibleValija">: posible valija a agregar</param>
    /// <returns>True en caso de ser posible, false en caso contrario</returns>
    bool agregarEquipaje(cValija* posibleValija);
    /// <summary>
    /// Retira el equipaje para posteriormente eliminarlo
    /// </summary>
    /// <param name="nEquipaje">: posicion de valija a quitar</param>
    /// <returns>El equipaje en cuestion</returns>
    cValija* retirarEquipaje(unsigned int nEquipaje);
    /// <summary>
    /// Elimina el elemento mediante el destructor
    /// </summary>
    /// <param name="nEquipaje">: posicion a eliminar</param>
    /// <returns></returns>
    bool eliminarEquipaje(unsigned int nEquipaje);
    #pragma endregion
private: 
    // datos del pasajero
    const string nombre;
    const unsigned int DNI;
    unsigned int nAsiento;
    unsigned int nVuelo;
    // equipaje del pasajero
    cValija** listaValija;
    unsigned int nValijas;
    double pesoTotal;
    // medio por el cual obtengo el numero de vuelo
    cVuelo* vuelo;

};

#endif // _CPASAJERO_H