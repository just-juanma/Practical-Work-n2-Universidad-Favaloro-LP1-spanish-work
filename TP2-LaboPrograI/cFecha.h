/*
La clase fecha incluye un short hora 
Tiene que ser una fecha del anio 2022 y la hora idealmente sera en formato de 24 hs.
*/
#ifndef _CFECHA_H
#define _CFECHA_H
#include "gbl.h"
class cFecha 
{

    #pragma region friend classes

    friend class cVuelo;
    friend class cPasajero;
    friend class cVuelo;

    #pragma endregion

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

    /// <summary>
    /// Concatena a un solo string los atributos pertinentes a la fecha
    /// </summary>
    /// <returns>String concatenado</returns>
    string to_string()const;

    /// <summary>
    /// Imprime to_string()
    /// </summary>
    void imprimir()const { cout << to_string() << endl; }

private: 

   /// <summary>
   /// Sistema que controla que la fecha y hora sea valida
   /// Fuente: https://www.geeksforgeeks.org/program-check-date-valid-not/
   /// </summary>
   /// <param name="_dia">Dia a verificar</param>
   /// <param name="_mes">Mes a verificar</param>
   /// <param name="_anio">Anio a verificar</param>
   /// <param name="_hora">Hora a verificar</param>
   /// <returns>True en caso de ser una fecha y hora valida, false en caso contrario</returns>
   bool isValid(sh _dia, sh _mes, sh _anio, sh _hora);

   #pragma endregion

    #pragma region atributos

    // interno de la clase
    sh dia;
    sh mes;
    sh anio;
    sh hora;

    #pragma endregion
};

#endif // _CFECHA_H