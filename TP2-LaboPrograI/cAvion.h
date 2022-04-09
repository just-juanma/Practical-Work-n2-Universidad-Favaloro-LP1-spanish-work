#ifndef _CAVION_H
#include "gbl.h"
#define _CAVION_H

class cAvion {
public: 
    #pragma region constructor y destructor 

        /// <summary>
        /// Constructor parametrizado
        /// </summary>
        /// <param name="_totalPasajeros">Capacidad maxima que permite el avion</param>
        /// <param name="_pesoMaximo">Peso maximo que permite el avion</param>
        /// <param name="_nPasajeros">Cantidad actual de pasajeros</param>
        cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros);
        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cAvion();

    #pragma endregion 

    #pragma region metodos

        /// <summary>
        /// Depegue del avion. Esto implica que
        ///         En cuanto al pasajero:
        ///       - La fecha y el numero de vuelo del pasajero deja de ser valida
        ///         En cuanto al vuelo:
        ///       - Debe cambiar el estado del vuelo
        ///         En
        /// </summary>
        //void despegar();

        /// <summary>
        /// Aterrizaje del avion. Esto implica que:
        ///       1. Debe cambiar el estado del vuelo
        /// </summary>
        //void aterrizar();

        // void pedirPermiso();
        // void chequearCargaMaxima();

    #pragma endregion
private: 
    const unsigned int ID;
    unsigned int totalPasajeros;
    unsigned int pesoMaximo;
    unsigned int nPasajeros;
};

#endif // _CAVION_H