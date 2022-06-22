#include "menu.h"

// Função auxiliar que deixa a string minúscula
// Pré-condição: ponteiro válido para uma string
// Pós-condição: string convertida
void lowerStr(char *str){
  for(; *str; str++) *str = tolower(*str);
}

// Imprime o menu principal para o usuário
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void mostraOpcoes(){
  printf("Selecione uma das opcoes abaixo\n\n");

  printf("1-> Inserir palavra\n");                     
  printf("2-> Remover palavra\n");             
  printf("3-> Carregar arquivo de insercao\n"); 
  printf("4-> Carregar arquivo de stopwords\n"); 
  printf("5-> Imprimir dicionario\n");   
  printf("6-> Imprimir arvore por nivel\n");   
  printf("7-> Consultar palavras com prefixo\n");   
  printf("8-> Contar palavras existentes na árvore\n");   
  printf("-1-> Sair\n\n");
}

// Chama uma função que imprime as opções, lê a entra da do usuário e chama a função escolhida pelo usuário
// Pré-condição: Nenhuma
// Pós-condição: Chamará a função desejada pelo usuário
void menuEntrada(arvoreTRIE r){
  int option = -2;
  
  while (option != -1){
    mostraOpcoes();
    scanf("%d", &option);

  	switch(option){
	    case 1: {
	      inserirPalavra(&r);
	      break;
	    }
	    case 2:{
	      removerPalavra(&r);
	      break;
	    }
	    case 3:{
	      carregarArqInsercao(&r);
	      break;
	    }
	    case 4:{
	      carregarArqRemocao(&r);
	      break;
	    }
      case 5:{
        printPalavras(r);
        break;
      }
	    case 6:{
	      print_niveis(r);
	      break;
	    }
      case 7:{
        consultarPrefixo(r);
        break;
      }
      case 8:{
        contarPalavrasArvore(r);
        break;
      }
	    default:{
	      break;
	    }
    }
  }
}

void inserirPalavra(arvoreTRIE *r){
  char palavra[MAX];
  printf("Insira a palavra: \n");
	scanf("%*c%[^\n]%*c", palavra);
  lowerStr(palavra);
  inserir(r, palavra); printf("\n");
}

void removerPalavra(arvoreTRIE *r){
  char palavra[MAX];
  printf("Insira a palavra para remover: \n");
	scanf("%*c%[^\n]%*c", palavra);
  lowerStr(palavra);
  remover(r, palavra); printf("\n");
}

void carregarArqInsercao(arvoreTRIE *r){
	char nomeArq[100];
  printf("\nCarregar informacoes de arquivo texto\n");
  printf("Insira o nome do arquivo de texto: \n");
	scanf("%*c%[^\n]%*c", nomeArq);
	printf("\n");
	
  FILE *arq = fopen(nomeArq, "r");
  char linha[MAX]; int i = 0;

	while(fscanf(arq, "%[^\n]%*c", linha) != EOF) {
    lowerStr(linha);
    inserir(r, linha);
    i++;
  }
  fclose(arq);
  printf("Arquivo carregado. %d palavras inseridas\n", i);
}

void carregarArqRemocao(arvoreTRIE *r){
	char nomeArq[100];
  printf("\nRemover palavras a partir de arquivo texto\n");
  printf("Insira o nome do arquivo de texto: \n");
	scanf("%*c%[^\n]%*c", nomeArq);
	printf("\n");
	
  FILE *arq = fopen(nomeArq, "r");
  char linha[MAX]; int i = 0;

	while(fscanf(arq, "%[^\n]%*c", linha) != EOF) {
    lowerStr(linha);
    if(remover(r, linha)) {
      i++;
    }
  }
  fclose(arq);
  printf("Arquivo carregado. %d palavras removidas\n", i);
}

void consultarPrefixo(arvoreTRIE r){
  char prefixo[MAX];
  printf("Insira o prefixo a ser pesquisado: \n");
	scanf("%*c%[^\n]%*c", prefixo);
  lowerStr(prefixo);
  printf("Palavras encontradas:\n");
  consultarPalavra(r, prefixo); printf("\n");
}

void contarPalavrasArvore(arvoreTRIE r){
  printf("Numero de palavras na arvore: %d\n", contarPalavras(r));
}