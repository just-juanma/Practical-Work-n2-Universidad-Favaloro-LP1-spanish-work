#ifndef _CPASAJERO_H
#define _CPASAJERO_H
#include "gbl.h"
#include "cListaValija.h"
#include "cFecha.h"

class cPasajero {

    #pragma region Friend classes
    
    friend class cListaPasajero;
    friend class cVuelo;

    #pragma endregion

public:

    #pragma region Constructor y destructor

    /// <summary>
    /// Constructor parametrizado por defecto
    /// </summary>
    /// <param name="_nombre">: Nombre del pasajero</param>
    /// <param name="_DNI">: DNI del pasajero</param>
    /// <param name="_numeroVuelo">: Numero de vuelo del pasajero</param>
    /// <param name="_asiento">: Numero de asiento del pasajero</param>
    cPasajero(string _nombre = "", string _DNI = "",
              sh _numeroVuelo = 0, sh _asiento = 0);

    /// <summary>
    /// Destructor por defecto
    /// </summary>
    ~cPasajero();

    #pragma endregion 

    #pragma region Metodos

    /// <summary>
    /// Permite obtener el peso de todo el equipaje
    /// </summary>
    /// <returns>Peso total de la suma de todo el equipaje del pasajero</returns>
    float getPesoTotalEquipaje()const { 
        float suma = 0;
        for (ush i = 0; i < equipaje->cantActual; i++) 
            if(this->equipaje->listaValija[i])
                suma += this->equipaje->listaValija[i]->peso;
        return suma;
    }

    /// <summary>
    /// Concatena a un solo string los atributos pertinentes
    /// </summary>
    /// <returns>String concatenado</returns>
    string to_string()const;

    /// <summary>
    /// Imprime to_string()
    /// </summary>
    void imprimir()const { cout << to_string() << endl; }

    /// <summary>
    /// Obtiene la fecha del pasajero
    /// </summary>
    /// <returns>Fecha del pasajero</returns>
    cFecha* getFecha()const { return this->fecha; }

    void setFecha(cFecha* _fecha) { this->fecha = _fecha; }

    void setLista(cListaValija* lista) { equipaje = lista; }

    #pragma endregion

    #pragma region Sobrecarga 

    /// <summary>
    /// Sobrecarga del operador + para poder ir cargando el equipaje del pasajero
    /// </summary>
    /// <param name="_equipaje">: Equipaje a agregar</param>
    /// <returns></returns>
    cPasajero* operator+(cValija& _equipaje) {
        try {
            if (getPesoTotalEquipaje() + _equipaje.peso < 25) {
                if (this->equipaje->agregar(&_equipaje)) 
                    return this;
                else 
                    return NULL;
            }
            else 
                throw "Error: Se alcanzo el equipaje maximo que puede llevar el pasajero";
        }
        catch (const char* msg) {
            cout << msg << endl;
            return NULL;
        }
    }

    cPasajero* operator-(cValija& _equipaje) {
        if (equipaje->eliminar(&_equipaje)) {
            return this;
        }
        else 
            return NULL;
    }

    #pragma endregion

private:

    #pragma region Atributos
    
    // interno clases
    cListaValija* equipaje;
    cFecha* fecha;

    // interno
    const string nombre;
    const string DNI;
    sh asiento;
    sh numeroVuelo;

    #pragma endregion

};

#endif // _CPASAJERO_H