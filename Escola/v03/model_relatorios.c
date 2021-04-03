
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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

void listarProcuraNome(int quantidade_alunos, Individuo cadastro_alunos[], int quantidade_professores, Individuo cadastro_professores[]){

	char procura[TAM];

	fgets(procura, TAM, stdin);
	setbuf(stdin, NULL);

	if(quantidade_alunos <= 0){

		printf("\nCadastro de alunos(as) vazio.\n");

	}else{

		printf("Resultado alunos(as):\n\n");

		for(int i = 0; i < quantidade_alunos; i++){

			if(strstr(cadastro_alunos[i].nome, procura) != NULL){

				printf("Matricula: %s\n",cadastro_alunos[i].matricula);
				printf("Nome: %s\n",cadastro_alunos[i].nome);

			}

		}

	}

	if(quantidade_alunos <= 0){

		printf("\nCadastro de professores(as) vazio.\n");

	}else{

		printf("Resultado professores(as):\n\n");

		for(int i = 0; i < quantidade_professores; i++){

			if(strstr(cadastro_professores[i].nome, procura) != NULL){

				printf("Matricula: %s\n",cadastro_professores[i].matricula);
				printf("Nome: %s\n",cadastro_professores[i].nome);

			}

		}

	}

	printf("\n\n");

}

void listarIndividuosSortPorData(int quantidade, Individuo cadastro[], Individuo_temp cadastro_temp[]){

	for(int i = 0; i < quantidade; i++){

		strcpy(cadastro_temp[i].nome_temp, cadastro[i].nome);
		strcpy(cadastro_temp[i].matricula_temp, cadastro[i].matricula);
		cadastro_temp[i].sexo_temp = cadastro[i].sexo;
		strcpy(cadastro_temp[i].data_nascimento_temp, cadastro[i].data_nascimento);
		strcpy(cadastro_temp[i].cpf_temp, cadastro[i].cpf);

	}

	char temp_string[TAM];
	char temp_char;

	for(int i = 0; i < quantidade - 1; i++){

		int len_01 = strlen(cadastro_temp[i].data_nascimento_temp);
		char digitos_01[TAM];
		char caracteres_01[TAM];
		int len_digitos_01 = 0;

		strcpy(caracteres_01, cadastro_temp[i].data_nascimento_temp);

		for(int i = 0; i < len_01; i++){

			if(caracteres_01[i] >= 49 && caracteres_01[i] <= 57){
			//if(isdigit(caracteres[i])){
				digitos_01[len_digitos_01] = caracteres_01[i];
				len_digitos_01++;

			}

		}
		digitos_01[len_digitos_01] = '\0';

		int data_01 = atoi(digitos_01[i]);

		int dia_01 = data_01 / 1000000;
		int mes_01 = data_01 % 1000000 / 10000;
		int ano_01 = data_01 % 10000;

		for(int j = i + 1; j < quantidade; j++){

			int len_02 = strlen(cadastro_temp[j].data_nascimento_temp);
			char digitos_02[TAM];
			char caracteres_02[TAM];
			int len_digitos_02 = 0;

			strcpy(caracteres_02, cadastro_temp[j].data_nascimento_temp);

			for(int j = 0; j < len_02; j++){

				if(caracteres_02[j] >= 49 && caracteres_02[j] <= 57){
				//if(isdigit(caracteres[i])){
					digitos_02[len_digitos_02] = caracteres_02[j];
					len_digitos_02++;

				}

			}
			digitos_02[len_digitos_02] = '\0';

			int j = i + 1;
			int data_02 = atoi(digitos_02[j]);

			int dia_02 = data_02 / 1000000;
			int mes_02 = data_02 % 1000000 / 10000;
			int ano_02 = data_02 % 10000;

			if(ano_02 > ano_01){

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

			if(ano_02 == ano_01 && mes_02 > mes_01){

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

			if(ano_02 == ano_01 && mes_02 == mes_01 && dia_02 > dia_01){

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

void listarAniversariantes(int quantidade_alunos, Individuo cadastro_alunos[], int quantidade_professores, Individuo cadastro_professores[]){

	time_t momento;
	struct tm* tempo_atual;

	momento = time(NULL);

	tempo_atual = localtime(&momento);

	for(int i = 0; i < quantidade_alunos - 1; i++){

		int len = strlen(cadastro_alunos[i].data_nascimento);
		char digitos[TAM];
		char caracteres[TAM];
		int len_digitos = 0;

		strcpy(caracteres, cadastro_alunos[i].data_nascimento);

		for(int i = 0; i < len; i++){

			if(caracteres[i] >= 49 && caracteres[i] <= 57){
			//if(isdigit(caracteres[i])){
				digitos[len_digitos] = caracteres[i];
				len_digitos++;

			}

		}
		digitos[len_digitos] = '\0';

		int data = atoi(digitos);

		int mes = data % 1000000 / 10000;

		if(tempo_atual->tm_mon + 1 == mes){

			printf("Nome: %s\n",cadastro_alunos[i].nome);
			printf("Data de nascimento %s\n",cadastro_alunos[i].data_nascimento);

		}

	}

	for(int i = 0; i < quantidade_professores - 1; i++){

		int len = strlen(cadastro_professores[i].data_nascimento);
		char digitos[TAM];
		char caracteres[TAM];
		int len_digitos = 0;

		strcpy(caracteres, cadastro_professores[i].data_nascimento);

		for(int i = 0; i < len; i++){

			if(caracteres[i] >= 49 && caracteres[i] <= 57){
			//if(isdigit(caracteres[i])){
				digitos[len_digitos] = caracteres[i];
				len_digitos++;

			}

		}
		digitos[len_digitos] = '\0';

		int data = atoi(digitos);

		int mes = data % 1000000 / 10000;

		if(tempo_atual->tm_mon + 1 == mes){

			printf("Nome: %s\n",cadastro_alunos[i].nome);
			printf("Data de nascimento %s\n",cadastro_alunos[i].data_nascimento);

		}

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
			printf("Semestre: %d\n",cadastro[i].semestre);

		}

	}

	printf("\n\n");

}


void listarAlunoDisciplinas(int quantidade_disciplinas, Disciplina cadastro_disciplinas[], int quantidade_professores, Individuo cadastro_professores[]){

	int alunos_cadastrados;

	if(quantidade_disciplinas <= 0) {

		printf("\nNão há registros!\n\n");

	} else {

		for(int i = 0; i < quantidade_disciplinas; i++) {

			alunos_cadastrados = cadastro_disciplinas[i].quantidade_alunos_disciplina;

			printf("Numero: %d\n", i+1);
			printf("Código: %s\n",cadastro_disciplinas[i].codigo);
			printf("Nome da disciplina: %s\n",cadastro_disciplinas[i].nome);
			printf("Alunos matriculados na disciplina: %d\n", alunos_cadastrados);
			printf("\nID do docente: %d", cadastro_disciplinas[i].id_professor);
			printf("\nNome do docente: %s", cadastro_professores[cadastro_disciplinas[i].id_professor - 1].nome);

			printf("Semestre: %d\n",cadastro_disciplinas[i].semestre);

			for(int j = 0; j < alunos_cadastrados; j++) {

				printf("Discente %d: %s", j + 1, cadastro_disciplinas[i].aluno[j].nome);

			}

		}
	}
}

void listarAlunoDisciplinasMaisDe40Vagas(int quantidade_disciplinas, Disciplina cadastro_disciplinas[], int quantidade_professores, Individuo cadastro_professores[]){

	int alunos_cadastrados;

	if(quantidade_disciplinas <= 0) {

		printf("\nNão há registros!\n\n");

	} else {

		for(int i = 0; i < quantidade_disciplinas; i++) {

			alunos_cadastrados = cadastro_disciplinas[i].quantidade_alunos_disciplina;

			if (alunos_cadastrados < 5){

				printf("Numero: %d\n", i+1);
				printf("Código: %s\n",cadastro_disciplinas[i].codigo);
				printf("Nome da disciplina: %s\n",cadastro_disciplinas[i].nome);
				printf("Alunos matriculados na disciplina: %d\n", alunos_cadastrados);
				printf("\nID do docente: %d", cadastro_disciplinas[i].id_professor);
				printf("\nNome do docente: %s", cadastro_professores[cadastro_disciplinas[i].id_professor - 1].nome);
				printf("Semestre: %d\n",cadastro_disciplinas[i].semestre);

			}

		}
	}
}

void listarAlunoEmMaisDe3Disciplinas(int quantidade_disciplinas, Disciplina cadastro_disciplinas[], int quantidade_alunos, Individuo cadastro_alunos[]){



	if(quantidade_disciplinas <= 3) {

		printf("\nNão há registros suficientes!\n\n");

	} else {




		for(int i = 0; i < quantidade_alunos; i++){

			int disciplinas = 0;
			int posicao = 0;

			while(posicao <= quantidade_disciplinas){

				for(int j = posicao; j < quantidade_disciplinas; j++){


					if(strcmp(cadastro_disciplinas[posicao].aluno[j].nome, cadastro_alunos[i].nome) == 0){

						j++;
						posicao += j;
						disciplinas++;
						break;

					}

					break;

				}

			}

			if(disciplinas > 3){

				printf("Matricula: %s\n",cadastro_alunos[i].matricula);
				printf("Nome: %s\n",cadastro_alunos[i].nome);

			}


		}


	}


}

/*void recursivoAlunoEmMaisDe3Disciplinas(int quantidade_disciplinas, Disciplina cadastro_disciplinas[], Individuo cadastro_alunos[], int posicao, int disciplinas, int i){


	for(int j = posicao; j < quantidade_disciplinas; j++){


		if(strcmp(cadastro_disciplinas[posicao].aluno[j].nome, cadastro_alunos[i].nome) == 0){

			j++;
			posicao += j;
			disciplinas++;
			break;

		}

		break;

	}



}*/
