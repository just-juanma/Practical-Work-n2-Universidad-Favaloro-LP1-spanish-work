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
    
    /// <summary>
    /// Verifico que sea posible agregar un nuevo avion al aeropuerto sin sobrepasar su capacidad maxima, de no ser asi lanzo una excepcion
    /// </summary>
    /// <param name="avion">: Avion a tratar de conseguir permiso</param>
    /// <returns>True en caso de dar permiso, false en caso contrario</returns>
    bool darPermiso(cAvion* avion);

    string to_string();
    void imprimir();

    /// <summary>
    /// Segun una fecha, se obtiene el numero de vuelos despegados y aterrizados en el dia
    /// </summary>
    /// <param name="fecha">: Fecha a buscar coincidencia</param>
    /// <returns>Cantidad de aterrizados</returns>
    ush cantAterrizadosDia(cFecha* fecha);

    /// <summary>
    /// Obtiene la cantidad de aviones que admite el aeropuerto
    /// </summary>
    /// <returns>Cantidad de aviones admitidos</returns>
    ush getCapacidadAeropuerto()const { return this->capacidadAeropuerto; }

    /// <summary>
    /// Obtiene la lista de aviones
    /// </summary>
    /// <returns></returns>
    cListaAvion* getListaAvionesAeropuerto()const { return this->listaAvionesAeropuerto; }

    /// <summary>
    /// Asigna la capacidad del aeropuerto
    /// </summary>
    /// <param name="_capacidad">: Capacidad a asignar</param>
    void setcapacidadAeropuerto(ush _capacidad) { this->capacidadAeropuerto = _capacidad; }

    /// <summary>
    /// Asgina la lista de vuelos
    /// </summary>
    /// <param name="Lista">: lista a asignar</param>
    void setListaVuelos(cListaVuelo* Lista) { this->listaVuelos = Lista; }

    /// <summary>
    /// Asgina los aviones al aeropuerto
    /// </summary>
    /// <param name="Lista">: lista a asginar</param>
    void setAvionesAeropuerto(cListaAvion* Lista) { this->listaAvionesAeropuerto = Lista; }

    /// <summary>
    /// Obtiene los aviones aterrizados dentro del aeropuerto
    /// </summary>
    /// <returns>Cantidad de aviones</returns>
    ush CantAvionesAeropuerto();

    /// <summary>
    /// Recorre la lista de vuelos y aviones para saber si partieron en horario
    /// </summary>
    /// <returns>Porcentaje de ocurrencia</returns>
    float porcentajeHorarioPartida() {
        ush cont = 0;
        float res = 0;
        for (ush i = 0; i < cVuelo::numero; i++) 
            for(ush j = 0; j < listaAvionesAeropuerto->ocupados; j++)
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