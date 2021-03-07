#include <stdio.h>
#include <stdlib.h>



typedef struct cliente
{
    char nome[25];
    char dataNascimento[11];
    char cpf[12];
    char sexo[1];
    
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

    printf("NOME: %s\n", perfil_teste.nome);
    printf("NASCIMENTO: %s\n", perfil_teste.dataNascimento);
    printf("CPF: %s\n", perfil_teste.cpf);
    printf("SEXO %s\n", perfil_teste.sexo);
 
    return 0;

}

