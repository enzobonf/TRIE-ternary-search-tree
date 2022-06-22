#include "trie.h"

int maior(int a, int b, int c){
  int maior1 = a > b ? a : b;
  return maior1 > c ? maior1 : c;
}

int vazia(arvoreTRIE *r){
 return !(*r);
}

int ehFolha(arvoreTRIE *r){
  return vazia(&((*r)->esq)) && vazia(&((*r))->meio)
    && vazia(&((*r)->dir));
}

arvoreTRIE criaNoTrie(char ch){

  struct noTrie *auxNo;

  auxNo = (struct noTrie*) malloc(sizeof(struct noTrie));
  auxNo->ch = ch;
  auxNo->ehFim = 0;
  
  auxNo->esq = auxNo->meio = auxNo->dir = NULL;

  return auxNo;
  
}

void inserir(arvoreTRIE *r, char *str){

  if(vazia(r)){
    *r = criaNoTrie(*str);
  }
  if((*str) < (*r)->ch){
    inserir(&((*r)->esq), str);
  }
  else if((*str) > (*r)->ch){
    inserir(&((*r)->dir), str);
  }
  else{
    if(*(str+1)){
      inserir(&((*r)->meio), str+1);
    }
    else{
      (*r)->ehFim = 1;
    }
  }
  
}

void printPalavras_aux(arvoreTRIE r, char *buffer, int nivel, int *limit){

  if(*limit > 0 && !vazia(&r)){

    printPalavras_aux(r->esq, buffer, nivel, limit);
    buffer[nivel] = r->ch;

    if(r->ehFim){
      buffer[nivel+1] = '\0';
      printf("%s\n", buffer);
      *limit = *limit - 1;
    }

    printPalavras_aux(r->meio, buffer, nivel+1, limit);
    printPalavras_aux(r->dir, buffer, nivel, limit);
    
  }
  
}

void printPalavras(arvoreTRIE r){

  char buffer[MAX];
  int limit = 999999;
  printPalavras_aux(r, buffer, 0, &limit);
  
}

void removeNo_aux(struct noTrie** no){

  if(vazia(no) || (*no)->ehFim == 1) return;
    
  struct noTrie* oldNo = (*no);
  if(!vazia(&((*no)->esq))){
    (*no) = (*no)->esq;
    (*no)->dir = oldNo->dir;
  }
  else{
    (*no) = (*no)->dir;
  }

  free(oldNo);
}

int remover(arvoreTRIE *r, char *str){

  if(vazia(r)) return 0;
  
  if((*str) == (*r)->ch){

    if(*(str+1)){
      if(remover(&((*r)->meio), str+1)){

        if(ehFolha(r) && (*r)->ehFim == 0){
          free(*r);
          (*r) = NULL;
        }
        else if(vazia(&((*r)->meio))){

          if((*r)->ehFim){
            (*r)->ehFim = 0;
            return 1;
          }
          
          removeNo_aux(&(*r));
          
        }
        
        return 1;
        
      }
    }
    else if((*r)->ehFim){
      
      if(ehFolha(r)){
        free(*r);
        (*r) = NULL;
        return 1;
      }
      else if((*r)->ehFim){
        (*r)->ehFim = 0;
        return 1;
      }
      
      removeNo_aux(&(*r));
      return 1;
      
    }
    
  }
    
  if((*str) < (*r)->ch){
    return remover(&((*r)->esq), str);
  }
    
  return remover(&((*r)->dir), str);
}

int altura_arvore(arvoreTRIE r){
  if(vazia(&r)) return 0;
  return 1 + maior(altura_arvore(r->esq), altura_arvore(r->meio), altura_arvore(r->dir));
}

void print_nivel(arvoreTRIE r, int nivel){

  if(vazia(&r)) return;

  if(nivel == 1){
    printf("%c ", r->ch);
  }
  else{
    print_nivel(r->esq, nivel-1);
    print_nivel(r->meio, nivel-1);
    print_nivel(r->dir, nivel-1);
  }

  
}

void print_niveis(arvoreTRIE r){

  int i;
  for(i = 1; i <= altura_arvore(r); i++){
    print_nivel(r, i); printf("\n");
  }
  
}

int consultarPalavra_aux(arvoreTRIE r, char *buffer, char *str, int nivel, int limit){

  if(vazia(&r)) return 0;

  if((*str) == r->ch){

    buffer[nivel] = r->ch;
    
    if(*(str+1)){
      return consultarPalavra_aux(r->meio, buffer, str+1, nivel+1, limit);
    }

    if(r->ehFim){
      buffer[nivel+1] = '\0';
      printf("%s\n", buffer);
      limit--;
    }
    
    if(!vazia(&r->meio)){
      printPalavras_aux(r->meio, buffer, nivel+1, &limit);
      return 1;
    }
    
  }
    
  if((*str) < r->ch){
    return consultarPalavra_aux(r->esq, buffer, str, nivel, limit);
  }
    
  return consultarPalavra_aux(r->dir, buffer, str, nivel, limit);
  
}

void consultarPalavra(arvoreTRIE r, char *str){

  char buffer[MAX];
  consultarPalavra_aux(r, buffer, str, 0, 10);
  
}

int contarPalavras(arvoreTRIE r){

  if(vazia(&r)) return 0;

  return r->ehFim + contarPalavras(r->esq) + contarPalavras(r->meio)
    + contarPalavras(r->dir);
  
}

int buscarTST(arvoreTRIE r, char * str){

  if(vazia(&r)) return 0;

  printf("%c %c\n", *str, r->ch);

  if((*str) == r->ch){

    if(*(str+1)){
      return buscarTST(r->meio, str+1);
    }

    return r->ehFim;
    
  }
  
  if((*str) < r->ch){
    return buscarTST(r->esq, str);
  }

  return buscarTST(r->dir, str);

}