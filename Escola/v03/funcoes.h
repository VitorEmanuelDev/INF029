#define TAM 45

typedef struct dados_01{

	char data_nascimento[TAM];
	char matricula[TAM];
	char nome[TAM];
	char cpf[TAM];
	char sexo;

}Individuo;

typedef struct dados_02{

	char data_nascimento_temp[TAM];
	char matricula_temp[TAM];
	char nome_temp[TAM];
	char cpf_temp[TAM];
	char sexo_temp;

}Individuo_temp;

typedef struct dados_03{

	char nome[TAM];
	char professor[TAM];
	char codigo[TAM];
	char semestre;

}Disciplina;

typedef struct dados_04{

	char nome_temp[TAM];
	char professor_temp[TAM];
	char codigo_temp[TAM];
	char semestre_temp;

}Disciplina_temp;

struct tm* tempo_atual;

//menu
int menuPrincipal(int escolha);

//métodos para indivíduos
void cadastrarIndividuo(int quantidade, Individuo cadastro[]);
void listarIndividuo(int quantidade, Individuo cadastro[]);
void alterarIndividuo(int quantidade, Individuo cadastro[]);
void removerIndividuo(int quantidade, Individuo cadastro[]);
void listarIndividuoSexo(int quantidade, Individuo cadastro[]);
void listarIndividuoSortPorNome(int quantidade, Individuo cadastro[], Individuo_temp cadastro_temp[]);
void listarProcuraNome(int quantidade_alunos, Individuo cadastro_alunos[], int quantidade_professores, Individuo cadastro_professores[]);
void listarIndividuosSortPorData(int quantidade, Individuo cadastro[], Individuo_temp cadastro_temp[]);
void listarAniversariantes(int quantidade_alunos, Individuo cadastro_alunos[], int quantidade_professores, Individuo cadastro_professores[]);

//métodos para disciplinas
void cadastrarDisciplinas(int quantidade_professores, int quantidade_disciplinas, Disciplina cadastro_disciplinas[], Individuo cadastro_individuos[]);
void listarDisciplinas(int quantidade, Disciplina cadastro[]);
void alterarDisciplinas(int quantidade, Disciplina cadastro[]);
void removerDisciplinas(int quantidade, Disciplina cadastro[]);


//validacoes
int validarMatricula(char matricula[]);
int validarCPF(char cpf[]);
int validarNome(char nome[]);
int validarData(char data_nascimento[]);
int validarSexo(char sexo);
int validarCodigo(char codigo[]);
int validarProfessor(int quantidade_professores, int quantidade_disciplinas, Disciplina cadastro_disciplinas[], Individuo cadastro_professores[]);
int validarSemestre(char semestre);
