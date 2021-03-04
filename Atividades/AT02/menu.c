#include <stdio.h>
#include <stdlib.h>

int main(void){
	
    int input;
    float a, b, c;
    int continua = 1;
    

    while(continua != 0){
	    
        puts("\nEscolha uma operação para dois números de sua escolha:\n");
        puts("0 - Sair\n");
        puts("1 - Somar\n");
        puts("2 - Subtrair\n");
        puts("3 - Multiplicar\n");
        puts("4 - Dividir\n");
    
        scanf("%d", &input);

        if(input == 0){
    
	    continua = 0;
            return 0;
    
        }
    
        puts("\nEscolha dois inteiros:\n");
        scanf("%f", &a);
        scanf("%f", &b);

        switch (input){

           // case 0:
           // return 0;
           // break;

            case 1 :
            c = a + b;
            printf ("%.2f", c);
            break;
    
            case 2 :
            c = a - b;
            printf ("%.2f", c);
            break;
    
            case 3 :
            c = a * b;
            printf ("%.2f", c);
            break;
    
            case 4 :
            c = a / b;
            printf ("%.2f", c);
            break;
    
            default :
            printf ("Valor invalido!\n");

        }

        
    }

}
