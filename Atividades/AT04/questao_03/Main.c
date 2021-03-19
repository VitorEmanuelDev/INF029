#include<stdio.h>
#include "Functions.h"

int main(){

    int num, fator;
    printf("Digite um número\n");
    scanf("%d", &num);

    if(num < 0){
       
        printf("Não é possível calcular o fatorial de um número negativo\n");
        return 0;    

    }

        fator = factorial(num);
        printf("O fatorial do valor informado é %d.", fator);   
    
    return 0;

}
