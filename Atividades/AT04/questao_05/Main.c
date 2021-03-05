#include <stdio.h>

#include "Functions.h"

struct numeros{

    int array[4];

};

int main(void){

    struct numeros num[4];

    printf("Informe três números: ");

    for(int i = 0; i < 4; i++){

        scanf("%d", &array[i].num);

   }

    lerArray(num);
    
    printf("[");
    for(int i = 0; i < 3; i++){
    
	printf(" %d", array[i].num);    
    
    }
    printf(" ]");

    return 0;

}

