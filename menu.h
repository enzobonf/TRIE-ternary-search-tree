#ifndef MENU_H
#define MENU_H
#include <ctype.h>

#include "trie.h"

// Chama uma função que imprime as opções, lê a entra da do usuário e chama a função escolhida pelo usuário
// Pré-condição: Nenhuma
// Pós-condição: Chamará a função desejada pelo usuário
void menuEntrada(arvoreTRIE r);


// Lê os dados e insere um profissional
// Pré-condição: o código não existir na árvore
// Pós-condição: o profissional será adicionado a árvore
void inserirPalavra(arvoreTRIE *r);

// Remove um profissional da árvore
// Pré-condição: o código existir na árvore
// Pós-condição: o profissional será removido da árvore
void removerPalavra(arvoreTRIE *r);

// Altera o endereço de um determinado profissional
// Pré-condição: o código existir na árvore
// Pós-condição: será alterado o endereço do profissional
void alterarEndereco();

// Imprime todos os códigos da forma como eles estariam na árvore
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void imprimirNivel();

void carregarArqInsercao(arvoreTRIE *r);
void carregarArqRemocao(arvoreTRIE *r);

void consultarPrefixo(arvoreTRIE r);

void contarPalavrasArvore(arvoreTRIE r);


#endif //MENU_H