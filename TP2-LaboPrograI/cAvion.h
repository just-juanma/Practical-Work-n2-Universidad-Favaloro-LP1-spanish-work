#ifndef _CAVION_H
#define _CAVION_H
#include "gbl.h"
#include "cListaPasajero.h"
//#include "cAeropuerto.h"
class cAvion {
public:
#pragma region constructor y destructor 

    /// <summary>
    /// Constructor parametrizado
    /// <///summary>
    cAvion(unsigned int _totalPasajeros, unsigned int _pesoMaximo, unsigned int _nPasajeros,string _ID);
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
    /// Se le solicita permiso al aeropuerto para que chequee la disposicion en el hangar para poder asi
    /// realizar el aterrizaje (cambiar el esdtado del vuelo)
    /// </summary>
    /// <///summary>	
    void aterrizar();
    /// <summary>
    /// chequearCargaMaxima:
    ///       1. Debe chequear que la carga en el avion no sea superior
    ///       2. Devuele 1 si esta todo biem, sino tirara una excepcion(con try y catch) y devolvera 0; 
    ///      
    /// <///summary>
    bool chequearCargaMaxima();

    void setListaPasajero(cListaPasajero* _pasajeros,int n);
    /// <summary>
    ///  Segun lo comprendido se podría hacer que este metodo sea "obtenido" por friend de la clase aeropuerto
    /// </summary> 
    /// Al ser desde la clase cAeropuerto no es dar es recibir permiso
    void recibirPermiso(cAvion* avion);
    eEstado pedirPermiso();
    string getid();
    cListaPasajero* getListaPasajero();
    int getcantpasajeros();
    eEstado getestado();
    string to_string();
    void imprimir();
#pragma endregion

private:
    string ID;
    unsigned int totalPasajeros;
    // unsigned int pesoMaximo; el peso nos lo da la clase cValija, y el peso debe ser flotante
    unsigned int nPasajeros;
    unsigned int pesoMaximo;
    cListaPasajero* Listapasajeros;
    eEstado estado; //reemplazar por vuelo
    int permiso;
};

#endif  
_CAVION_H



