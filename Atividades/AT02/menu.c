#include <stdio.h>
#include <stdlib.h>

int main(void){
	
    int input;
    int a;
    int b;
    int c;

    puts("Escolha uma operação para dois inteiros de sua escolha:\n");
    puts("0 - Sair\n");
    puts("1 - Somar\n");
    puts("2 - Subtrair\n");
    puts("3 - Multiplicar\n");
    puts("4 - Dividir\n");

    scanf("%d", &input);
    
    puts("Escolha dois inteiros:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    switch (input){

         case 0:
         return 0;
         break;

         case 1 :
         c = a + b;
         printf ("%d", c);
         break;
    
         case 2 :
         c = a - b;
         printf ("%d", c);
         break;
    
         case 3 :
         c = a * b;
         printf ("%d", c);
         break;
    
         case 4 :
         c = a / b;
         printf ("%d", c);
         break;
    
         default :
         printf ("Valor invalido!\n");

    }
    

}
