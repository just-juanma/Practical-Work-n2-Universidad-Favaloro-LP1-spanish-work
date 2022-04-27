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
        if (_equipaje.peso > 0 && this->pesoTotal->peso < 25)
            if (equipaje->agregar(&_equipaje)) {
                this->pesoTotal->peso += _equipaje.peso;
                return pesoTotal; // retorno el peso total del equipaje del pasajero
            }
            else return NULL;
    }
    cValija* operator-(cValija& _equipaje) {
        if (equipaje->eliminar(&_equipaje)) {
            this->pesoTotal->peso -= _equipaje.peso;
            return pesoTotal;
        }
        else return NULL;
    }
    string to_string();
    void imprimir() { cout << to_string() << endl; }
#pragma endregion

private:
    const string nombre;
    const string DNI;
    static ush cantActual;
    static sh cantTotal;
    cValija* pesoTotal;
    cListaValija* equipaje;
    cFecha* fecha;
    sh numeroVuelo;
    sh asiento;

};

#endif // _CPASAJERO_H