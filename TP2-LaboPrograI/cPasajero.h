#ifndef _CPASAJERO_H
#define _CPASAJERO_H
#include "gbl.h"
#include "cVuelo.h"
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


    //bool agregarEquipaje();
    
    //bool retirarEquipaje();

    #pragma endregion
private: 
    cVuelo vuelo;
    unsigned int numeroVuelo;
    const string nombre;
    const unsigned int DNI;
    static unsigned int numeroAsiento;
};

#endif // _CPASAJERO_H