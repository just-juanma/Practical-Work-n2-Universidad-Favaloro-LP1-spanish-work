#ifndef _CPASAJERO_H
#define _CPASAJERO_H
#include "gbl.h"
#include "cValija.h"
#include "cListaValija.h"
#include "cFecha.h"
class cPasajero {
    friend class cListaPasajero;
    friend class cVuelo;
public:

    #pragma region constructor y destructor

    cPasajero(string _nombre = "", string _DNI = "",
        sh _numeroVuelo = 0, sh _asiento = 0);
    /// <summary>
    /// Destructor por defecto
    /// </summary>
    ~cPasajero();

    #pragma endregion 

    #pragma region metodos

    cValija* operator+(cValija& _equipaje) {
        try {
            if (_equipaje.peso > 0) {
                if (this->pesoTotalEquipaje->peso < 25) {
                    if (equipaje->agregar(&_equipaje)) {
                        this->pesoTotalEquipaje->peso += _equipaje.peso;
                        return pesoTotalEquipaje; // retorno el peso total del equipaje del pasajero
                    }
                    else 
                        throw "No se pudo agregar el equipaje";
                }
                else 
                    throw "Se alcanzo el equipaje maximo que puede llevar el pasajero";
            }
            else 
                throw "El peso no puede ser negativo o cero";
        }
        catch (const char* msg) {
            cout << msg << endl;
            return NULL;
        }
    }
    cValija* operator-(cValija& _equipaje) {
        try {
            if (equipaje->eliminar(&_equipaje)) {
                this->pesoTotalEquipaje->peso -= _equipaje.peso;
                return pesoTotalEquipaje;
            }
            else 
                throw "No se pudo eliminar el equipaje";
        }
        catch (const char* msg) {
            cout << msg << endl;
            return NULL;
        }
     
    }
    float getPesoTotalEquipaje()const { return pesoTotalEquipaje->peso; }
    string to_string()const;
    void imprimir()const { cout << to_string() << endl; }

    #pragma endregion

    #pragma region getters y setters

    cFecha* getFecha()const { return this->fecha; }

    #pragma endregion
private:
    const string nombre;
    const string DNI;
    static ush cantActual;
    static sh cantTotal;
    cValija* pesoTotalEquipaje;
    cListaValija* equipaje;
    cFecha* fecha;
    sh numeroVuelo;
    sh asiento;

};

#endif // _CPASAJERO_H