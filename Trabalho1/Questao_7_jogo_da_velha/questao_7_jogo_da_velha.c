#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char quadrado[10]; /*= { 'O', '1', '2', '3', '4', '5', '6', '7', '8', '9' };*/

int verifica_vitoria();
void quadro();

int main()
{
    int jogador = 1, i;
    char escolha[3];
    int numero;
    char sinal;

    do
    {
        quadro();
        jogador = (jogador % 2) ? 1 : 2;

        printf("Jogador %d, informe uma posição:  ", jogador);
        scanf("%s", escolha);

		if(strcmp(escolha, "A1") == 0)
			numero = 1;
		else if(strcmp(escolha, "A2") == 0)
			numero = 2;
		else if(strcmp(escolha, "A3") == 0)
			numero = 3;
		else if(strcmp(escolha, "B1") == 0)
			numero = 4;
		else if(strcmp(escolha, "B2") == 0)
			numero = 5;
		else if(strcmp(escolha, "B3") == 0)
			numero = 6;
		else if(strcmp(escolha, "C1") == 0)
			numero = 7;
		else if(strcmp(escolha, "C2") == 0)
			numero = 8;
		else if(strcmp(escolha, "C3") == 0)
			numero = 9;
		else
			printf("Escolha inválida");


        sinal = (jogador == 1) ? 'X' : 'O';

        if (numero == 1)
            quadrado[1] = sinal;

        else if (numero == 2)
            quadrado[2] = sinal;

        else if (numero == 3)
            quadrado[3] = sinal;

        else if (numero == 4)
            quadrado[4] = sinal;

        else if (numero == 5)
            quadrado[5] = sinal;

        else if (numero == 6)
            quadrado[6] = sinal;

        else if (numero == 7)
            quadrado[7] = sinal;

        else if (numero == 8)
            quadrado[8] = sinal;

        else if (numero == 9)
            quadrado[9] = sinal;

        else
        {
            printf("Escolha inválida ");

            jogador--;
            setbuf(stdin, NULL);
        }

        i = verifica_vitoria();

        jogador++;

    }while (i == -1);

    quadro();

    if (i == 1)
        printf("Jogador %d ganhou ", --jogador);
    else
        printf("Empate");

    setbuf(stdin, NULL);

    return 0;
}


int verifica_vitoria()
{
    if (quadrado[1] == quadrado[2] && quadrado[2] == quadrado[3])
        return 1;

    else if (quadrado[4] == quadrado[5] && quadrado[5] == quadrado[6])
        return 1;

    else if (quadrado[7] == quadrado[8] && quadrado[8] == quadrado[9])
        return 1;

    else if (quadrado[1] == quadrado[4] && quadrado[4] == quadrado[7])
        return 1;

    else if (quadrado[2] == quadrado[5] && quadrado[5] == quadrado[8])
        return 1;

    else if (quadrado[3] == quadrado[6] && quadrado[6] == quadrado[9])
        return 1;

    else if (quadrado[1] == quadrado[5] && quadrado[5] == quadrado[9])
        return 1;

    else if (quadrado[3] == quadrado[5] && quadrado[5] == quadrado[7])
        return 1;

    else if (quadrado[1] != '\0' && quadrado[2] != '\0' && quadrado[3] != '\0' &&
        quadrado[4] != '\0' && quadrado[5] != '\0' && quadrado[6] != '\0' && quadrado[7]
        != '\0' && quadrado[8] != '\0' && quadrado[9] != '\0')

        return 0;
    else
        return  -1;
}


void quadro()
{
	system("clear");
    printf("\n\n\tJogo da velha\n\n");

    printf("Jogador 1 (X)  -  Jogador 2 (O)\n\n\n");

    printf("  1     2     3  \n");
    printf("     |     |     \n");
    printf("A  %c  |  %c  |  %c \n", quadrado[1], quadrado[2], quadrado[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("B  %c  |  %c  |  %c \n", quadrado[4], quadrado[5], quadrado[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("C  %c  |  %c  |  %c \n", quadrado[7], quadrado[8], quadrado[9]);

    printf("     |     |     \n\n");
}

