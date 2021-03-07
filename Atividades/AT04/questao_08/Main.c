#include <stdio.h>
#include <stdlib.h>



typedef struct cliente
{
    char nome[255];
    char dataNascimento[11];
    char cpf[12];
    char sexo[30];
    
}perfil;

void cadastroCliente(perfil *p)
{

    scanf("%s", p->nome);
    scanf("%s", p->dataNascimento);
    scanf("%s", p->cpf);
    scanf("%s", p->sexo);
    
    //return p;

}
 
int main(void)
{
    perfil perfil_teste;

    printf("Informe o nome, a data de nascimento, o cpf e o sexo:\n");
    cadastroCliente(&perfil_teste);

    printf("%s\n", perfil_teste.nome);
    printf("%s\n", perfil_teste.dataNascimento);
    printf("%s\n", perfil_teste.cpf);
    printf("%s\n", perfil_teste.sexo);
 
    return 0;

}

