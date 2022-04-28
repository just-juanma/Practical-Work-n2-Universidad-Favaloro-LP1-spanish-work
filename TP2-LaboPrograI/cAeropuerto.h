#ifndef _CAEROPUERTO_H
#define _CAEROPUERTO_H
#include "gbl.h"
#include "cListaAvion.h"
#include "cListaVuelo.h"

class cAeropuerto {

    #pragma region Friend classes

    friend class cAvion;

    #pragma endregion

public: 

    #pragma region Constructor y destructor

        /// <summary>
        /// Constructor por defecto parametrizado
        /// </summary>
        /// <param name="_ID"></param>
        /// <param name="_capacidadAeropuerto"></param>
        /// <param name="_nombre"></param>
        cAeropuerto(string _ID=" ", unsigned int _capacidadAeropuerto=0, string _nombre="");

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cAeropuerto();

    #pragma endregion

    #pragma region metodos

    bool darPermiso(cAvion* avion);
    string to_string();
    void imprimir();
    ush cantAterrizados(cFecha* fecha);
    ush cantDespegados(cFecha* fecha);
   // float porcentajeHorarioPartida();

    #pragma endregion

private: 
    const string ID;
    const string nombre;
    ush capacidadAeropuerto;
    cListaVuelo* listaVuelos;
    cListaAvion* hangar;
};

#endif // _CAEROPUERTO_H