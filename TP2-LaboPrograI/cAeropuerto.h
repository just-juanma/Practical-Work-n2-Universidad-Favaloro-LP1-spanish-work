#ifndef _CAEROPUERTO_H
#define _CAEROPUERTO_H
#include "gbl.h"
#include "cVuelo.h"
#include "cListaAvion.h"

class cAeropuerto {
public: 

    #pragma region constructor y destructor

        /// <summary>
        /// Constructor parametrizado
        /// </summary>
        /// <param name="totalAeropuerto"></param>
        cAeropuerto(const unsigned int _ID, unsigned int _totalAeropuerto, unsigned int _nVuelos, unsigned int _nAviones, const string _nombre);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cAeropuerto();

    #pragma endregion

    #pragma region metodos

    void darPermiso();
    string getNombre() { return nombre;}

    string to_string();
    void imprimir();

    #pragma endregion

private: 
    const unsigned int ID;
    const string nombre;
    unsigned int capacidadAeropuerto;
    unsigned int nAviones;
    static unsigned int numeroAeropuerto;
    //cListaVuelo listaVuelo;
    cListaAvion listaAvionAeropuerto;
    unsigned int nVuelos;
};

#endif // _CAEROPUERTO_H