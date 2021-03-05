#include <stdio.h>

#include "Functions.h"
#define ROWS 3
#define COLS 20

int main(void)
{
    char palavras[ROWS][COLS];
    
    printf("Informe três palavras: ");

    ler3Palavras(palavras);
 
    printf("[");
    for(int i = 0; i < 3; i++){
    
        printf(" %s", palavras[i]);

    }
    printf(" ]\n");

    return 0;

}

