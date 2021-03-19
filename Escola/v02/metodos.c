
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"

int paginaPrincipcal(int opcao){

	printf("\n*** Menu Projeto Escola ***\n\n");
	printf("1 - Cadastrar Alunos(a)\n");
	printf("2 - Listar Alunos(as)\n");
	printf("3 - Cadastrar Professores(as)\n");
	printf("4 - Listar Professores(as)\n");
	printf("5 - Cadastrar Disciplinas(a)\n");
	printf("6 - Listar Disciplinas(a)\n");
	printf("7 - Sair\n");


	printf("Digite a sua opcao:\n");
	scanf("%d",&opcao);
	setbuf(stdin, NULL);

	return opcao;
}

void cadastrarIndividuo(int quantidade, Individuo cadastro[]){

	int errado = 1;

	int validaNome;
	int validaData;
	int validaCPF;
	int validaSexo;
	int validaMatricula;

	printf("Informe a matricula:\n");
	fgets(cadastro[quantidade].matricula, TAM, stdin);
	setbuf(stdin, NULL);

	while(errado) {

		validaMatricula = validarMatricula(cadastro[quantidade].matricula);

		if(validaMatricula != 1) {

			printf("\nMatricula inválida. Informe novamente:\n");
			fgets(cadastro[quantidade].matricula, TAM, stdin);
			setbuf(stdin, NULL);

		}else {

			break;

		}
	}

	printf("Informe o nome:\n");
	fgets(cadastro[quantidade].nome, TAM, stdin);
	setbuf(stdin, NULL);

	while(errado) {

		validaNome = validarNome(cadastro[quantidade].nome);

		if(validaNome != 1) {

			printf("\nNome inválido. Informe novamente:\n");
			fgets(cadastro[quantidade].nome, TAM, stdin);
			setbuf(stdin, NULL);

		}else {

			break;

		}
	}

	printf("Informe o Sexo:\n");
	scanf("%c",&cadastro[quantidade].sexo);
	getchar();

	while(errado) {

		validaSexo = validarSexo(cadastro[quantidade].sexo);

		if(validaSexo != 1) {

			printf("\nSexo inválido. Informe novamente:\n");
			scanf("%c",&cadastro[quantidade].sexo);
			getchar();
		} else {

			break;

		}
	}


	printf("Informe a data de nascimento, formato: dd/mm/aaaa.\n");
	fgets(cadastro[quantidade].data_nascimento, TAM, stdin);
	setbuf(stdin, NULL);
	//getchar();

	while(errado) {

		validaData = validarData(cadastro[quantidade].data_nascimento);

		if(validaData != 1) {

			printf("\nData inválida. Informe novamente:\n");
			fgets(cadastro[quantidade].data_nascimento, TAM, stdin);
			setbuf(stdin, NULL);

		} else {

			break;

		}
	}

	printf("Informe o CPF\n");
	fgets(cadastro[quantidade].cpf, TAM, stdin);
    setbuf(stdin, NULL);

    while(errado) {

    	validaCPF = validarCPF(cadastro[quantidade].cpf);

		if(validaCPF!= 1) {

			printf("\nCPF inválido. Informe novamente\n");
			fgets(cadastro[quantidade].cpf, TAM, stdin);
			setbuf(stdin, NULL);

		} else {

			break;

		}
	}

    printf("\n\n");

}


void listarIndividuo(int quantidade, Individuo cadastro[]){

	if(quantidade <= 0){

		printf("Cadastro vazio.\n");

	}else{

		for(int i = 0; i < quantidade; i++){

			printf("Matricula: %s\n",cadastro[i].matricula);
			printf("Nome: %s\n",cadastro[i].nome);
			printf("Sexo: %c\n",cadastro[i].sexo);
			printf("Data de nascimento %s\n",cadastro[i].data_nascimento);
			printf("CPF: %s\n",cadastro[i].cpf);

		}

	}

	printf("\n\n");
}

void cadastrarDisciplinas(int quantidade_professores, int quantidade_disciplinas, Disciplina cadastro_disciplinas[], Individuo cadastro_professores[]){

	int errado = 1;

	int validaNome;
	int validaCodigo;
	int validaProfessor;
	int validaSemestre;

	printf("Informe o código:\n");
	fgets(cadastro_disciplinas[quantidade_disciplinas].codigo, TAM, stdin);
	setbuf(stdin, NULL);

	while(errado) {

		validaCodigo = validarCodigo(cadastro_disciplinas[quantidade_disciplinas].codigo);

		if(validaCodigo != 1) {

			printf("\nCódigo inválido. Informe novamente:\n");
			fgets(cadastro_disciplinas[quantidade_disciplinas].codigo, TAM, stdin);
			setbuf(stdin, NULL);

		}else {

			break;

		}
	}

	printf("Informe o nome:\n");
	fgets(cadastro_disciplinas[quantidade_disciplinas].nome, TAM, stdin);
	setbuf(stdin, NULL);

	while(errado) {

		validaNome = validarNome(cadastro_disciplinas[quantidade_disciplinas].nome);

		if(validaNome != 1) {

			printf("\nNome inválido. Informe novamente:\n");
			fgets(cadastro_disciplinas[quantidade_disciplinas].nome, TAM, stdin);
			setbuf(stdin, NULL);

		}else {

			break;

		}
	}


	printf("Informe o Professor\n");
	fgets(cadastro_disciplinas[quantidade_disciplinas].professor, TAM, stdin);
    setbuf(stdin, NULL);

    while(errado) {

    	validaProfessor = validarProfessor(quantidade_professores,quantidade_disciplinas, cadastro_disciplinas[quantidade_disciplinas].professor, cadastro_professores[quantidade_professores].nome);

		if(validaProfessor!= 1) {

			printf("\nProfessor não corresponde a nenhum registrado. Informe novamente\n");
			fgets(cadastro_disciplinas[quantidade_disciplinas].professor, TAM, stdin);
			setbuf(stdin, NULL);

		} else {

			break;

		}
	}

    printf("Informe o semestre (1 ou 2)\n");
    scanf("%c", &cadastro_disciplinas[quantidade_disciplinas].semestre);
	setbuf(stdin, NULL);

	while(errado) {

		validaSemestre = validarSemestre(cadastro_disciplinas[quantidade_disciplinas].semestre);

		if(validaSemestre != 1) {

			printf("\nSemestre inválido\n");
			scanf("%c", &cadastro_disciplinas[quantidade_disciplinas].semestre);
			setbuf(stdin, NULL);

		} else {

			break;

		}
	}

    printf("\n\n");

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

