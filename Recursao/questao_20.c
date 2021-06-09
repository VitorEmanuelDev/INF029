/*20. Um fatorial exponencial é um inteiro positivo N elevado à potência de N-1, que por
sua vez é elevado à potência de N-2 e assim em diante. Ou seja,
Faça uma função recursiva que receba um número inteiro positivo N e retorne o
fatorial exponencial desse número.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double exponencial(double valor);

int main(void){

    double valor;

    printf("Informe um valor");
    scanf("%lf", &valor);

    printf("fatorial de %.0lf = %0.lf\n", valor, exponencial(valor));

    return 0;
}

double exponencial(double valor){

    if(valor == 1)
        return 1;

    return pow(valor, exponencial(valor - 1));
}

