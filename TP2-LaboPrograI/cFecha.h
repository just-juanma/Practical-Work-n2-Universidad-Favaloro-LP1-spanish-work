#ifndef _CFECHA_H
#define _CFECHA_H
#include "gbl.h"
class cFecha {
    friend class cVuelo;
    friend class cPasajero;
    friend class cVuelo;
public: 
    #pragma region constructor y destructor

        /// <summary>
        /// Constructor por defecto
        /// </summary>
 
        cFecha(sh _dia = 0, sh _mes = 0, sh _anio = 0, sh _hora = 0);

        /// <summary>
        /// Destructor por defecto 
        /// </summary>       
        ~cFecha();

    #pragma endregion

    #pragma region metodos

  


    

    #pragma endregion
private: 
    sh dia;
    sh mes;
    sh anio;
    sh hora;
};

#endif // _CFECHA_H