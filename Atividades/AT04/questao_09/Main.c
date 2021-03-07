#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NOME 25

typedef struct {

    char nome[25];
    int dia, mes, ano;
    float cpf;
    char sexo;

}cliente;

cliente cadastroCliente();

int validarData(cliente perfis);
int validarCPF(cliente perfis);
int validarNome(cliente perfis);
int validarSexo(cliente perfis);

int main(void){

    cliente perfil;

    printf("Informe o nome, a data de nascimento (digite o dia, depois o mes e, por fim, o ano),\n o cpf (apenas digitos) e o sexo(M, F ou O):\n"); 
    
    perfil = cadastroCliente();
    
    printf("\n\nCadastro cliente.\n");
    printf("Nome: %s", perfil.nome);
    printf("Nascimento: %d/%d/%d\n", perfil.dia, perfil.mes, perfil.ano);
    printf("CPF: %.0f\n", perfil.cpf);
    printf("Sexo: %c\n", perfil.sexo);
    
    return 0;

}

int validarNome(cliente perfis) {
    
    int valor = strlen(perfis.nome);

	if(valor - 1 < 20 && valor -1 > 0) {
	
	    return 1;
	    
	} else {
	
	    return -1;
	    
	}
	
}


int validarSexo(cliente perfis) {

	perfis.sexo = toupper(perfis.sexo);

	if(perfis.sexo =='F' || perfis.sexo == 'M' || perfis.sexo == 'O') {
	
	    return 1;
		
	} else {
	
	    return -1;
		
	}
	
}

int validarCPF(cliente perfis) {

  
      if(perfis.cpf > 9999999999 && perfis.cpf <= 99999999999){
    
          return 1;
        
      }else {
    
          return -1;
    
      }

}


int validarData(cliente perfis) {
    
    if(perfis.ano >= 1900 && perfis.ano < 2004){
    
          if((perfis.dia >= 1 && perfis.dia <= 31) && 
             (perfis.mes == 1 || perfis.mes == 3 || perfis.mes == 5 || perfis.mes == 7 || perfis.mes == 8 || perfis.mes == 10 ||perfis.mes == 12)){
        
              return 1; 
        
          }else if((perfis.dia >= 1 && perfis.dia <= 30) && 
                 (perfis.mes == 4 || perfis.mes == 6 || perfis.mes == 9 || perfis.mes == 11)){
                 
              return 1;         
                 
          }else if((perfis.dia >= 1 && perfis.dia <= 28) && (perfis.mes == 2)){
          
              return 1;
          
          }else if(perfis.dia == 29 && perfis.mes == 2 && (perfis.ano % 400 == 0 || (perfis.ano % 4 == 0 && perfis.ano % 100 != 0))){
          
              return 1;
          
          }else{
          
              return -1;
          
          }
    
    
   }else{
   
       return -1;
   
   }



}


cliente cadastroCliente()
{
    int validaNome = 0;
    int validaData = 0;
    int validaCPF = 0;
    int validaSexo = 0;
    
    cliente perfis;

    fgets(perfis.nome, NOME, stdin);
    setbuf(stdin, NULL);
    scanf("%d", &perfis.dia);
    setbuf(stdin, NULL);
    scanf("%d", &perfis.mes);
    setbuf(stdin, NULL);
    scanf("%d", &perfis.ano);
    setbuf(stdin, NULL);
    scanf("%f", &perfis.cpf);
    setbuf(stdin, NULL);
    scanf("%c", &perfis.sexo);
    setbuf(stdin, NULL);

    validaNome = validarNome(perfis);
    
    if(validaNome != 1) {
    
	printf("\nNome inválido.");
    
    }
    
    validaSexo = validarSexo(perfis);
    
    if(validaSexo != 1) {
    
	printf("\nSexo inválido.");
	
    } 
    
    validaCPF = validarCPF(perfis);
    
    if(validaCPF != 1) {
    
	printf("\nCPF inválido.");
	
    } 
    
    validaData = validarData(perfis);
    
    if(validaCPF != 1) {
    
	printf("\nData inválida.");
	
    } 
    
    return perfis;

}





