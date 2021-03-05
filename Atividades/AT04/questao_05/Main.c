#include <stdio.h>

#include "Functions.h"

struct numeros {

  int array[4];

};

int main(void)
{
    struct numeros num;

    printf("Informe quatro números: ");

    ler4Numeros(num.array);
 
    printf("[");
    for(int i = 0; i < 4; i++){
    
        printf(" %d", num.array[i]);

    }
    printf(" ]");

    return 0;

}

