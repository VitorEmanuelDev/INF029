#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 30

typedef struct dados_01{

	char data_nascimento[TAM];
	char matricula[TAM];
	char nome[TAM];
	char cpf[TAM];
	char sexo;

}Individuo;

typedef struct dados_02{

	char nome[TAM];
	char professor[TAM];
	char semestre;
	char codigo[TAM];

}Disciplina;


int paginaPrincipcal(int escolha);

void cadastrarIndividuo(int quantidade, Individuo cadastro[]);
void listarIndividuo(int quantidade, Individuo cadastro[]);

void cadastrarDisciplinas(int quantidade_professores, int quantidade_disciplinas, Disciplina cadastro_disciplinas[], Individuo cadastro_individuos[]);
void listarDisciplinas(int quantidade, Disciplina cadastro[]);


int validarMatricula(char matricula[]);
int validarCPF(char cpf[]);
int validarNome(char nome[]);
int validarData(char data_nascimento[]);
int validarSexo(char sexo);
int validarCodigo(char codigo[]);
int validarProfessor(int quantidade_professores, int quantidade_disciplinas, Disciplina cadastro_disciplinas[], Individuo cadastro_professores[]);
int validarSemestre(char semestre);


int main(){

	Individuo cadastro_alunos[TAM];
	Individuo cadastro_professores[TAM];
	Disciplina cadastro_disciplinas[TAM];

	int quantidade_alunos = 0;
	int quantidade_professores = 0;
	int quantidade_disciplinas = 0;

	int escolha = 0;
	int flag = 1;

	while(flag == 1){

		escolha = paginaPrincipcal(escolha);

		switch(escolha){

			case 1:{

				if(quantidade_alunos < TAM){

					cadastrarIndividuo(quantidade_alunos, cadastro_alunos);
					printf("Cadastro realizado\n");
					quantidade_alunos++;
					break;

				}else{

					printf("Turma cheia.\n");
					break;
				}

			}
			case 2:{

				printf("\n*** Alunos(as) cadastrados(as) ***\n\n");
				listarIndividuo(quantidade_alunos, cadastro_alunos);
				break;

			}
			case 3:{

				if(quantidade_professores < TAM){

					cadastrarIndividuo(quantidade_professores, cadastro_professores);
					printf("Cadastro realizado\n");
					quantidade_professores++;
					break;

				}else{

					printf("Vagas insuficientes.\n");
					break;

				}

			}
			case 4:{

			printf("\n*** Professores(as) cadastrados(as) ***\n\n");
			listarIndividuo(quantidade_professores, cadastro_professores);
			break;

			}
			case 5:{

				if(quantidade_disciplinas < TAM){

					cadastrarDisciplinas(quantidade_professores, quantidade_disciplinas, cadastro_disciplinas, cadastro_professores);
					printf("Cadastro realizado\n");
					quantidade_disciplinas++;
					break;

				}else{

					printf("Quantidade máxima atingida.\n");
					break;
				}

			}
			case 6:{

				printf("\n*** Disciplinas cadastradas ***\n\n");
				listarDisciplinas(quantidade_disciplinas, cadastro_disciplinas);
				break;

			}
			case 7:{

				printf("Saindo...");
				flag = 0;
				break;

			}
			default:{
				printf("\nOpção inválida\n");
				break;
			}
		}
	}

	return 0;
}


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



int validarSexo(char sexo){

	if(sexo == 'M' || sexo == 'F' || sexo == 'O' ||
	   sexo == 'm' || sexo == 'f' || sexo == 'o') {

	    return 1;

	} else {

	    return -1;

	}

}

int validarCPF(char cpf[]) {

    int icpf[TAM];

    int resultado_01, resultado_02, digito_01, digito_02, valor;

    int soma = 0;

    for(int i = 0; i < 11; i++)
    	icpf[i] = cpf[i] - 48;
        //icpf[i] = atoi(cpf[i]);

     //encontrar o primeiro digito verificador
    for(int i = 0; i < 9; i++)
        soma += icpf[i] * (10 - i);

    resultado_01 = soma % 11;

    if(resultado_01 == 0 || resultado_01 == 1 ){

        digito_01 = 0;

    }else{

        digito_01 = 11 - resultado_01;

    }

    //encontrar o segundo digito verificador

    soma = 0;

    for(int i = 0; i < 10; i++)  {

        soma += icpf[i] * (11 - i);

    }

    valor = (soma / 11) * 11;

    resultado_02 = soma - valor;

    if(resultado_02 == 0 || resultado_02 == 1){

        digito_02 = 0;

    }else{

        digito_02 = 11 - resultado_02;

    }


    if(strlen(cpf) - 1 != 11 && ((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
      (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
      (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||(strcmp(cpf,"99999999999") == 0))){

    	return -1;

    }else if(digito_01 == icpf[9] && digito_02 == icpf[10]){

        return 1;

    }else{

    	return -1;

    }



}






int validarMatricula(char matricula[]) {

	char caracteres[TAM];
	int len = strlen(matricula);
	int flag = 1;

	strcpy(caracteres, matricula);

	if(len - 1 == 11){

		for(int i = 0; i < len; i++){

			if(caracteres[i] < 49 && caracteres[i] > 57){
			//if(isdigit(caracteres[i])){
				flag = 0;
				break;

			}

		}

		if((flag == 0) || ((strcmp(matricula,"00000000000") == 0) || (strcmp(matricula,"11111111111") == 0) || (strcmp(matricula,"22222222222") == 0) ||
		(strcmp(matricula,"33333333333") == 0) || (strcmp(matricula,"44444444444") == 0) || (strcmp(matricula,"55555555555") == 0) ||
		(strcmp(matricula,"66666666666") == 0) || (strcmp(matricula,"77777777777") == 0) || (strcmp(matricula,"88888888888") == 0) ||(strcmp(matricula,"99999999999") == 0))){

			return -1;

		}else {

			return 1;

		}

	}else{

		return -1;

	}

}

int validarData(char data_nascimento[]) {

	int len = strlen(data_nascimento);
	char digitos[TAM];
	char caracteres[TAM];
	int len_digitos = 0;

	strcpy(caracteres, data_nascimento);

	for(int i = 0; i < len; i++){

		if(caracteres[i] >= 49 && caracteres[i] <= 57){
		//if(isdigit(caracteres[i])){
			digitos[len_digitos] = caracteres[i];
			len_digitos++;

		}

	}
	digitos[len_digitos] = '\0';

	int data = atoi(digitos);

	int dia = data / 1000000;
	int mes = data % 1000000 / 10000;
	int ano = data % 10000;

	if(ano >= 1900 && ano <= 2100){

	        if (mes >= 1 && mes <= 12){

	            if ((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
	                return 1;

	            else if ((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
	            	 return 1;

	            else if ((dia >= 1 && dia <= 28) && (mes == 2))
	            	 return 1;

	            else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)))
	            	 return 1;

	            else
	            	 return -1;
	        }else{

	        	return -1;
	        }

	    }else{

	    	return -1;

	    }

}

int validarNome(char nome[]){

	char caracteres[TAM];
	int len = strlen(nome);
	int flag = 1;

	strcpy(caracteres, nome);

	if(len - 1 <= 30 && len - 1 > 5) {

		for(int i = 0; i < len; i++){

			//if(isalpha(caracteres[i])){
			if((caracteres[i] < 65 && caracteres[i] > 90) && (caracteres[i] < 97 && caracteres[i] > 122)){

				flag = 0;
				break;

			}

		}

		if (flag == 0){

			return -1;

		}else{

			return 1;

		}

	}else{

		return -1;

    }

}

int validarCodigo(char codigo[]){

	char caracteres[TAM];
	int len = strlen(codigo);
	int flag = 1;

	strcpy(caracteres, codigo);

	if(len - 1 == 6) {

		for(int i = 0; i < 3; i++){

			//if(isalpha(caracteres[i])){
			if((caracteres[i] < 65 && caracteres[i] > 90) && (caracteres[i] < 97 && caracteres[i] > 122)){

				flag = 0;
				break;

			}

		}

		for(int i = 3; i < 6; i++){

			if(caracteres[i] < 49 && caracteres[i] > 57){
			//if(isdigit(caracteres[i])){
				flag = 0;
				break;

			}

		}

		if (flag == 0){

			return -1;

		}else{

			return 1;

		}

	}else{

		return -1;

    }


}

int validarProfessor(int quantidade_professores, int quantidade_disciplinas, Disciplina cadastro_disciplinas[], Individuo cadastro_professores[]){

	size_t tam_disciplina = sizeof(cadastro_disciplinas) / sizeof(cadastro_disciplinas[0]);
	size_t tam_individuo = sizeof(cadastro_professores) / sizeof(cadastro_professores[0]);

	int flag = 0;

	if(quantidade_professores > 0 && quantidade_disciplinas > 0){

			for(int i = 0; i < tam_disciplina; i++){

				if(flag == 0){

					for(int j = 0; j < tam_individuo; j++){

						if(strcmp(cadastro_disciplinas[i].professor, cadastro_professores[j].nome) == 0){

							flag = 1;
							break;

						}
					}
				}

				if(flag == 1){

					return 1;
					break;

				}
			}

	}else
		return -1;

}

int validarSemestre(char semestre){

	if(semestre == '1' || semestre == '2'){

		return 1;

	}else{

		return -1;

	}

}

