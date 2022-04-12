#ifndef _CFECHA_H
#define _CFECHA_H

class cFecha {
public: 
    #pragma region constructor y destructor

        /// <summary>
        /// Constructor parametrizado 
        /// </summary>
        cFecha();
        cFecha(string _fecha);

        /// <summary>
        /// Destructor por defecto 
        /// </summary>       
        ~cFecha();

    #pragma endregion

    #pragma region metodos

        /// <summary>
        /// En caso de que algun objeto no pueda cumplir con su horario de partida, debera reprogramar su fecha
        /// </summary>
        /// <param name="_fecha">: Fecha a modificar</param>
        void reprogramarFecha(string _fecha) { this->fecha = _fecha; }

    #pragma endregion
private: 
    string fecha;
};

#endif // _CFECHA_H