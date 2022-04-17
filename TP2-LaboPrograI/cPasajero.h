#ifndef _CPASAJERO_H
#define _CPASAJERO_H
#include "gbl.h"
#include "cValija.h"
class cPasajero {
public: 
    #pragma region constructor y destructor
    /// <summary>
    /// Constructor parametrizado
    /// </summary>
    /// <param name="_nombre">: Nombre del pasajero</param>
    /// <param name="_DNI">: DNI del pasajero</param>
    cPasajero(string _nombre = "", unsigned short _DNI = 0, unsigned short _nAsiento = 0, unsigned short _nVuelo = 0);
    /// <summary>
    /// Destructor por defecto
    /// </summary>
    ~cPasajero();
    #pragma endregion 
    
    #pragma region metodos
    unsigned short getDNI()const {
        return DNI;
    }
    unsigned short getNVuelo()const {
        return nVuelo;
    }
    double getPesoEquipaje(unsigned short pos)const {
        return listaValija[pos]->getPeso();
    }
    /// <summary>
    /// Trata de agregar una valija a la lista de valijas
    /// </summary>
    /// <param name="posibleValija">: posible valija a agregar</param>
    /// <returns>True en caso de ser posible, false en caso contrario</returns>
    bool agregarEquipaje(cValija* posibleValija);
    /// <summary>
    /// Retira el equipaje para posteriormente eliminarlo
    /// </summary>
    /// <param name="nEquipaje">: posicion de valija a quitar</param>
    /// <returns>El equipaje en cuestion</returns>
    cValija* retirarEquipaje(unsigned short nEquipaje);
    /// <summary>
    /// Elimina el elemento mediante el destructor
    /// </summary>
    /// <param name="nEquipaje">: posicion a eliminar</param>
    /// <returns></returns>
    bool eliminarEquipaje(unsigned short nEquipaje);


    string to_string();
    void imprimir();

    #pragma endregion
private: 
    // datos del pasajero
    const string nombre;
    const unsigned short DNI;
    unsigned short nAsiento;
    unsigned short nVuelo;
    // equipaje del pasajero
    cValija** listaValija;
    unsigned short nValijas;
    double pesoTotal;
};

#endif // _CPASAJERO_H