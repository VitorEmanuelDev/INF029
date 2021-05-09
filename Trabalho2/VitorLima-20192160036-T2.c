#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "VitorLima-20192160036-T2.h"

Principal vetorPrincipal[TAM];

void dobrar(int *x)
{

    *x = *x * 2;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/
void inicializar(){
  int i;

  for (i = 0; i < TAM; i++){
    vetorPrincipal[i].auxiliar = NULL;
    vetorPrincipal[i].qtd = 0;
    vetorPrincipal[i].tamanho = 0;
  }
}

int posicaoInvalida(int posicao){
    if (posicao < 1 || posicao > TAM)
        return 1;
    else
        return 0;
}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

	  if (tamanho < 1 )
	    return TAMANHO_INVALIDO;

	  if (posicaoInvalida(posicao))
	    return POSICAO_INVALIDA;

	  posicao -= 1;

	  if (vetorPrincipal[posicao].auxiliar != NULL)
	    return JA_TEM_ESTRUTURA_AUXILIAR;

	  vetorPrincipal[posicao].auxiliar = (int*)malloc(tamanho*sizeof(int));

	  if (vetorPrincipal[posicao].auxiliar == NULL)
	      return SEM_ESPACO_DE_MEMORIA;

	  vetorPrincipal[posicao].tamanho = tamanho;

	  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{

	if (posicaoInvalida(posicao))
	        return POSICAO_INVALIDA;

	    posicao -= 1;

	    if (vetorPrincipal[posicao].auxiliar == NULL )
	        return SEM_ESTRUTURA_AUXILIAR;

	    int qtd = vetorPrincipal[posicao].qtd;

	    if (qtd >= vetorPrincipal[posicao].tamanho)
	      return SEM_ESPACO;

	    vetorPrincipal[posicao].auxiliar[qtd] = valor;
	    vetorPrincipal[posicao].qtd++;

	    return SUCESSO;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{

    if (posicaoInvalida(posicao) == 1)
        return POSICAO_INVALIDA;

    posicao -= 1;

    if (vetorPrincipal[posicao].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[posicao].qtd--;

    return SUCESSO;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
	 int i, j;
	    int existe = 0;
	    int aux;

	    if (posicaoInvalida(posicao))
	        return POSICAO_INVALIDA;

	    posicao -= 1;

	    if (vetorPrincipal[posicao].auxiliar == NULL)
	        return SEM_ESTRUTURA_AUXILIAR;

	    if (vetorPrincipal[posicao].qtd == 0)
	        return ESTRUTURA_AUXILIAR_VAZIA;

	    int qtd = vetorPrincipal[posicao].qtd;

	    if (qtd == 1 && vetorPrincipal[posicao].auxiliar[0] == valor)
	      existe = 1;

	    else
	      for (i = 0; i < qtd-1; i++)

	        if (vetorPrincipal[posicao].auxiliar[i] == valor){
	          aux = vetorPrincipal[posicao].auxiliar[i];
	          vetorPrincipal[posicao].auxiliar[i] = vetorPrincipal[posicao].auxiliar[i+1];
	          vetorPrincipal[posicao].auxiliar[i+1] = aux;

	          existe = 1;
	        }

	    if (existe == 0)
	        return NUMERO_INEXISTENTE;
	    else
	      vetorPrincipal[posicao].qtd--;

	    return SUCESSO;

}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}

