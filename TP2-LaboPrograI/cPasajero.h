#ifndef _CPASAJERO_H
#include "gbl.h"
#define _CPASAJERO_H

class cPasajero {
public: 
    #pragma region constructor y destructor
    /// <summary>
    /// Constructor por defecto
    /// </summary>
    cPasajero();
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
    const string nombre;
    const unsigned int DNI;
    unsigned int numeroDeVuelo;
};

#endif // _CPASAJERO_H