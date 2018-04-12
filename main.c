#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

int main()
{
    char seguir='s';
    int opcion=0;
    float operando1 = 0;
    float operando2 = 0;
    float resultado;
    float resultadoF;
    int resultadoFact;


    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando A= %.2f\n", operando1);
        printf("2- Ingresar 2do operando B= %.2f\n", operando2);
        printf("3- Calcular la suma %.2f + %.2f\n", operando1, operando2);
        printf("4- Calcular la resta %.2f - %.2f\n", operando1, operando2);
        printf("5- Calcular la division %.2f / %.2f\n", operando1, operando2);
        printf("6- Calcular la multiplicacion %.2f * %.2f\n", operando1, operando2);
        printf("7- Calcular el factorial %.2f ! \n", operando1);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf(" ingrese el 1er operando ");
            scanf("%f", &operando1);
            printf(" el 1er operando es %.2f \n", operando1 );
                break;
            case 2:
                printf(" ingrese el 2do operanod ");
            scanf("%f", &operando2);
            printf(" el 2do operando es %.2f \n", operando2 );
                break;
            case 3:
                resultado = suma(operando1, operando2);
                printf(" la suma entre los 2 operandos es %.2f \n", resultado);
                break;
            case 4:
                resultado = resta(operando1, operando2);
                printf(" la resta entre los 2 operandos es %.2f \n", resultado);
                break;
            case 5:
                if (operando1 == 0 || operando2 == 0)
                {
                    printf(" no se puede dividir por 0 \n");
                    break;
                }
                else
                {
                resultadoF = division(operando1, operando2);
                printf(" la divicion entre los 2 operandos es %.2f \n", resultadoF);
                break;
                }

            case 6:
                resultado = multiplicar(operando1, operando2);
                printf(" la multiplicacion entre los 2 operandos es %.2f \n", resultado);
                break;

            case 7:
                if(operando1 < 0)
                {
                    printf("la operacion no se puede realizar con un numero negativo \n");
                    break;
                }
                if(operando1 >= 13)
                {
                   printf(" no se puede realizar el factorial de un numero tan grande \n");
                   break;
                }
                else
                {
                resultadoFact = factorial(operando1);
                printf(" el factorial del primer operando es %d \n", resultadoFact);
                break;
                }
            case 8:
                resultado = suma(operando1, operando2);
                printf(" la suma entre los 2 operandos es %.2f \n", resultado);

                resultado = resta(operando1, operando2);
                printf(" la resta entre los 2 operandos es %.2f \n", resultado);

                if (operando1 == 0 || operando2 == 0)
                    {
                    printf(" no se puede dividir por 0 \n");
                    }
                else
                {
                resultadoF = division(operando1, operando2);
                printf(" la divicion entre los 2 operandos es %.2f \n", resultadoF);
                }

                resultado = multiplicar(operando1, operando2);
                printf(" la multiplicacion entre los 2 operandos es %.2f \n", resultado);

                if(operando1 < 0)
                {
                    printf("la operacion no se puede realizar con un numero negativo \n");
                    break;
                }
                if(operando1 >= 13)
                {
                   printf(" no se puede realizar el factorial de un numero tan grande");
                }
                else
                {
                resultadoFact = factorial(operando1);
                printf(" el factorial del primer operando es %d \n", resultadoFact);
                break;
                }
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
