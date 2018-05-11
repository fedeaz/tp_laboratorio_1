#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define tam 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona gente[tam];

    inicializarPersona(gente, tam);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                alta(gente, tam);
                system("pause");
                break;
            case 2:
                baja(gente,tam);
                system("pause");
                break;
            case 3:
                printf("imprimir lista ordenada por nombre\n");
                mostrarPersonas(gente, tam);
                break;
            case 4:
                printf("imprimir grafico de edades\n");

                graficar(gente,tam);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
