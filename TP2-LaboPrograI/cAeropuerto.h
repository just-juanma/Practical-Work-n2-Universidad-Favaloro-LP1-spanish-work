#ifndef _CAEROPUERTO_H
#define _CAEROPUERTO_H
#include "gbl.h"
#include "cListaAvion.h"
#include "cListaVuelo.h"

class cAeropuerto {

    #pragma region Friend classes

    friend class cAvion;
    friend class main;

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
    ush cantAterrizadosDia(cFecha* fecha);
    ush cantDespegados(cFecha* fecha);
    ush getcapacidadAeropuerto() { return this->capacidadAeropuerto; };
    cListaAvion* getListaAvionesAeropuerto() { return this->listaAvionesAeropuerto; };
    void setcapacidadAeropuerto(int _capacidad) { this->capacidadAeropuerto = _capacidad; }
    void setListaVuelos(cListaVuelo* Lista) { this->listaVuelos = Lista; }
    void setAvionesAeropuerto(cListaAvion* Lista) { this->listaAvionesAeropuerto = Lista; }
    ush CantAvionesAeropuerto();
    float porcentajeHorarioPartida() {
        ush cont = 0;
        float res = 0;
        for (ush i = 0; i < cVuelo::numero; i++) 
            for(ush j = 0; j < listaAvionesAeropuerto->MetidosEnLista; j++)
                if (this->listaVuelos->listaVuelo[i]->vuelo == this->listaAvionesAeropuerto->ListaAviones[j]->getfecha() &&
                    this->listaAvionesAeropuerto->ListaAviones[j]->getestado() == eEstado::aterrizado);
            cont++;
        try {
            if (cVuelo::numero)
                return (float)(cont * 100) / cVuelo::numero;
            else
                throw "Error: no se puede dividir por cero (0)";
        }
        catch (const char msg) {
            cout << msg << endl;
            return 0;
        }
      
    }
    #pragma endregion

private: 

    #pragma region Atributos

    // interno de la clase
    cListaVuelo* listaVuelos;
    cListaAvion* listaAvionesAeropuerto;
    
    // interno
    const string ID;
    const string nombre;
    ush capacidadAeropuerto;

    #pragma endregion

};

#endif // _CAEROPUERTO_H