#include <stdio.h>

#include "Functions.h"

int main(void)
{
    int array[3];

    printf("Informe três números: ");

    for(int i = 0; i < 3; i++){

        scanf("%d", &array[i]);

    }

    lerArray(array);
    
    printf("[");
    for(int i = 0; i < 3; i++){
    
	printf(" %d", array[i]);    
    
    }
    printf(" ]");

    return 0;

}

