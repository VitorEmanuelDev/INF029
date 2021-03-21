
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"

int paginaPrincipcal(int opcao){

	printf("______________________________________________________________\n");
	printf("|************************************************************|\n");
	printf("|********************* PROJETO ESCOLA ***********************|\n");
	printf("|************************************************************|\n");
	printf("|____________________________________________________________|\n");
	printf("|                |                     |                     |\n");
	printf("|    * ALUNOS *  |    * PROFESSORES *  |    * DISCIPLINAS *  |\n");
	printf("|________________|_____________________|_____________________|\n");
	printf("|                |                     |                     |\n");
	printf("|   1.Cadastrar  |    5.Cadastrar      |     9.Cadastrar     |\n");
	printf("|   2.Listar     |    6.Listar         |     10.Listar       |\n");
	printf("|   3.Remover    |    7.Remover        |     11.Remover      |\n");
	printf("|   4.Atualizar  |    8.Atualizar      |     12.Atualizar    |\n");
	printf("|________________|_____________________|_____________________|\n");
	printf("|                |                                           |\n");
	printf("|   13.SAIR      |*******************************************|\n");
	printf("|________________|___________________________________________|\n");


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

void alterarIndividuo(int quantidade, Individuo cadastro[]){

	int numero;
	char sexo_novo;
	char matricula_nova[TAM];
	char nome_novo[TAM];
	char data_nova[TAM];
	char cpf_novo[TAM];

	listarIndividuo(quantidade, cadastro);

	printf("\nInforme o número de um perfil que deseja alterar: ");
	scanf("%d", &numero);
	setbuf(stdin, NULL);

	int true = 1;

	while(true) {

		if(numero <= 0 || numero > quantidade) {

			printf("\nRegistro inexistente. Informe novamente.\n");
			scanf("%d", &numero);
			setbuf(stdin, NULL);

		} else {

			break;

		}

	}

	int opcao;

	printf("Qual dado deseja alterar?\n");
	scanf("%d", &opcao);

	printf("_____________________\n");
	printf("|                   |\n");
	printf("|*******************|\n");
	printf("|*    1.Matricula  *|\n");
	printf("|*    2.Nome       *|\n");
	printf("|*    3.Sexo       *|\n");
	printf("|*    4.Nascimento *|\n");
	printf("|*    5.CPF        *|\n");
	printf("|*******************|\n");
	printf("|___________________|\n");

	switch(opcao) {

		case 1: {

			printf("\nInforme o novo número de matrícula:\n");
			fgets(matricula_nova, TAM, stdin);
			setbuf(stdin, NULL);



			while(true) {

				if(validarMatricula(cadastro[numero - 1].matricula) != 1) {

					printf("\nMatrícula inválida. Informe novamente\n");
					fgets(matricula_nova, TAM, stdin);
					setbuf(stdin, NULL);

				} else {

					strcpy(cadastro[numero - 1].matricula, matricula_nova);
					break;

				}

			}

			break;

		}

		case 2: {
			printf("\nInforme o novo nome:\n");
			fgets(nome_novo, TAM, stdin);
			setbuf(stdin, NULL);

			while(true) {

				if(validarNome(cadastro[numero - 1].nome) != 1) {

					printf("\nNome inválido. Informe novamente.\n");
					fgets(nome_novo, TAM, stdin);
					setbuf(stdin, NULL);

				} else {

					strcpy(cadastro[numero - 1].nome, nome_novo);
					break;

				}

			}

			break;

		}

		case 3: {

			printf("\nInforme o novo sexo:\n");
			scanf("%c", &sexo_novo);
			setbuf(stdin, NULL);

			while(true) {

				if(validarSexo(cadastro[numero - 1].sexo) != 1) {

					printf("\nSexo inválido. Informe novamente.\n");
					scanf("%c", &sexo_novo);
					setbuf(stdin, NULL);

				} else {

					cadastro[numero - 1].sexo = sexo_novo;
					break;

				}

			}

			break;

		}

		case 4: {

			printf("\nInforme a nova data de nascimento:\n");
			fgets(data_nova, TAM, stdin);
			setbuf(stdin, NULL);

			while(true) {

				if(validarData(cadastro[numero - 1].data_nascimento) != 1) {

					printf("\nData inválida. Informe novamente.\n");
					fgets(data_nova, TAM, stdin);
					setbuf(stdin, NULL);

				} else {

					strcpy(cadastro[numero - 1].data_nascimento, data_nova);
					break;

				}

			}

			break;

		}

		case 5: {

			printf("\nInforme o novo CPF:\n");
			fgets(cpf_novo, TAM, stdin);
			setbuf(stdin, NULL);

			while(true) {

				if(validarCPF(cadastro[numero - 1].cpf) != 1) {

					printf("\nCPFa inválido. Informe novamente.\n");
					fgets(cpf_novo, TAM, stdin);
					setbuf(stdin, NULL);

				} else {

					strcpy(cadastro[numero - 1].cpf, cpf_novo);
					break;

				}

			}

			break;

		}

		default: {

			printf("\nOpção inválida.\n");
			break;

		}

	}

}

int removerIndividuo(int quantidade, Individuo cadastro[]) {

	int posicao;

	listarIndividuo(quantidade, cadastro);

	printf("\nInforme qual perfil deseja deletar: ");
	scanf("%d", &posicao);
	setbuf(stdin, NULL);
	posicao--;

	for(int i = posicao; i < quantidade; i++) {

		strcpy(cadastro[i].matricula, cadastro[i+1].matricula);
		strcpy(cadastro[i].nome, cadastro[i+1].nome);
		cadastro[i].sexo = cadastro[i+1].sexo;
		strcpy(cadastro[i].data_nascimento, cadastro[i+1].data_nascimento);
		strcpy(cadastro[i].cpf, cadastro[i+1].cpf);

	}

	quantidade--;

	listarIndividuo(quantidade, cadastro);

	return posicao;

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

