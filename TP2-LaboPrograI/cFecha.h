#ifndef _CFECHA_H
#define _CFECHA_H
#include "gbl.h"

class cFecha {
public: 
    #pragma region constructor y destructor

        /// <summary>
        /// Constructor por defecto
        /// </summary>
 
        cFecha();

        /// <summary>
        /// Destructor por defecto 
        /// </summary>       
        ~cFecha();

    #pragma endregion

    #pragma region metodos

        /// <summary>
        /// Setea fechas y en caso de que algun objeto no pueda cumplir con su horario de partida, debera reprogramar su fecha
        /// </summary>
        /// <param name="_fecha">: Fecha a agregar/modificar</param>
        void setFecha(string* _fecha) { 
            if(fecha == NULL)
                this->fecha = _fecha; 
        }

        string* getFecha()const {
            if (fecha != NULL)
                return fecha;
            return NULL;
        }

        

    #pragma endregion
private: 
    string* fecha;
};

#endif // _CFECHA_H