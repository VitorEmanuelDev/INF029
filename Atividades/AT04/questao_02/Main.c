#include <stdio.h>

#include "Functions.h"

int main(void)
{
    int a, b, c, d;

    printf("Informe três números: ");
    scanf("%d %d %d", &a, &b, &c);
	
    d = Subtract(a, b, c);

    printf("%d - %d - %d = %d", a, b, c, d);
    return 0;

}

