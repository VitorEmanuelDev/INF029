#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"


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


