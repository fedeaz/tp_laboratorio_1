#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float suma (float op1, float op2) /**< solicita 2 numeros al usuario y devuelve como resultado la suma entre estos */
    {
        float resultado ;         /*se crea la variable resultado*/
        resultado = op1 + op2;   /*hace la suma entre los 2 operandos y asigna a resultado ese valor */
        return resultado;        /*devuelve como valor la variable resultado*/
    }


float resta (float op1, float op2) /**< solicita 2 numeros al usuario y devuelve como resultado la resta entre estos */
    {
        float resultado ;          /*se crea la variable resultado*/
        resultado = op1 - op2;   /*hace la resta entre los 2 operandos y asigna a resultado ese valor */
        return resultado;       /*devuelve como valor la variable resultado*/
    }


float division (float op1, float op2) /**< solicita 2 numeros al usuario y devuelve como resultado el cociente entre estos */
    {
        float resultado ;             /*se crea la variable resultado*/
        resultado =(float)op1 / op2;  /*hace la division entre los 2 operandos y asigna a resultado ese valor*/
        return resultado;             /*devuelve como valor la variable resultado*/
    }


float multiplicar (float op1, float op2) /**< solicita 2 numeros al usuario y devuelve como resultado el producto de estos */
    {
        float resultado ;              /*se crea la variable resultado*/
        resultado = op2 * op1;       /*hace la multiplicación entre los 2 operandos y asigna a resultado ese valor */
        return resultado;            /*devuelve como valor la variable resultado*/
    }


int factorial (int op1) /**< solicita 1 numero al usuario y devuelve como resultado el factorial de este */
    {
        int i;                  /*se crea la variable i*/
        unsigned int resultado = 1;           /*se crea la variable resultado y se le da el valor 1*/
        for(i = op1; i> 0; i -- )     /*se crea la interación*/ /* se le asigna a i el valor 1*/ /*el for se va a ejecutar mientras i no sea mayor o igual a el operador 1*/ /*se le suma 1 a i*/
            {
                resultado = resultado * i; /*se le asigna a la variable resultado, el producto de la multipolicación entre resultado y la variable i*/
            }
            return resultado;       /*devuelve como valor la variable resultado*/
    }

#endif // FUNCIONES_H_INCLUDED*/
