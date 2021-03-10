#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 25
#define CPF 12

typedef struct dma {
  int dia;
  int mes;
  int ano; 
  
} Data; 

typedef struct {

    char nome[SIZE];
    Data data_nascimento;
    char cpf[CPF];
    char sexo;

}cliente;

cliente cadastroCliente();

int validarData(cliente verifica);
int validarCPF(cliente verifica);
int validarNome(cliente verifica);
int validarSexo(cliente verifica);

int main(void){

    cliente perfil;
    
    
    
    perfil = cadastroCliente();
    
    printf("\n\nCadastro cliente.\n");
    printf("Nome: %s", perfil.nome);
    printf("Nascimento: %d/%d/%d\n", perfil.data_nascimento.dia, perfil.data_nascimento.mes, perfil.data_nascimento.ano);
    printf("CPF: %s\n", perfil.cpf);
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
    
    printf("\nInforme o nome do cliente:\n");
    fgets(verifica.nome, SIZE, stdin);
    setbuf(stdin, NULL);
    printf("\nInforme a data de nascimento do cliente (dd/mm/yyyy):\n");
    scanf("%d", &verifica.data_nascimento.dia);
    setbuf(stdin, NULL);
    scanf("%d", &verifica.data_nascimento.mes);
    setbuf(stdin, NULL);
    scanf("%d", &verifica.data_nascimento.ano);
    setbuf(stdin, NULL);
    printf("\nInforme o CPF do cliente:\n");
    scanf(" %s", verifica.cpf);
    setbuf(stdin, NULL);
    printf("\nInforme o sexo do cliente.\n");
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

    char cpf[12];
    int icpf[12];
    int result1, result2, digito1, digito2, valor;
      
    int somador=0;
    
    strcpy(cpf, verifica.cpf);
  
    for(int i = 0; i < 11; i++){
  
        icpf[i] = cpf[i] - 48;
  
    }
    
     //encontrar o primeiro digito verificador
    for(int i = 0; i < 9; i++)  {
  
        somador += icpf[i] * (10 - i); 
       
    }  
    
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
  
 
  
    if(digito1 == icpf[9] && digito2 == icpf[10]){  

        return 1;
    
    }else{
      
        return -1;
        
    }
    
}


int validarData(cliente verifica) {
    
    if(verifica.data_nascimento.ano >= 1900 && verifica.data_nascimento.ano < 2004){
    
          if((verifica.data_nascimento.dia >= 1 && verifica.data_nascimento.dia <= 31) && 
             (verifica.data_nascimento.mes == 1 || verifica.data_nascimento.mes == 3 || verifica.data_nascimento.mes == 5 || verifica.data_nascimento.mes == 7 || verifica.data_nascimento.mes == 8 || verifica.data_nascimento.mes == 10 || verifica.data_nascimento.mes == 12)){
        
              return 1; 
        
          }else if((verifica.data_nascimento.dia >= 1 && verifica.data_nascimento.dia <= 30) && 
                 (verifica.data_nascimento.mes == 4 || verifica.data_nascimento.mes == 6 || verifica.data_nascimento.mes == 9 || verifica.data_nascimento.mes == 11)){
                 
              return 1;         
                 
          }else if((verifica.data_nascimento.dia >= 1 && verifica.data_nascimento.dia <= 28) && (verifica.data_nascimento.mes == 2)){
          
              return 1;
          
          }else if(verifica.data_nascimento.dia == 29 && verifica.data_nascimento.mes == 2 && (verifica.data_nascimento.ano % 400 == 0 || (verifica.data_nascimento.ano % 4 == 0 && verifica.data_nascimento.ano % 100 != 0))){
          
              return 1;
          
          }else{
          
              return -1;
          
          }
    
    
    }else{
   
       return -1;
   
    }



}






