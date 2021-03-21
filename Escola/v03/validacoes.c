#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"


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

