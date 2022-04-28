#ifndef _CAEROPUERTO_H
#define _CAEROPUERTO_H
#include "gbl.h"
#include "cVuelo.h"
#include "cListaAvion.h"
#include "cListaVuelo.h"
#include "cAvion.h"

class cAeropuerto {
    friend class cAvion;
public: 

    #pragma region constructor y destructor

        /// <summary>
        /// Constructor parametrizado
        /// </summary>
        /// <param name="totalAeropuerto"></param>
        cAeropuerto(string _ID="", unsigned int _capacidadAeropuerto=0, string _nombre="");

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
    float porcentajeHorarioPartida();

    #pragma endregion

private: 
    const string ID;
    const string nombre;
    ush capacidadAeropuerto;
    cListaVuelo* listaVuelos;
    cListaAvion* hangar;
};

#endif // _CAEROPUERTO_H