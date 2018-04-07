#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED





int suma (int op1, int op2)
    {
        int resultado ;         /*se crea la variable resultado*/
        resultado = op1 + op2;   /*hace la suma entre los 2 operandos y asigna a resultado ese valor */
        return resultado;        /*devuelve como valor la variable resultado*/
    }


int resta (int op1, int op2)
    {
        int resultado ;          /*se crea la variable resultado*/
        resultado = op1 - op2;   /*hace la resta entre los 2 operandos y asigna a resultado ese valor */
        return resultado;       /*devuelve como valor la variable resultado*/
    }


float division (int op1, int op2)
    {
        float resultado ;             /*se crea la variable resultado*/
        resultado =(float)op1 / op2;  /*hace la division entre los 2 operandos y asigna a resultado ese valor*/
        return resultado;             /*devuelve como valor la variable resultado*/
    }


int multiplicar (int op1, int op2)
    {
        int resultado ;              /*se crea la variable resultado*/
        resultado = op1 * op2;       /*hace la multiplicación entre los 2 operandos y asigna a resultado ese valor */
        return resultado;            /*devuelve como valor la variable resultado*/
    }


int factorial (int op1)      /*hace el factorial del primer operando*/
    {
        int i;                  /*se crea la variable i*/
        int resultado = 1;           /*se crea la variable resultado y se le da el valor 1*/
        for(i = 1; i <= op1 ; i++)      /* se le asigna a i el valor 1*/ /*el for se va a ejecutar mientras i no sea mayor o igual a el operador 1*/ /*se le suma 1 a i*/
            {
                resultado = resultado * i; /*se le asigna a la variable resultado, el producto de la multipolicación entre resultado y la variable i*/
            }
            return resultado;       /*devuelve como valor la variable resultado*/
    }


#endif // FUNCIONES_H_INCLUDED
