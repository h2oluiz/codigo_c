//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Constantes
#define tamanho 5

//Estrutura da Fila
struct tfila {
  int dados[tamanho];
  int ini;
  int fim;   
};

//Estrutura da Pilha
struct tpilha {
  int dados[tamanho];
  int ini;
  int fim;   
};

//Variáveis globais
tfila fila;
tpilha pilha;
int op;

//Protipação
void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();
void pilha_entrar();
void pilha_mostrar();

//Função principal
int main(){
  setlocale(LC_ALL, "Portuguese");    
  op = 1;  
  fila.ini = 0;
  fila.fim = 0;
  
  pilha.ini = 5;
  pilha.fim = 0;
  
  while (op != 0) {
    system("cls");  
    fila_mostrar();
    pilha_mostrar();
    menu_mostrar();
    scanf("%d", &op);
    switch (op) {
      case 1:
        fila_entrar();
      break;
      case 2:
        fila_sair();	
      break;
      case 3:
        pilha_entrar();	
      break;
    }      
  }  
  return(0);
}

//Adicionar um elemento no final da Fila
void fila_entrar(){
  if (fila.fim == tamanho) {
    printf("\nA fila está cheia, impossível adicionar um novo valor!\n\n");          
    system("pause");      
  }   
  else {    
    printf("\nDigite o valor a ser inserido: ");        
    scanf("%d", &fila.dados[fila.fim]);  
    fila.fim++;  
  }  
}

//Retirar o primeiro elemento da Fila
void fila_sair() {
  if (fila.ini == fila.fim) {
    printf("\nA fila está vazia, não há nada para remover!\n\n");          
    system("pause");      
  }          
  else {
    int i;   
    for (i = 0; i < tamanho; i++) {
      fila.dados[i] = fila.dados[i+1];          
    }  
    fila.dados[fila.fim] = 0;
    fila.fim--;
  }  
}

//Mostrar o conteúdo da Fila
void fila_mostrar() {
  int i;   
  printf("Fila: [  ");         
  for (i = 0; i < tamanho; i++) {
    printf("%d  ", fila.dados[i]);          
  }
  printf("]\n\n");         
}

// Tratando a Pilha

void pilha_entrar(){
 
  if (pilha.fim == tamanho) {
    printf("\nA pilha está cheia, impossível adicionar um novo valor!\n\n");          
    system("pause");      
  }   
  else {    
    printf("\nDigite o valor a ser inserido: ");        
    scanf("%d", &pilha.dados[pilha.fim]);  
    pilha.ini--;  
  }  
}


//Mostrar o conteúdo da Fila
void pilha_mostrar() {
  int i;   
  printf("Pilha: [  ");         
  for (i = 0; i < tamanho; i++) {
    printf("%d  ", pilha.dados[i]);          
  }
  printf("]\n\n");         
}

//Mostrar o menu de opções
void menu_mostrar() {
  printf("\nEscolha uma opcao:\n");        
  printf("1 - Incluir na Fila\n");            
  printf("2 - Excluir da Fila\n");
  printf("3 - Saida como Pilha\n");
  printf("0 - Sair\n\n");           
}
