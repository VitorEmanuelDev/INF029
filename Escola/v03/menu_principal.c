#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"

int menuPrincipal(int opcao){

	printf("________________________________________________________________\n");
	printf("|**************************************************************|\n");
	printf("|*********************** PROJETO ESCOLA ***********************|\n");
	printf("|**************************************************************|\n");
	printf("|_______________________________________ ______________________|\n");
	printf("|                 |                     |                      |\n");
	printf("|    * ALUNOS *   |    * PROFESSORES *  |    * DISCIPLINAS *   |\n");
	printf("|_________________|_____________________|______________________|\n");
	printf("|                 |                     |                      |\n");
	printf("|   1.Cadastrar   |    4.Cadastrar      |     7.Cadastrar      |\n");
	printf("|   2.Remover     |    5.Remover        |     8.Remover        |\n");
	printf("|   3.Atualizar   |    6.Atualizar      |     9.Atualizar      |\n");
	printf("|_________________|_____________________|______________________|\n");
	printf("|                                                              |\n");
	printf("|                     10.Relatórios                            |\n");
	printf("|______________________________________________________________|\n");
	printf("|                 |                                            |\n");
	printf("|   11.SAIR       |************ Digite a sua opcao ************|\n");
	printf("|_________________|____________________________________________|\n");

	scanf("%d",&opcao);
	setbuf(stdin, NULL);

	return opcao;

}

int main(){

	Individuo cadastro_alunos[TAM];
	Individuo cadastro_professores[TAM];
	Disciplina cadastro_disciplinas[TAM];

	int quantidade_alunos = 0;
	int quantidade_professores = 0;
	int quantidade_disciplinas = 0;

	int escolha = 0;
	int true = 1;

	while(true){

		escolha = menuPrincipal(escolha);

		switch(escolha){

			case 1:{

				if(quantidade_alunos < TAM){

					printf("\n*** Cadastre um perfil ***\n");
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

				if(quantidade_alunos > 0){

					printf("\n*** Remova um perfil ***\n");
					removerIndividuo(quantidade_alunos, cadastro_alunos);
					printf("Remoção realizada\n");
					break;

				}else{

					printf("Não foi possível remover o discente.");
					break;

				}

			}
			case 3:{

				if(quantidade_alunos > 0){

					printf("\n*** Atualize um perfil ***\n");
					alterarIndividuo(quantidade_alunos, cadastro_alunos);
					printf("Atualização realizada\n");
					break;

				}else{

					printf("Não foi possível atualizar o perfil.");
					break;

				}

			}
			case 4:{

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
			case 5:{

				if(quantidade_professores > 0){

					printf("\n*** Remova um perfil ***\n");
					removerIndividuo(quantidade_professores, cadastro_professores);
					printf("Remoção realizada\n");
					break;

				}else{

					printf("Não foi possível remover o docente.");
					break;

				}

			}
			case 6:{

				if(quantidade_professores > 0){

					printf("\n*** Atualize um perfil ***\n");
					alterarIndividuo(quantidade_professores, cadastro_professores);
					printf("Atualização realizada\n");
					break;

				}else{

					printf("Não foi possível atualizar o perfil.");
					break;

				}

			}
			case 7:{

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
			case 8:{

				if(quantidade_disciplinas > 0){

					printf("\n*** Remova uma disciplina ***\n");
					removerDisciplinas(quantidade_disciplinas, cadastro_disciplinas);
					printf("Remoção realizada\n");
					break;

				}else{

					printf("Não foi possível remover a disciplina.");
					break;

				}

			}
			case 9:{

				if(quantidade_disciplinas > 0){

					printf("\n*** Atualize uma disciplina ***\n");
					alterarDisciplinas(quantidade_disciplinas, cadastro_disciplinas);
					printf("Atualização realizada\n");
					break;

				}else{

					printf("Não foi possível atualizar o perfil.");
					break;

				}

			}
			case 10:{

				menuRelatorios(escolha);
				break;

			}
			case 11:{

				printf("Saindo...");
				true = 0;
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

