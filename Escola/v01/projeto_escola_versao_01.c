
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TURMA 5
#define TAM 30


typedef struct dados{

	char data_nascimento[TAM];
	char matricula[TAM];
	char nome[TAM];
	char cpf[TAM];
	char sexo;

}Aluno;


int paginaPrincipcal(int escolha);
void cadastrarAlunos(int quantidade, Aluno cadastro[]);
void listarAlunos(int quantidade, Aluno cadastro[]);
int validarMatricula(char matricula[]);
int validarCPF(char cpf[]);
int validarNome(char nome[]);
int validarData(char data_nascimento[]);
int validarSexo(char sexo);




int main(){

	Aluno cadastro_aluno[TURMA];
	int quantidade_alunos = 0;
	int escolha = 0;
	int flag = 1;


	while(flag == 1){

		escolha = paginaPrincipcal(escolha);

		switch(escolha){

			case 1:{

				if(quantidade_alunos < TURMA){

					cadastrarAlunos(quantidade_alunos, cadastro_aluno);
					printf("Cadastro Realizado\n");
					quantidade_alunos++;
					break;

				}else{

					printf("Turma cheia.\n");
					break;
				}

			}
			case 2:{

				printf("\n*** Alunos(as) cadastrados(as) ***\n\n");
				listarAlunos(quantidade_alunos, cadastro_aluno);
				break;

			}
			case 3:{

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
	printf("1 - Cadastrar Aluno(a)\n");
	printf("2 - Listar Aluno(a)\n");
	printf("3 - Sair\n");


	printf("Digite a sua opcao:\n");
	scanf("%d",&opcao);
	setbuf(stdin, NULL);

	return opcao;
}

void cadastrarAlunos(int quantidade, Aluno cadastro[]){

	int true = 1;

	int validaNome;
	int validaData;
	int validaCPF;
	int validaSexo;
	int validaMatricula;

	printf("Informe a matricula:\n");
	fgets(cadastro[quantidade].matricula, TAM, stdin);
	setbuf(stdin, NULL);

	while(true) {

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

	while(true) {

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

	while(true) {

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
	getchar();

	while(true) {

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

    while(true) {

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


void listarAlunos(int quantidade, Aluno cadastro[]){

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

    int result1, result2, digito1, digito2, valor;

    int somador = 0;

    for(int i = 0; i < 11; i++)
    	icpf[i] = cpf[i] - 48;
        //icpf[i] = atoi(cpf[i]);




     //encontrar o primeiro digito verificador
    for(int i = 0; i < 9; i++)
        somador += icpf[i] * (10 - i);

    result1 = somador % 11;

    if( result1 == 0 || result1 == 1 ){

        digito1 = 0;

    }else{

        digito1 = 11 - result1;

    }

    //encontrar o segundo digito verificador

    somador = 0;

    for(int i = 0; i < 10; i++)  {

        somador += icpf[i] * (11 - i);

    }

    valor = (somador / 11) * 11;

    result2 = somador - valor;

    if(result2 == 0 || result2 == 1){

        digito2 = 0;

    }else{

        digito2 = 11 - result2;

    }


    if(strlen(cpf) != 11 && ((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
      (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
      (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||(strcmp(cpf,"99999999999") == 0))){

    	return -1;

    }else if(digito1 == icpf[9] && digito2 == icpf[10]){

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
	int j = 0;

	strcpy(caracteres, data_nascimento);

	for(int i = 0; i < len; i++){

		if(caracteres[i] >= 49 && caracteres[i] <= 57){
		//if(isdigit(caracteres[i])){
			digitos[j] = caracteres[i];
			j++;

		}

	}
	digitos[j] = '\0';

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

	if(len - 1 <= 30 && len - 1 > 3) {

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


