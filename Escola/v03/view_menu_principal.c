#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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
	printf("|   1.Cadastrar   |    6.Cadastrar      |     9.Cadastrar      |\n");//ok
	printf("|   2.Matricular  |    7.Remover        |     10.Remover       |\n");//ok
	printf("|   3.Remover     |    8.Atualizar      |     11.Atualizar     |\n");//ok
	printf("|   4.Atualizar   |                     |                      |\n");//ok
	printf("|   5.Trancar     |                     |                      |\n");//ok
	printf("|_________________|_____________________|______________________|\n");
	printf("|                                                              |\n");
	printf("|                      * RELATÓRIOS *                          |\n");
	printf("|______________________________________________________________|\n");
	printf("|*                                                            *|\n");
	printf("|*                         ALUNOS                             *|\n");
	printf("|*                                                            *|\n");
	printf("|*    12.Listar Alunos(as)                                    *|\n");//ok
	printf("|*    13.Listar Alunos(as) por sexo                           *|\n");//ok
	printf("|*    14.Listar Alunos(as) por ordem alfabética               *|\n");//ok
	printf("|*    15.Listar Alunos(as) por nascimento                     *|\n");//ok
	printf("|*    16.Lista de alunos em menos de 3 disciplinas            *|\n");//em andamento
	printf("|*                                                            *|\n");
	printf("|**************************************************************|\n");
	printf("|*                                                            *|\n");
	printf("|*                       PROFESORES                           *|\n");
	printf("|*                                                            *|\n");
	printf("|*    17.Listar Professores                                   *|\n");//ok
	printf("|*    18.Listar Professores(as) por sexo                      *|\n");//ok
	printf("|*    19.Listar Professores(as) por ordem alfabética          *|\n");//ok
	printf("|*    20.Listar Professores(as) por data de nascimento        *|\n");//ok
	printf("|*                                                            *|\n");
	printf("|**************************************************************|\n");
	printf("|*                                                            *|\n");
	printf("|*                       DISCIPLINAS                          *|\n");
	printf("|*                                                            *|\n");
	printf("|*    21.Listar Disciplinas                                   *|\n");//ok
	printf("|*    22.Lista de Disciplinas e alunos matrículados           *|\n");//ok
	printf("|*    23.Lista de Disciplinas com mais de 40 vagas            *|\n");//ok
	printf("|*                                                            *|\n");
	printf("|**************************************************************|\n");
	printf("|*                                                            *|\n");
	printf("|*    24.Aniversariantes do mês                               *|\n");//ok
	printf("|*    25.Procurar alunos ou professores no sistema            *|\n");//ok
	printf("|*                                                            *|\n");
	printf("|**************************************************************|\n");
	printf("|*   26.Sair                                                  *|\n");
	printf("|______________________________________________________________|\n");

	scanf("%d",&opcao);
	setbuf(stdin, NULL);

	return opcao;

}

int main(){

	Individuo cadastro_alunos[TAM];
	Individuo cadastro_professores[TAM];
	Disciplina cadastro_disciplinas[TAM];
	Individuo_temp cadastro_alunos_temp[TAM];
	Individuo_temp cadastro_professores_temp[TAM];

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

					printf("\n*** Cadastre um perfil ***\n\n");
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

				if(quantidade_alunos < TAM){

					printf("\n*** Matricule um aluno(a) ***\n\n");
					matricularAlunoDisciplinas(quantidade_disciplinas, cadastro_disciplinas, quantidade_alunos, cadastro_alunos);
					printf("Matricula realizada\n");
					break;

				}else{

					printf("Erro ao cadastrar.\n");
					break;

				}

			}
			case 3:{

				if(quantidade_alunos > 0){

					printf("\n*** Remova um perfil ***\n\n");
					removerIndividuo(quantidade_alunos, cadastro_alunos);
					printf("Remoção realizada\n");
					break;

				}else{

					printf("Não foi possível remover o discente.");
					break;

				}

			}
			case 4:{

				if(quantidade_alunos > 0){

					printf("\n*** Atualize um perfil ***\n\n");
					alterarIndividuo(quantidade_alunos, cadastro_alunos);
					printf("Atualização realizada\n");
					break;

				}else{

					printf("Não foi possível atualizar o perfil.");
					break;

				}

			}
			case 5:{

				if(quantidade_alunos > 0){

					printf("\n*** Tranque uma matricula ***\n\n");
					removerAlunoDisciplinas(quantidade_disciplinas, cadastro_disciplinas);
					printf("Atualização realizada\n");
					break;

				}else{

					printf("Não foi possível trancar a disciplina.");
					break;

				}

			}
			case 6: {

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
			case 7:{

				if(quantidade_professores > 0){

					printf("\n*** Remova um perfil ***\n\n");
					removerIndividuo(quantidade_professores, cadastro_professores);
					printf("Remoção realizada\n");
					break;

				}else{

					printf("Não foi possível remover o docente.");
					break;

				}

			}
			case 8:{

				if(quantidade_professores > 0){

					printf("\n*** Atualize um perfil ***\n\n");
					alterarIndividuo(quantidade_professores, cadastro_professores);
					printf("Atualização realizada\n");
					break;

				}else{

					printf("Não foi possível atualizar o perfil.");
					break;

				}

			}
			case 9:{

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
			case 10:{

				if(quantidade_disciplinas > 0){

					printf("\n*** Remova uma disciplina ***\n\n");
					removerDisciplinas(quantidade_disciplinas, cadastro_disciplinas);
					printf("Remoção realizada\n");
					break;

				}else{

					printf("Não foi possível remover a disciplina.");
					break;

				}

			}
			case 11:{

				if(quantidade_disciplinas > 0){

					printf("\n*** Atualize uma disciplina ***\n\n");
					alterarDisciplinas(quantidade_disciplinas, cadastro_disciplinas, quantidade_professores);
					printf("Atualização realizada\n");
					break;

				}else{

					printf("Não foi possível atualizar o perfil.");
					break;

				}

			}
			case 12: {

				printf("\n*** Lista geral - Alunos(as) ***\n");
				listarIndividuo(quantidade_alunos, cadastro_alunos);
				break;

			}

			case 13: {

				printf("\n*** Lista por sexo - Alunos(as) ***\n\n");
				listarIndividuoSexo(quantidade_alunos, cadastro_alunos);
				break;

			}
			case 14: {

				printf("\n*** Lista por nome - Alunos(as) ***\n\n");
				listarIndividuoSortPorNome(quantidade_alunos, cadastro_alunos, cadastro_alunos_temp);
				break;

			}
			case 15: {

				printf("\n*** Lista por data de nascimento - Alunos(as) ***\n\n");
				listarIndividuosSortPorData(quantidade_alunos, cadastro_alunos, cadastro_alunos_temp);

				break;

			}
			case 16: {

				printf("\n*** Lista de alunos em menos de 3 disciplinas ***\n\n");
				listarAlunoEmMaisDe3Disciplinas(quantidade_disciplinas, cadastro_disciplinas, quantidade_alunos, cadastro_alunos);
				break;

			}
			case 17: {

				printf("\n*** Lista geral - Professores(as) ***\n");
				listarIndividuo(quantidade_professores, cadastro_professores);
				break;

			}

			case 18: {

				printf("\n*** Lista por sexo - Professores(as) ***\n\n");
				listarIndividuoSexo(quantidade_professores, cadastro_professores);
				break;

			}
			case 19: {

				printf("\n*** Lista por nome - Professores(as) ***\n\n");
				listarIndividuoSortPorNome(quantidade_professores, cadastro_professores, cadastro_professores_temp);
				break;

			}
			case 20: {

				printf("\n*** Lista por data de nascimento - Professores(as) ***\n\n");
				listarIndividuosSortPorData(quantidade_professores, cadastro_professores, cadastro_professores_temp);

				break;

			}
			case 21: {

				printf("\n*** Lista geral - Disciplinas ***\n\n");
				listarDisciplinas(quantidade_disciplinas, cadastro_disciplinas);

				break;

			}
			case 22: {

				printf("\n*** Lista alunos(as) matriculados ***\n\n");
				listarAlunoDisciplinas(quantidade_disciplinas, cadastro_disciplinas, quantidade_professores, cadastro_professores);
				break;

			}
			case 23: {

				printf("\n*** Lista de Disciplinas com mais de 40 vagas ***\n\n");
				listarAlunoDisciplinasMaisDe40Vagas(quantidade_disciplinas, cadastro_disciplinas, quantidade_professores, cadastro_professores);


				break;

			}case 24: {

				printf("\n*** Aniversariantes do mês ***\n\n");
				listarAniversariantes(quantidade_alunos, cadastro_alunos, quantidade_professores,cadastro_professores);
				break;

			}
			case 25: {

				printf("\n*** Procurar ***\n\n");
				listarProcuraNome(quantidade_alunos, cadastro_alunos, quantidade_professores,cadastro_professores);
				break;

			}

			case 26:{

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

