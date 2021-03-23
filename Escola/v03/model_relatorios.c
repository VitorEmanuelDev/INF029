
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"

void listarIndividuo(int quantidade, Individuo cadastro[]){

	if(quantidade <= 0){

		printf("Cadastro vazio.\n");

	}else{

		for(int i = 0; i < quantidade; i++){

			printf("Numero: %d\n", i+1);
			printf("Matricula: %s\n",cadastro[i].matricula);
			printf("Nome: %s\n",cadastro[i].nome);
			printf("Sexo: %c\n",cadastro[i].sexo);
			printf("Data de nascimento %s\n",cadastro[i].data_nascimento);
			printf("CPF: %s\n",cadastro[i].cpf);

		}

	}

	printf("\n\n");

}

void listarIndividuoSexo(int quantidade, Individuo cadastro[]){

	if(quantidade <= 0){

		printf("Cadastro vazio.\n");

	}else{

		printf("Lista de alunos");
		for(int i = 0; i < quantidade; i++){

			if(cadastro[i].sexo == 'm' || cadastro[i].sexo == 'M'){

				printf("Numero: %d\n", i+1);
				printf("Matricula: %s\n",cadastro[i].matricula);
				printf("Nome: %s\n",cadastro[i].nome);
				printf("Sexo: %c\n",cadastro[i].sexo);
				printf("Data de nascimento %s\n",cadastro[i].data_nascimento);
				printf("CPF: %s\n",cadastro[i].cpf);

			}
		}

		printf("\n\n");

		printf("Lista de alunas");
		for(int i = 0; i < quantidade; i++){

			if(cadastro[i].sexo == 'f' || cadastro[i].sexo == 'F'){

				printf("Numero: %d\n", i+1);
				printf("Matricula: %s\n",cadastro[i].matricula);
				printf("Nome: %s\n",cadastro[i].nome);
				printf("Sexo: %c\n",cadastro[i].sexo);
				printf("Data de nascimento %s\n",cadastro[i].data_nascimento);
				printf("CPF: %s\n",cadastro[i].cpf);

			}
		}

		printf("Lista de alunes");
		for(int i = 0; i < quantidade; i++){

			if(cadastro[i].sexo == 'o' || cadastro[i].sexo == 'O'){

				printf("Numero: %d\n", i+1);
				printf("Matricula: %s\n",cadastro[i].matricula);
				printf("Nome: %s\n",cadastro[i].nome);
				printf("Sexo: %c\n",cadastro[i].sexo);
				printf("Data de nascimento %s\n",cadastro[i].data_nascimento);
				printf("CPF: %s\n",cadastro[i].cpf);

			}
		}


	}

}

void listarIndividuoSortPorNome(int quantidade, Individuo cadastro[], Individuo_temp cadastro_temp[]){

	for(int i = 0; i < quantidade; i++){

		strcpy(cadastro_temp[i].nome_temp, cadastro[i].nome);
		strcpy(cadastro_temp[i].matricula_temp, cadastro[i].matricula);
		cadastro_temp[i].sexo_temp = cadastro[i].sexo;
		strcpy(cadastro_temp[i].data_nascimento_temp, cadastro[i].data_nascimento);
		strcpy(cadastro_temp[i].cpf_temp, cadastro[i].cpf);

	}

	if(quantidade <= 0){

		printf("Cadastro vazio.\n");

	}else{

		char temp_string[TAM];
		char temp_char;

		for(int i = 0; i <= quantidade; i++){

		    for(int j = i + 1; j <= quantidade; j++){

		      if(strcmp(cadastro_temp[i].nome_temp, cadastro_temp[j].nome_temp) > 0){

		        strcpy(temp_string, cadastro_temp[i].nome_temp);
		        strcpy(cadastro_temp[i].nome_temp, cadastro_temp[j].nome_temp);
		        strcpy(cadastro_temp[j].nome_temp, temp_string);

		        strcpy(temp_string, cadastro_temp[i].matricula_temp);
				strcpy(cadastro_temp[i].matricula_temp, cadastro_temp[j].matricula_temp);
				strcpy(cadastro_temp[j].matricula_temp, temp_string);

				temp_char = cadastro_temp[i].sexo_temp;
				cadastro_temp[i].sexo_temp = cadastro_temp[j].sexo_temp;
				cadastro_temp[j].sexo_temp = temp_char;

				strcpy(temp_string, cadastro_temp[i].data_nascimento_temp);
				strcpy(cadastro_temp[i].data_nascimento_temp, cadastro_temp[j].data_nascimento_temp);
				strcpy(cadastro_temp[j].data_nascimento_temp, temp_string);

				strcpy(temp_string, cadastro_temp[i].cpf_temp);
				strcpy(cadastro_temp[i].cpf_temp, cadastro_temp[j].cpf_temp);
				strcpy(cadastro_temp[j].cpf_temp, temp_string);

		      }

		    }

		}

		printf("Lista de alunos - Ordem alfabética");
		for(int i = 0; i < quantidade; i++){

			printf("Numero: %d\n", i+1);
			printf("Matricula: %s\n",cadastro_temp[i].matricula_temp);
			printf("Nome: %s\n",cadastro_temp[i].nome_temp);
			printf("Sexo: %c\n",cadastro_temp[i].sexo_temp);
			printf("Data de nascimento %s\n",cadastro_temp[i].data_nascimento_temp);
			printf("CPF: %s\n",cadastro_temp[i].cpf_temp);

		}

		printf("\n\n");

	}

}



void listarDisciplinas(int quantidade, Disciplina cadastro[]){

	if(quantidade <= 0){

		printf("Cadastro vazio.\n");

	}else{

		for(int i = 0; i < quantidade; i++){

			printf("Código: %s\n",cadastro[i].codigo);
			printf("Nome: %s\n",cadastro[i].nome);
			printf("Professor: %s\n",cadastro[i].professor);
			printf("Semestre: %c\n",cadastro[i].semestre);

		}

	}

	printf("\n\n");

}
