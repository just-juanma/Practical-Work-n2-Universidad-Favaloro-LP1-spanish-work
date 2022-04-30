/*
    Juanma solo toco la estetica del codigo, no cambio NADA mas
    Consejos a modificar por Juanma (tomalo o dejalo, borrar todo el comentario al terminar de leer):
        - generar los summary faltantes
        - usar sh en lugar de int y ush en lugar de unsigned int, seria optmizar el programa
        - tener cuidado con ush, usarlo cuando estes seguro de que el numero nunca sera negativo (la "i" de un bucle, por ejemplo)
        - no esta el atributo cantTotal de aviones, como puedo saber cual es el limite de la lista?
        - el ID del avion no se modifica, debe ser const string en lugar de string
        - clases de implementacion corta (ej getters y setters) al header, mejora la eficiencia del programa
    PD: no es mejor hacer los pragma region en la "portada" de la clase? es decir, en su .h? no saque los pragma region del cpp, pero
        consideralo tambien
*/



#ifndef _CAVION_H
#define _CAVION_H
#include "gbl.h"
#include "cListaPasajero.h"
#include "cFecha.h"

class cAvion {

public:
    #pragma region Clases friends
    #pragma endregion


    #pragma region Constructor y destructor 

    /// <summary>
    /// Constructor parametrizado por defecto
    /// <///summary>
    cAvion(unsigned int _totalPasajeros = 20, unsigned int _pesoMaximo = 1200, unsigned int _nPasajeros = 20,string _ID = "none");

    /// <summary>
    /// Destructor por defecto
    /// <///summary>
    ~cAvion();

    #pragma endregion 

    #pragma region metodos

    /// <summary>
    /// Depegue del avion. Esto implica que
    ///         En cuanto al pasajero:
    ///       - Chequear que los pasajeros a vordo sean los correctos
    ///       - La fecha y el numero de vuelo del pasajero deja de ser valida
    ///         En cuanto al vuelo:
    ///       - Debe cambiar el estado del vuelo
    ///       - Chequear si el peso de los pasajeros con su equipaje, mas 4 tripulantes no es el maximo
    ///       -
    /// </summary>
    void despegar();

    /// <summary>
    /// Se le solicita permiso al aeropuerto para que chequee la disposicion en el hangar para poder asi
    /// realizar el aterrizaje (cambiar el esdtado del vuelo)
    /// </summary>
    void aterrizar();

    /// <summary>
    /// chequearCargaMaxima:
    ///       1. Debe chequear que la carga en el avion no sea superior
    ///       2. Devuele 1 si esta todo biem, sino tirara una excepcion(con try y catch) y devolvera 0; 
    ///      
    /// </summary>
    bool chequearCargaMaxima();

    /// <summary>
    /// setea la lista de pasajeros
    /// </summary>
    /// <param name="_pasajeros">El puntero de la lista</param>
    /// <param name="n">La cantidad de elementos que esta lista contiene</param>
    void setListaPasajero(cListaPasajero* _pasajeros,int n);

    /// <summary>
    /// se lo debe llamar cuando el aeropuerto decida otorgarle permiso al avion
    /// </summary> 
    /// Al ser desde la clase cAeropuerto no es dar es recibir permiso
    /// 
    void recibirPermiso(cFecha* llegada, cFecha* partida);

    /// <summary>
    /// setea el estado del avion, meciando un enum
    /// </summary>
    /// <param name="_estado"></param>
    void setestado(eEstado _estado);


    void setfecha(cFecha* llegada,cFecha* partida);

    /// <summary>
    /// Este metodo devuelve el valor de aviones en toda la ejecucio, 
    /// por lo que devuelve el valor de una variable estatica
    /// </summary>
    /// <returns></returns>
    static ush getnAviones();

    eEstado pedirPermiso();

    /// <summary>
    /// Se obtiene la identificacion unica del avion
    /// </summary>
    /// <returns></returns>
    string getid();

    /// <summary>
    /// Se obtiene la lista de pasajeros
    /// </summary>
    /// <returns></returns>
    cListaPasajero* getListaPasajero();

    /// <summary>
    /// Se obtiene la cantidad de pasajeros
    /// </summary>
    /// <returns></returns>
    int getcantpasajeros();

    /// <summary>
    /// Se obtiene el estado del avion
    /// </summary>
    /// <returns></returns>
    eEstado getestado();

    /// <summary>
    /// Se obtiene la fecha en la que sale el avion
    /// </summary>
    /// <returns></returns>
    cFecha* getfecha();


    string to_string();


    void imprimir();


    #pragma endregion

private:

    #pragma region Atributos
    
    // static
    static int nAviones;
    
    // interno clases
    cListaPasajero* Listapasajeros;
    cFecha* partida;
    cFecha* llegada; 
    // iterno
    unsigned int totalPasajeros;
    unsigned int nPasajeros;

    const string ID;
    unsigned int pesoMaximo;
    eEstado estado; 
    int permiso;
    #pragma endregion

};

#endif  // _CAVION_H



