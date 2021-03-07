#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 25

typedef struct {

    char nome[SIZE];
    int dia, mes, ano;
    long long cpf;
    char sexo;

}cliente;

cliente cadastroCliente();

int validarData(cliente verifica);
int validarCPF(cliente verifica);
int validarNome(cliente verifica);
int validarSexo(cliente verifica);

int main(void){

    cliente perfil;

    printf("Informe o nome, a data de nascimento (digite o dia, depois o mes e, por fim, o ano),\n o cpf (apenas digitos) e o sexo(M, F ou O):\n"); 
    
    perfil = cadastroCliente();
    
    printf("\n\nCadastro cliente.\n");
    printf("Nome: %s", perfil.nome);
    printf("Nascimento: %d/%d/%d\n", perfil.dia, perfil.mes, perfil.ano);
    printf("CPF: %lld\n", perfil.cpf);
    printf("Sexo: %c\n", toupper(perfil.sexo));
    
    return 0;

}


cliente cadastroCliente()
{
    int validaNome;
    int validaData;
    int validaCPF;
    int validaSexo;
    
    cliente verifica;

    fgets(verifica.nome, SIZE, stdin);
    setbuf(stdin, NULL);
    scanf("%d", &verifica.dia);
    setbuf(stdin, NULL);
    scanf("%d", &verifica.mes);
    setbuf(stdin, NULL);
    scanf("%d", &verifica.ano);
    setbuf(stdin, NULL);
    scanf("%lld", &verifica.cpf);
    setbuf(stdin, NULL);
    scanf("%c", &verifica.sexo);
    setbuf(stdin, NULL);

    validaNome = validarNome(verifica);
    
    if(validaNome != 1) {
    
	printf("\nNome inválido.");
    
    }
    
    validaSexo = validarSexo(verifica);
    
    if(validaSexo != 1) {
    
	printf("\nSexo inválido.");
	
    } 
    
    validaCPF = validarCPF(verifica);
    
    if(validaCPF != 1) {
    
	printf("\nCPF inválido.");
	
    } 
    
    validaData = validarData(verifica);
    
    if(validaCPF != 1) {
    
	printf("\nData inválida.");
	
    } 
    
    return verifica;

}


int validarNome(cliente verifica) {
    
    int valor = strlen(verifica.nome) - 1;

	if(valor < 20 && valor > 0) {
	
	    return 1;
	    
	} else {
	
	    return -1;
	    
	}
	
}


int validarSexo(cliente verifica) {

	verifica.sexo = toupper(verifica.sexo);

	if(verifica.sexo =='F' || verifica.sexo == 'M' || verifica.sexo == 'O') {
	
	    return 1;
		
	} else {
	
	    return -1;
		
	}
	
}

int validarCPF(cliente verifica) {

  
      if(verifica.cpf > 9999999999 && verifica.cpf <= 99999999999){
    
          return 1;
        
      }else {
    
          return -1;
    
      }

}


int validarData(cliente verifica) {
    
    if(verifica.ano >= 1900 && verifica.ano < 2004){
    
          if((verifica.dia >= 1 && verifica.dia <= 31) && 
             (verifica.mes == 1 || verifica.mes == 3 || verifica.mes == 5 || verifica.mes == 7 || verifica.mes == 8 || verifica.mes == 10 || verifica.mes == 12)){
        
              return 1; 
        
          }else if((verifica.dia >= 1 && verifica.dia <= 30) && 
                 (verifica.mes == 4 || verifica.mes == 6 || verifica.mes == 9 || verifica.mes == 11)){
                 
              return 1;         
                 
          }else if((verifica.dia >= 1 && verifica.dia <= 28) && (verifica.mes == 2)){
          
              return 1;
          
          }else if(verifica.dia == 29 && verifica.mes == 2 && (verifica.ano % 400 == 0 || (verifica.ano % 4 == 0 && verifica.ano % 100 != 0))){
          
              return 1;
          
          }else{
          
              return -1;
          
          }
    
    
   }else{
   
       return -1;
   
   }



}






