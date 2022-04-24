#ifndef _CPASAJERO_H
#define _CPASAJERO_H
#include "gbl.h"
#include "cValija.h"
#include "cFecha.h"
class cPasajero {
    friend class cListaPasajero;
public: 
    #pragma region constructor y destructor
    
    cPasajero(string _nombre = "", string _DNI = "",
              sh _numeroVuelo = 0, sh _asiento = 0);
    /// <summary>
    /// Destructor por defecto
    /// </summary>
    ~cPasajero();
    #pragma endregion 
    

  
  
  
    string to_string();
    void imprimir() { cout << to_string(); }

   
private: 
    const string nombre;
    const string DNI;
    static sh cantActual;
    static sh cantTotal;
    cFecha* fecha;
    sh numeroVuelo;
    sh asiento;

};

#endif // _CPASAJERO_H