#include <stdio.h>

#include "Functions.h"

int main(void)
{
    int a, b, c;

    printf("Informe dois números: ");
    scanf("%d %d", &a, &b);
	
    c = Sum(a, b);

    printf("%d + %d = %d", a, b, c);
    return 0;

}

