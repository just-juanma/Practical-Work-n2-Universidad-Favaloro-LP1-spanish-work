#ifndef _CAVION_H
#define _CAVION_H
#include "gbl.h"
//#include "cAeropuerto.h"
#include "cListaPasajero.h"
#include "cVuelo.h"
#include <random>
class cAvion {
public:
#pragma region constructor y destructor 

    /// <summary>
    /// Constructor parametrizado
    /// <///summary>
    /// <param name="_totalPasajeros">: Capacidad maxima que permite el avion<///param>
    /// <param name="_pesoMaximo">: Peso maximo que permite el avion<///param>
    /// <param name="_nPasajeros">: Cantidad actual de pasajeros<///param>
    cAvion(unsigned int _totalPasajeros = 0, unsigned int _pesoMaximo = 0, unsigned int _nPasajeros = 0);
    // unsigned int _pesoMaximo, el peso nos lo da la clase cValija, y el peso debe ser flotante
    /// <summary>
    /// Destructor por defecto
    /// <///summary>
    ~cAvion();
#pragma endregion 
#pragma region metodos
    /// <summary>
    /// Depegue del avion. Esto implica que
    ///         En cuanto al pasajero:
    ///       - Chequear que los pasajeros a vordo sean los correctos
    ///       - La fecha y el numero de vuelo del pasajero deja de ser valida
    ///         En cuanto al vuelo:
    ///       - Debe cambiar el estado del vuelo
    ///       - Chequear si el peso de los pasajeros con su equipaje, mas 4 tripulantes no es el maximo
    ///       -
    /// <///summary>
    void despegar();
    /// <summary>
    /// Se le solicita permiso al aeropuerto asigando que chequee la disposicion en el hangar para poder asi
    /// realizar el aterrizaje
    /// </summary>
    /// <///summary>	
    void aterrizar();
    string getfecha()const {
        return this->fecha;
    }
    /// <summary>
    /// chequearCargaMaxima:
    ///       1. Debe chequear que la carga en el avion no sea superior
    ///       2. Devuele 1 si esta todo biem, sino tirara una excepcion(con try y catch) y devolvera 0; 
    ///      
    /// <///summary>
    bool chequearCargaMaxima();
    void setPasajeros(cListaPasajero* pasajeros);
    //void setListaPasajeros(cListaPasajero* pasajeros);
    string to_string();
    void imprimir();
    /// <summary>
    /// 
    /// </summary>
    void pedirPermiso(bool _valor, string* _fecha);
#pragma endregion

private:
    unsigned int ID;
    unsigned int totalPasajeros;
    // unsigned int pesoMaximo; el peso nos lo da la clase cValija, y el peso debe ser flotante
    unsigned int nPasajeros;
    unsigned int pesoMaximo;
    string fecha;
    //cAeropuerto* aeropuerto;
    cListaPasajero* pasajeros; //cListaPasajero* pasajeros; 
    cVuelo vuelo;
    eEstado estado;

};

#endif  
_CAVION_H



