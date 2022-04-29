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
        /// <param name="_ID">: ID del aeropuerto</param>
        /// <param name="_capacidadAeropuerto">: Capacidad del aeropuerto</param>
        /// <param name="_nombre">: Nombre del aeropuerto</param>
        cAeropuerto(string _ID = "", ush _capacidadAeropuerto = 0, string _nombre = "");

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cAeropuerto();

    #pragma endregion

    #pragma region Metodos

    // hacer summary de todos los metodos, consultar a juanma como se hace
    bool darPermiso(cAvion* avion);
    string to_string();
    void imprimir();
    ush cantAterrizados(cFecha* fecha);
    ush cantDespegados(cFecha* fecha);
    ush getcapacidadAeropuerto() { return this->capacidadAeropuerto; };
    void setcapacidadAeropuerto(int _capacidad) { this->capacidadAeropuerto = _capacidad; }
    void setListaVuelos(cListaVuelo* Lista) { this->listaVuelos = Lista; }
    void setHangar(cListaAvion* Lista) { this->hangar = Lista; }
   // float porcentajeHorarioPartida();

    #pragma endregion

private: 

    #pragma region Atributos

    // interno de la clase
    cListaVuelo* listaVuelos;
    cListaAvion* hangar;
    
    // interno
    const string ID;
    const string nombre;
    ush capacidadAeropuerto;

    #pragma endregion

};

#endif // _CAEROPUERTO_H