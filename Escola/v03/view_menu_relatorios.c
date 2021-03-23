#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes.h"

int menuRelatorios(int escolha){

		printf("__________________________________________________________\n");
		printf("|*                                                      *|\n");
		printf("|********************************************************|\n");
		printf("|********************** RELATÓRIOS **********************|\n");
		printf("|********************************************************|\n");
		printf("|*                                                      *|\n");
		printf("|*    1.Listar Alunos(as)                               *|\n");
		printf("|*    2.Listar Alunos(as) por sexo                      *|\n");
		printf("|*    3.Listar Alunos(as) por ordem alfabética          *|\n");
		printf("|*    4.Listar Alunos(as) por nascimento                *|\n");
		printf("|*    5.Lista de alunos em menos de 3 disciplinas       *|\n");
		printf("|*                                                      *|\n");
		printf("|********************************************************|\n");
		printf("|*                                                      *|\n");
		printf("|*    6.Listar Professores                              *|\n");
		printf("|*    7.Listar Professores(as) por sexo                 *|\n");
		printf("|*    8.Listar Professores(as) por ordem alfabética     *|\n");
		printf("|*    9.Listar Professores(as) por data de nascimento   *|\n");
		printf("|*                                                      *|\n");
		printf("|********************************************************|\n");
		printf("|*                                                      *|\n");
		printf("|*   10.Aniversariantes do mês                          *|\n");
		printf("|*   11.Procurar alunos ou professores no sistema       *|\n");
		printf("|*                                                      *|\n");
		printf("|********************************************************|\n");
		printf("|*                                                      *|\n");
		printf("|*   12.Listar Disciplinas                              *|\n");
		printf("|*   13.Lista de Disciplina e alunos matrículados       *|\n");
		printf("|*   14.Lista de Disciplinas com mais de 40 vagas       *|\n");
		printf("|*                                                      *|\n");
		printf("|********************************************************|\n");
		printf("|________________________________________________________|\n");

		scanf("%d",&escolha);
		setbuf(stdin, NULL);

		return escolha;

}

int mainMenuRelatorios(){

	Individuo cadastro_alunos[TAM];
	Individuo_temp cadastro_alunos_temp[TAM];
	Individuo cadastro_professores[TAM];
	Disciplina cadastro_disciplinas[TAM];

	int quantidade_alunos = 0;
	int quantidade_professores = 0;
	int quantidade_disciplinas = 0;

	int escolha = 0;
	int true = 1;

	while(true){

		escolha = menuRelatorios(escolha);

		switch(escolha) {

			case 1: {

				printf("\n*** Lista geral - Alunos(as) ***\n");
				listarIndividuo(quantidade_alunos, cadastro_alunos);
				break;

			}

			case 2: {

				printf("\n*** Lista por sexo - Alunos(as) ***\n");
				listarIndividuoSexo(quantidade_alunos, cadastro_alunos);
				break;

			}

			case 3: {


				break;

			}

			case 4: {



				break;

			}

			case 5: {



				break;

			}
			case 6: {



				break;

			}
			case 7: {



				break;

			}
			case 8: {



				break;

			}
			case 9: {



				break;

			}
			case 10: {



				break;

			}
			case 11: {



				break;

			}

			case 12: {



				break;

			}
			case 13: {



				break;

			}
			case 14: {



				break;

			}

			default: {

				printf("\nOpção inválida.\n");
				break;

			}

		}

	}

	return 0;

}
