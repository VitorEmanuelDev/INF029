#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TURMA 6

typedef struct dma {
  int dia;
  int mes;
  int ano; 
} Data; 

typedef struct dados{

  char matricula[12];
  char nome[30];
  char sexo;
  Data data_nascimento;
  char cpf[12];

}Aluno;

int mostrarMenu(int escolha);
int cadastrarAlunos(int quantidade_alunos, Aluno cadastro_alunos[]);
void listarAlunos(int quantidade_alunos, Aluno cadastro_alunos[]);
void atualizarCadastro(int quantidade_alunos, Aluno cadastro_alunos[]);
int removerAluno(int quantidade_alunos, Aluno cadastro_alunos[]);
int validarMatricula(char matricula[]);
int validarNome(char nome[]);
int validarSexo(char sexo);
int validarCPF(char cpf[]);
int validarData(int quantidade_alunos, Aluno data_nascimento[]);


int mostrarMenu(int opcao){    

	printf("************PROJETO ESCOLA************\n");
	printf("0 - Sair\n");
	printf("1 - Cadastro de Alunos\n");
	printf("2 - Cadastro de Professores\n");
	printf("3 - Cadastro de Disciplinas\n");
	scanf("%d",&opcao);
	getchar();

	return opcao;
}


int main(void){    
 
  Aluno aluno; 
  Aluno cadastro_alunos[TURMA]; 
 
  int quantidade_alunos = 0; 
  bool em_uso = true;
  int removidos = 0;
  
  int escolha;
    

  while(em_uso){
  
    escolha = mostrarMenu();
 
    switch(escolha){
    
      case 0:{
      
		printf("Sair do programa.\n");
		exit(0);
		break;
        
      }case 1:{
      
        if(quantidade_alunos < TURMA) {
	cadastrarAlunos(quantidade_alunos, cadastro_alunos);
	
	quantidade_alunos++;
	
		printf("\nCadastro realizado\n");
		break;
	
	} else {
	
		printf("\Vagas esgotadas\n");
		break;
				}
        
      }case 2: {
      
	        listarAlunos(quantidade_alunos, cadastro_alunos);
		break;
		
      }case 3: {
		if(quantidade_alunos = 0) {
		
			printf("\nCadastro vazio.\n");
			
		} else {
		
			atualizarCadastro(quantidade_alunos, cadastro_alunos);
		}	
		
		break;
		
      }case 4: {
      
		if(quantidade_alunos <= 0) {
		
			printf("\nCadastro vazio.\n");
			
		} else {
		
			removido = removerAluno(quantidade_alunos, cadastro_alunos);
			quantidade_alunos--;
			
			printf("\nAluno(a) %d removido(a).\n", removido+1);
		}
		
			break;
	        }

	default: {
			printf("\nInput inválido\n");
			break;
	        }
	    }
        }

	return 1;
}


void cadastrarAlunos(int quantidade_alunos, Aluno cadastro_alunos[]) {


	printf("************CADASTRO ALUNOS************\n");
	
	printf("\nInforme a matrícula:\n ");
	fgets(estudante[quantidade_alunos].matricula, 12, stdin);
	getchar();
	
	bool invalido = true; 
	
	while(invalido) {
	
		if(validarMatricula(cadastro_alunos[quantidade_alunos].matricula) != 1) {
		
			printf("\nMatrícula inválida! Informe novamente.\n");
			fgets(cadastro_alunos[quantidade_alunos].matricula, 12, stdin);
			setbuf(stdin, NULL);
			
		} else {
		
		       break;
		     
		}
	}

	printf("\nInforme o nome: ");
	fgets(cadastro_alunos[quantidade_alunos].nome, 25, stdin);
        setbuf(stdin, NULL);
		
	while(invalido) {
	
		if(validarNome(cadastro_alunos[quantidade_alunos].nome) != 1) {
		
			printf("\nNome inválido. Informe novamente.\n");
			fgets(cadastro_alunos[quantidade_alunos].nome, 25, stdin);
			setbuf(stdin, NULL);
			
		} else {
		
		       break;
			
		}
	}
	
	printf("\nInforme o sexo (M, F ou O): ");
	scanf("%c", &cadastro_alunos[quantidade_alunos].sexo);
	setbuf(stdin, NULL);
	
	while(invalido) {
	
		if(validarSexo(cadastro_alunos[quantidade_alunos].sexo) != 1) {
		
			printf("\nSexo inválido. Informe novamente.\n");
			scanf("%c", &cadastro_alunos[quantidade_alunos].sexo);
			setbuf(stdin, NULL);
			
		} else {
		
			break;
			
		}
	}

	printf("\nInforme a data de nascimento do cliente (dd/mm/yyyy):\n");
	printf("dia:\n");
	scanf("%d", &cadastro_alunos[quantidade_alunos].data_nascimento.dia);
	setbuf(stdin, NULL);
	printf("\nmes:\n");
	scanf("%d", &cadastro_alunos[quantidade_alunos].data_nascimento.mes);
	setbuf(stdin, NULL);
	printf("\nano:\n");
	scanf("%d", &cadastro_alunos[quantidade_alunos].data_nascimento.ano);
	setbuf(stdin, NULL);
	
	while(invalido) {
	
		if(validarData(estudante[quantidade_alunos].Data) != 1) {
		
			printf("\nData inválida! Informe novamente.\n");
			printf("dia:\n");
			scanf("%d", &cadastro_alunos[quantidade_alunos].data_nascimento. dia);
			setbuf(stdin, NULL);
			printf("\nmes:\n");
			scanf("%d", &cadastro_alunos[quantidade_alunos].data_nascimento.mes);
			setbuf(stdin, NULL);
			printf("\nano:\n");
			scanf("%d", &cadastro_alunos[quantidade_alunos].data_nascimento.ano);
			setbuf(stdin, NULL);
			
		} else {
		
			break;
			
		}
	}

	printf("\nInforme o CPF: ");
	fgets(cadastro_alunos[quantidade_alunos].cpf, 12, stdin);
	setbuf(stdin, NULL);
	
	while(invalido) {
	
		if(validarCPF(cadastro_alunos[quantidade_alunos].cpf) != 1) {
		
			printf("\nCPF inválido! Informe novamente.\n");
			fgets(cadastro_alunos[quantidade_alunos].cpf, 12, stdin);
			
		} else {
		
			break;
			
		}
	}
}

void listarAlunos(int quantidade_alunos, Aluno estudante[]) {

	printf("************LISTA ALUNOS************\n");
	
	if(quantidade_alunos == 0) {
	
		printf("\nLista vazia\n");
		
	} else {
	
		for(int i = 0; i < quantidade_alunos; i++) {
		
			printf("\nAluno(a) %d\n", i+1);
			printf("Matrícula: %s", cadastro_alunos[i].matricula);
			printf("Nome: %s", cadastro_alunos[i].nome);
			printf("Sexo: %c", cadastro_alunos[i].sexo);
			printf("Nascimento: %d/%d/%d\n", cadastro_alunos[i].data_nascimento.dia, cadastro_alunos[i].data_nascimento.mes, cadastro_alunos[i].data_nascimento.ano);
			printf("CPF: %s", cadastro_alunos[i].cpf);
			
		}
	}
}

