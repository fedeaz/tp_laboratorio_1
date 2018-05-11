#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param hace un for que recorre la estructura
 * \param cambia el estado de todos los componentes de la estructura a 0
 * \param cambia la edad de todos los componentes de la estructura a 0
 * \return
 *
 */
void inicializarPersona(EPersona vec[], int tam)
{
       int i;
       for(i=0; i<tam; i++)
       {
           vec[i].estado = 0;
           vec[i].edad = 0;
       }
}


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param hace un for que recorre la estructura
 * \param si el estado del lugar en el que se encuentra el for es 0 cambia la variable indice
 * \return variable indice
 *
 */
int buscarLibre(EPersona vec[], int tam)
    {
        int indice =-1;
        int i;
        for(i=0 ;i<tam; i++)
        {
            if(vec[i].estado == 0)
            {
                    indice = i;
                    break;
            }

        }
        return indice;
    }


/** \brief pide al usuario un vector de la estructura EPersona , un entero y una cadena de caracteres
 *
 * \param hace un for que recorre la estructura
 * \param si en el lugar en que se encuentra el for dentro de la estructura su estado es = a 1 y su dni es = a la cadena de caracteres dni cambia el indice por el lugar en que se encuentre
 * \return variable indice
 *
 */
int buscarPersona(EPersona vec[], int tam, char dni[])
    {
        int indice = -1;
        int i;

        for(i=0; i<tam; i++)
        {
                if(vec[i].estado == 1 && vec[i].dni == dni)
                    indice = i;
                    break;
                }
        }
        return indice;

    }


    /** \brief pide al usuario un vector de la estructura EPersona
     *
     * \param un printf que muestra el nombre, dni y edad de la posicion que se le paso
     * \param
     * \return
     *
     */
void mostrarPersona(EPersona per)
    {
        printf(" \n%s\t   \t%s \t  \t%4d \n", per.nombre, per.dni, per.edad);
    }


    /** \brief pide al usuario un vector de la estructura EPersona y un entero
     *
     * \param limpia la pantalla
     * \param llama a la funcion ordenarGente
     * \param hace un for que recorra la estructura
     * \param si el estado de la posicion en la que se encuentra el for es = a 1 llama a la funcion mostrarPersona
     * \return
     *
     */
void mostrarPersonas(EPersona vec[], int tam)
    {
        system("cls");
        ordenarGente(vec,tam);
        printf("mostrar personas\n\n");
        printf("Nombre \t\t DNI \t \tEdad\n");
        int i;
        for(i=0; i<tam; i++)
        {
            if(vec[i].estado == 1)
            {
                mostrarPersona(vec[i]);
            }
        }
        system("pause");
    }


    /** \brief pide al usuario un vector de la estructura EPersona y un entero
     *
     * \param asigno a indice el valor que resulta de la llamada a la funcion buscar persona
     * \param si indice es distinto a -1 pido el dni y se lo asigno a la variable dni
     * \param asigno a valido el valor que resulta de la llamada de la funcion validarNumero
     * \param si valido es distinto a 1 devuelvo un printf para indicar que el usuario cometio un error
     * \param de lo contrario asigno a la variable estado el resultado de la funcion buscarPersona
     * \param si estado es distinto de -1 hago un printf mostrando que ese dni ya corresponde a una persona y la muestro
     * \param de lo contrario asigno a nuevaPersona.estado el volor 1 copio el dni en nuevaPersona.dni
     * \param pido el nombre mediante un printf y lo asigno a nuevaPersona.nombre
     * \param pido la edad mediante un printf y lo asigno a nuevaPersona.edad
     * \param asigno a el vec [indice] nuevaPersona e informo que la alta fue exitosa
     * \param de lo contrario informo con un printf que no hay lugar disponible
     * \return
     *
     */
void alta(EPersona vec[],int tam)
{
    EPersona nuevaPersona;
    int valido=3;
    int indice;
    int estado;
    char dni[10];

    system("cls");
    printf(" Agregar Persona\n\n");

    indice = buscarLibre(vec, tam);

    if(indice != -1)
    {
        printf("ingrese el DNI\n");
        fflush(stdin);
        gets(dni);

        valido = validarNumero(dni);
        if(valido !=1)
        {
            printf("Solo numeros!!\n");
        }
        else
        {
        estado = buscarPersona(vec, tam, dni);
        if(estado != -1)
        {
        printf("\n el DNI ya corresponde a una persona ");
        mostrarPersona(vec[estado]);
        }
        else
        {
            nuevaPersona.estado = 1;
            strcpy(nuevaPersona.dni,dni);

            printf(" ingrese el nombre\n");
            fflush(stdin);
            gets(nuevaPersona.nombre);

            printf("ingrese la edad");
            scanf("%d", &nuevaPersona.edad);

            vec[indice] = nuevaPersona;

            printf("la alta fue exitosa");
        }
         }
   }
      else
      {
        printf("\n no hay lugar disponible\n");
      }
}


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param pido por printf el dni y lo asigno a la cadena dni
 * \param asigno a la variable encientra el valor que resulta de la funcion buscarPersona
 * \param si encuentra es igual a -1 muestro por printf que el dni ingresado no corresponde a una persona
 * \param de lo contrario llamo a la funcion mostrarPersona y le pregunto al usuario mediante un printf si desea realizar la baja y que presione 's' o 'n' tomo el valor y lo asigno a la variable confirmar
 * \param si confirmar es = a 's' asigno a el estado de la estructura un 0 para indicar que es devuelta un espacio libre donde cargar datos e informo al  usuario que la baja fue exitosa
 * \param de lo contrario informo mediante un printf al usuario la cancelacion de la baja
 * \return
 *
 */
void baja(EPersona vec[],int tam)
{
    char dni[10];
    int encuentra;
    char confirmar;


    printf("ingrese el DNI\n");
    fflush(stdin);
    gets(dni);


    encuentra = buscarPersona(vec,tam,dni);

    if(encuentra== -1)
    {
        printf("el DNI no corresponde a una persona\n");
    }
    else
    {
        mostrarPersona(vec[encuentra]);

        printf("quiere realizar la baja ? s/n \n");
        fflush(stdin);
        scanf("%c", &confirmar);

        if(confirmar == 's')
        {
            vec[encuentra].estado = 0;
            printf("la baja fue exitosa !! \n");
        }
        else
        {
            printf("baja cancelada \n");
        }
   }
}


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param hago un for que recorra la estructura
 * \param dentro de el primer for hago otro que recorra la estructura pero un lugar mas adelante (burbujeo)
 * \param comparo en un if el valor de nombre en la posicion 'i' con el de nombre en la posicion 'j'
 * \param si el resultado es mayor a 0 la variable auxiliar toma el valor de vec en la posicion 'i', vec en la posicion 'i' toma el valor de vec en la posicion 'j' y vec en la posicion de 'j' toma el valor de auxiliar
 * \param de lo contrario comparo con un if el valor de nombre en la posicion 'i' con el de nombre en la posicion 'j'
 * \param si el resultado es = a 0 y vec en la posicion 'i'.dni es menor a vec en la posicion 'j'.dni la variable auxiliar toma el valor de vec en la posicion 'i', vec en la posicion 'i' toma el valor de vec en la posicion 'j' y vec en la posicion de 'j' toma el valor de auxiliar
 * \param
 * \return
 *
 */
void ordenarGente(EPersona vec[], int tam)
    {
        EPersona auxiliar;
        int i;
        int j;

        for(i=0;i<tam;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(strcmp(vec[i].nombre, vec[j].nombre)>0)
                {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;

                }
                else
                {
                if(strcmp(vec[i].nombre, vec[j].nombre)== 0)
                   {
                    if(vec[i].dni < vec[j].dni)
                    {
                     auxiliar = vec[i];
                     vec[i] = vec[j];
                     vec[j] = auxiliar;
                    }
                  }


                }

            }
        }
    }


/** \brief pide al usuario un vector de la estructura EPersona y un entero
 *
 * \param  hago un for que recorra la estructura
 * \param dentro del for pregunto si vec en la posicion 'j'.edad es mayor a 0 y si vec en la posicion 'j'.edad es menor o igual a 18 le sumo 1 a la variable rango1
 * \param si vec en la posicion 'j'.edad es mayor o igual a 19 y si vec en la posicion 'j'.edad es menor o igual a 35 le sumo 1 a la variable rango2
 * \param si vec en la posicion 'j'.edad es mayor o igual a 35 le sumo 1 a la variable rango3
 * \param si rango 1 es mayor o igual a ranngo2 y rango1 es mayor o igual a rango3 la variable mayor toma el valor de rango1
 * \param de lo contrario si rango2 es mayor o igual a ranngo1 y rango2 es mayor o igual a rango3 la variable mayor toma el valor de rango2
 * \param de lo contrario la variable mayor toma el valor de rango3
 * \param hago un for que recorra la estructura
 * \param si 'i' es menor o igual rango1 hago un printf con un*
 * \param si 'i' es menor o igual a rango2 cambio el volor de la vandera a 1 y hago un printf con una tabulacion y un *
 * \param si 'i' es menor o igual a rango3 pregunto el valor de la vandera
 * \param si el valor de la vandera es = a 0 realizo un printf con 2 tabulaciones y un *
 * \param si el valor de la vandera es = a 1 realizo un printf con una tabulacion y un *
 * \return
 *
 */
void graficar(EPersona vec[], int tam)
    {
        system("cls");
       int i;
       int j;
       int rango1=0;
       int rango2=0;
       int rango3=0;
       int flag=0;
       int mayor;

       for(j=0;j<tam;j++)
       {
           if(vec[j].edad > 0 && vec[j].edad <= 18 )
           {
               rango1 ++;
           }

           if(vec[j].edad >= 19 && vec[j].edad <= 35)
           {
               rango2 ++;
           }

           if(vec[j].edad > 35)
           {
               rango3 ++;
           }
       }

    if(rango1 >= rango2 && rango1 >= rango3)
    {
        mayor = rango1;
    }
    else
    {
        if(rango2 >= rango1 && rango2 >= rango3)
        {
            mayor = rango2;
        }
        else
        {
        mayor = rango3;
        }
    }

    for(i=mayor; i>0; i--)
        {
        if(i<= rango1){
            printf("*");
        }
        if(i<= rango2)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= rango3)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        printf("\n");
    }
    printf("<18\t19-35\t>35 \n");

}



/** \brief pide al usuario una cadena de caracteres
 *
 * \param realizo un for que intere una cantidad de veces iguales al tamaño de la cadena
 * \param si dni en la posicion de 'i' es distinto a sidigit cambio el valor de la variable fin a 0
 * \return variable fin
 *
 */

int validarNumero(char dni[])
    {
        int i;
        int fin=1;
        for(i=0;i<strlen(dni);i++)
        {
            if(!(isdigit(dni[i])))
            {
                fin = 0;
                break;
            }
        }
        return fin;
    }
