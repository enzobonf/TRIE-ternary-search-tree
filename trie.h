#ifndef TRIE_H
#define TRIE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 50

struct noTrie {
  char ch;
  unsigned ehFim;
  struct noTrie* esq;
  struct noTrie* meio;
  struct noTrie* dir;
};

typedef struct noTrie* arvoreTRIE;

void inserir(arvoreTRIE *r, char *str);
arvoreTRIE criaNoTrie(char ch);

int remover(arvoreTRIE *r, char *str);

void printPalavras(arvoreTRIE r);

int vazia(arvoreTRIE *r);
int ehFolha(arvoreTRIE *r);

int altura_arvore(arvoreTRIE r);

void print_nivel(arvoreTRIE r, int nivel);
void print_niveis(arvoreTRIE r);

void consultarPalavra(arvoreTRIE r, char *str);

int contarPalavras(arvoreTRIE r);

int buscarTST(arvoreTRIE r, char * str);

#endif