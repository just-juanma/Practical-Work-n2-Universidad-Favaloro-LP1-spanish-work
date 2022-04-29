/*
La clase fecha incluye un short hora 
Tiene que ser una fecha del anio 2022 y la hora idealmente sera en formato de 24 hs.
*/
#ifndef _CFECHA_H
#define _CFECHA_H
#include "gbl.h"

class cFecha 
{

    #pragma region Friend classes

    friend class cAeropuerto;
    friend class cVuelo;
    friend class cPasajero;

    #pragma endregion

public: 

    #pragma region Constructor y destructor

    /// <summary>
    /// Constructor parametrizado por defecto
    /// </summary>
    /// <param name="_dia">: Dia de la fecha</param>
    /// <param name="_mes">: Mes de la fecha</param>
    /// <param name="_anio">: Anio de la fecha</param>
    /// <param name="_hora">: Hora de la fecha</param>
    cFecha(sh _dia = 0, sh _mes = 0, sh _anio = 0, sh _hora = 0);

    /// <summary>
    /// Destructor por defecto 
    /// </summary>       
    ~cFecha();

    #pragma endregion

    #pragma region Metodos

    /// <summary>
    /// Concatena a un solo string los atributos pertinentes
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

    #pragma region Atributos

    // interno
    sh dia;
    sh mes;
    sh anio;
    sh hora;

    #pragma endregion
};

#endif // _CFECHA_H