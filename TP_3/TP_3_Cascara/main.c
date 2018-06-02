#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 50


EMovie* new_Movie();

void alta(EMovie*,int);

void baja(EMovie*,int);

int buscarPelicula(EMovie*,int,char);

int buscarLibre(EMovie*, int);

int cargarPelicula(EMovie*, int, char*);

void inicializarPeliculas(EMovie*,int);

EMovie* newArrayPeliculas(int);

EMovie* new_Pelicula_Param(int,char*,float);

void mostrarPelicula(EMovie*);


int main()
{
    EMovie* peli;
    EMovie* unaPeli;
    int cantidad;
    char seguir='s';
    int opcion=0;


    peli = newArrayPeliculas(TAM);


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                alta(peli,TAM);
                system("pause");
                break;
            case 2:
                baja(peli,TAM);
                break;
            case 3:
                mostrarPelicula(peli);
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

     cantidad = cargarPelicula(peli,TAM,"listarPeliculas.bin");

    return 0;
}


EMovie* new_Movie()
{
    EMovie* nuevaMovie;

    nuevaMovie = (EMovie*)malloc(sizeof(EMovie));
    if(nuevaMovie != NULL)
    {
        strcpy(nuevaMovie->descripcion,"" );
        nuevaMovie->duracion =0;
        strcpy(nuevaMovie->genero,"");
        strcpy(nuevaMovie->linkImagen,"");
        nuevaMovie->puntaje =0;
        strcpy(nuevaMovie->titulo,"");
        nuevaMovie->estado =0;
    }
    return nuevaMovie;
}

void alta(EMovie* peli,int tam)
{
    int indice;
    EMovie* nuevaPeli;

    nuevaPeli = (EMovie*)malloc(sizeof(EMovie));

    system("cls");
    printf("Agregar Pelicula\n");

    indice = buscarLibre(peli,tam);

    if(indice != -1)
    {
        printf("ingrese Titulo\n");
        fflush(stdin);
        gets(peli->titulo);

        printf("ingrese Genero\n");
        fflush(stdin);
        gets(peli->genero);

        printf("ingrese la Duracion\n");
        scanf("%d",&peli->duracion);

        printf("ingrese la Descripcion\n");
        fflush(stdin);
        gets(peli->descripcion);

        printf("ingrese el puntaje\n");
        scanf("%d",&peli->puntaje);

        peli->estado=1;


        printf("la alta fue exitosa");


    }
    free(nuevaPeli);

}

int buscarLibre(EMovie* pelicula, int tam)
{
    int indice= -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if((pelicula+i)->estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarPelicula(EMovie* peli,int tam,char nombre)
{
    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(peli->estado == 1 && peli->titulo == nombre)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int cargarPelicula(EMovie* peli, int tam, char* path)
    {
        FILE* f;
        int indice;
        EMovie peliAux;
        int cant;
        int total = 0;

        f = fopen(path, "rb");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            exit(1);
        }


        while(!feof(f))
        {
                indice = buscarLibre(peli, tam);
                if(indice == -1)
                {
                    printf("no hay mas lugar\n");
                    break;
                }
                else
                {
                    cant = fread(&peliAux, sizeof(EMovie),1,f);

                    if(cant != 1)
                    {
                        if(feof(f))
                        {
                            break;
                        }
                        else
                        {
                            printf("no se pudo leer el ultimo registro\n");
                            break;
                        }
                    }
                    *(peli+indice) = peliAux;
                    total++;
                    //indice = buscarLibre(peli,tam);
                }
        }
        fclose(f);
        return total;
    }

void inicializarPeliculas(EMovie* peliculas,int tam)
{
    int i;
    if(peliculas != NULL && tam > 0)
    {
        for(i=0 ;i<tam; i++)
        {
            (peliculas+i)->estado = 0;
        }
    }
}

EMovie* newArrayPeliculas(int tam)
{
    EMovie* array;

    if(tam > 0)
    {
        array = (EMovie*) malloc(tam * sizeof(EMovie));

        if(array != NULL)
        {
            inicializarPeliculas(array,tam);
        }
    }
    return array;
}

void mostrarPelicula(EMovie* peli)
{
    if(peli != NULL)
    {
        printf("%s %s %d %s %d\n", peli->titulo, peli->genero, peli->duracion, peli->descripcion, peli->puntaje);
    }
}

void baja(EMovie* peli,int tam)
{
    char Ptitulo[20];
    int encuentra;
    char confirmar;

    printf("ingrese el titulo\n");
    fflush(stdin);
    gets(Ptitulo);


    encuentra = buscarPelicula(peli,tam,peli->titulo);

    if(encuentra == -1)
    {
        printf("el titulo no corresponde a una pelicula\n");
    }
    else
    {
        mostrarPelicula(peli+encuentra);

        printf("quiere realizar la baja = s/n \n");
        fflush(stdin);
        scanf("%c", &confirmar);

        if(confirmar == 's')
        {
            (peli+encuentra)->estado = 0;
            printf("la baja fue exitosa !!\n");
        }
        else
        {
            printf("baja cancelada \n");
        }
    }
}


//EMovie* new_Pelicula_Param(int,char*,float)
