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
    cPasajero(string _nombre, unsigned int _DNI);
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
    /// Permite al pasajero retirar su equipaje
    /// </summary>
    /// <returns>El equipaje en cuestion</returns>
    cValija* retirarEquipaje();
    #pragma endregion
private: 
    // datos del pasajero
    const string nombre;
    const unsigned int DNI;
    static unsigned int numeroAsiento;
    unsigned int numeroVuelo;
    // equipaje del pasajero
    cValija** listaValija;
    unsigned int nValijas;
    unsigned int nValijaRetirada;
    double pesoTotal;
    // medio por el cual obtengo el numero de vuelo
    cVuelo* vuelo;

};

#endif // _CPASAJERO_H