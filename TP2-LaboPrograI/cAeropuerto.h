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
        cAeropuerto(const unsigned int _ID, unsigned int _capacidadAeropuerto, const string _nombre, cListaVuelo* listaVuelos, cListaAvion* hangar);

        cAeropuerto(const unsigned int _ID, unsigned int _capacidadAeropuerto, const string _nombre, cListaVuelo* listaVuelos, cListaAvion* hangar);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cAeropuerto();

    #pragma endregion

    #pragma region metodos

    bool darPermiso();
    //string getNombre() { return nombre;}
    string to_string();
    void imprimir();

    #pragma endregion

private: 
  
    const ush ID;
    const string nombre;
    ush capacidadAeropuerto;
    cListaVuelo *listaVuelos;
    cListaAvion *hangar;
};

#endif // _CAEROPUERTO_H