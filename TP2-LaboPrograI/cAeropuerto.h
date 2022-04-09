#ifndef _CAEROPUERTO_H
#include "gbl.h"
#define _CAEROPUERTO_H

class cAeropuerto {
public: 
    #pragma region constructor y destructor

        /// <summary>
        /// Constructor parametrizado
        /// </summary>
        /// <param name="totalAeropuerto"></param>
        cAeropuerto(unsigned int totalAeropuerto);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cAeropuerto();

    #pragma endregion

    #pragma region metodos

    //bool agregarAvion(cAvion* avion);

    //bool eliminarAvion(int pos);
    
    //bool darPermiso();

    #pragma endregion
private: 
    const unsigned int ID;
    unsigned int capacidadAeropuerto;
};

#endif // _CAEROPUERTO_H