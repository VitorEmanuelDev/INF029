
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"

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


void alterarIndividuo(int quantidade, Individuo cadastro[]){

	int numero;
	char sexo_novo;
	char matricula_nova[TAM];
	char nome_novo[TAM];
	char data_nova[TAM];
	char cpf_novo[TAM];

	listarIndividuo(quantidade, cadastro);

	printf("\nInforme o número de um perfil que deseja alterar:\n");
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

				if(validarMatricula(matricula_nova) != 1) {

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

				if(validarNome(nome_novo) != 1) {

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

				if(validarSexo(sexo_novo) != 1) {

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

				if(validarData(data_nova) != 1) {

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

				if(validarCPF(cpf_novo) != 1) {

					printf("\nCPF inválido. Informe novamente.\n");
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

void removerIndividuo(int quantidade, Individuo cadastro[]) {

	int posicao;

	listarIndividuo(quantidade, cadastro);

	printf("\nInforme qual perfil deseja deletar: ");
	scanf("%d", &posicao);
	setbuf(stdin, NULL);
	posicao--;

	int i;

	for(i = posicao; i < quantidade; i++) {

		strcpy(cadastro[i].matricula, cadastro[i+1].matricula);
		strcpy(cadastro[i].nome, cadastro[i+1].nome);
		cadastro[i].sexo = cadastro[i+1].sexo;
		strcpy(cadastro[i].data_nascimento, cadastro[i+1].data_nascimento);
		strcpy(cadastro[i].cpf, cadastro[i+1].cpf);

	}

	quantidade--;

	listarIndividuo(quantidade, cadastro);



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

void alterarDisciplinas(int quantidade, Disciplina cadastro[]){

	int numero;
	char nome_novo[TAM];
	char professor_novo[TAM];
	char codigo_novo[TAM];
	char semestre_novo = '\0';

	listarDisciplinas(quantidade, cadastro);

	printf("\nInforme o número de uma disciplina que deseja alterar:\n");
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
	printf("|*    1.Nome       *|\n");
	printf("|*    2.Professor  *|\n");
	printf("|*    3.Código     *|\n");
	printf("|*    4.Semestre   *|\n");
	printf("|*******************|\n");
	printf("|___________________|\n");

	switch(opcao) {

		case 1: {

			printf("\nInforme o novo nome da disciplina:\n");
			fgets(nome_novo, TAM, stdin);
			setbuf(stdin, NULL);

			while(true) {

				if(validarNome(nome_novo) != 1) {

					printf("\nNome inválido. Informe novamente\n");
					fgets(nome_novo, TAM, stdin);
					setbuf(stdin, NULL);

				} else {

					strcpy(cadastro[numero - 1].nome, nome_novo);
					break;

				}

			}

			break;

		}

		case 2: {
			printf("\nInforme o nome do/da docente:\n");
			fgets(professor_novo, TAM, stdin);
			setbuf(stdin, NULL);

			while(true) {

				if(validarNome(professor_novo) != 1) {

					printf("\nNome inválido. Informe novamente.\n");
					fgets(professor_novo, TAM, stdin);
					setbuf(stdin, NULL);

				} else {

					strcpy(cadastro[numero - 1].professor, professor_novo);
					break;

				}

			}

			break;

		}

		case 3: {

			printf("\nInforme o novo código:\n");
			fgets(codigo_novo, TAM, stdin);
			setbuf(stdin, NULL);

			while(true) {

				if(validarCodigo(codigo_novo) != 1) {

					printf("\nCódigo inválido. Informe novamente.\n");
					fgets(codigo_novo, TAM, stdin);
					setbuf(stdin, NULL);

				} else {

					strcpy(cadastro[numero - 1].codigo, codigo_novo);
					break;

				}

			}

			break;

		}

		case 4: {

			printf("\nInforme o novo semestre:\n");
			scanf("%c", &semestre_novo);
			setbuf(stdin, NULL);

			while(true) {

				if(validarSemestre(semestre_novo) != 1) {

					printf("\nData inválida. Informe novamente.\n");
					scanf("%c", &semestre_novo);
					setbuf(stdin, NULL);

				} else {

					cadastro[numero - 1].semestre = semestre_novo;
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

void removerDisciplinas(int quantidade, Disciplina cadastro[]){

	int posicao;

	listarDisciplinas(quantidade, cadastro);

	printf("\nInforme qual disciplina deseja deletar:\n");
	scanf("%d", &posicao);
	setbuf(stdin, NULL);
	posicao--;

	int i;

	for(i = posicao; i < quantidade; i++) {

		strcpy(cadastro[i].codigo, cadastro[i+1].codigo);
		strcpy(cadastro[i].professor, cadastro[i+1].professor);
		strcpy(cadastro[i].nome, cadastro[i+1].nome);
		cadastro[i].semestre = cadastro[i+1].semestre;

	}

	quantidade--;

	listarDisciplinas(quantidade, cadastro);

}
