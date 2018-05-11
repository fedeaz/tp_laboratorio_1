#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

    char nombre[50];
    int edad;
    int estado;
    char dni[10];

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param
 * \param
 * \return
 *
 */
void inicializarPersona(EPersona vec[], int);


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param
 * \param
 * \return
 *
 */
int buscarLibre(EPersona vec[], int);


/** \brief pide al usuario un vector de la estructura EPersona , un entero y una cadena de caracteres
 *
 * \param
 * \param
 * \return
 *
 */
int buscarPersona(EPersona vec[], int, char[]);


/** \brief pide al usuario un vector de la estructura EPersona
 * \param
 * \param
 * \return
 *
 */
void mostrarPersona(EPersona);


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarPersonas(EPersona vec[], int);


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param
 * \param
 * \return
 *
 */
void alta(EPersona vec[],int);


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param
 * \param
 * \return
 *
 */
void baja(EPersona vec[],int);


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param
 * \param
 * \return
 *
 */
void ordenarGente(EPersona vec[], int);


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param
 * \param
 * \return
 *
 */
void graficar(EPersona vec[], int);


/** \brief pide al usuario una cadena de caracteres
 *
 * \param
 * \param
 * \return
 *
 */
int validarNumero(char []);






#endif // FUNCIONES_H_INCLUDED
