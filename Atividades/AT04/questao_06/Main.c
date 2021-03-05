#include <stdio.h>

#include "Functions.h"

int main(void)
{
    char array[4];

    printf("Informe três caracteres e aperte enter: ");

    ler3Letras(array);
 
    printf("[");
    for(int i = 0; i < 4; i++){
    
        printf(" %c", array[i]);

    }
    printf("]\n");

    return 0;

}

