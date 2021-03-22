#define TAM 40

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
	char codigo[TAM];
	char semestre;

}Disciplina;

//menu
int menuPrincipal(int escolha);
int menuRelatorios(int escolha);

//métodos para indivíduos
void cadastrarIndividuo(int quantidade, Individuo cadastro[]);
void listarIndividuo(int quantidade, Individuo cadastro[]);
void alterarIndividuo(int quantidade, Individuo cadastro[]);
void removerIndividuo(int quantidade, Individuo cadastro[]);

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
