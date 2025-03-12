#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

/** 
 * @brief Cadastra um novo produto no vetor de produtos.
*/
void cadastrarProduto(Produto** vetorProdutos, int* tamanho, int* alocado){
    Produto *p = (Produto*) malloc(sizeof(Produto));

    scanf("%s %f %d\n", p->nome, &p->preco, &p->quantidade);

    for (int i = 0; i < *tamanho; i++){
        if (strcmp(p->nome, vetorProdutos[i]->nome) == 0){
            vetorProdutos[i]->preco = p->preco;
            vetorProdutos[i]->quantidade += p->quantidade;
            return;
        }
    }

    if (*alocado == *tamanho){
        (*alocado) += 3;
        vetorProdutos = realloc(vetorProdutos, *alocado * sizeof(Produto*));
    }

    vetorProdutos[*tamanho] = p;
    (*tamanho)++;
}

/** 
 * @brief Exibe a lista de produtos ordenada.
*/
void exibirLista(Produto** vetorProdutos, int tamanho){
    ordenarLista(vetorProdutos, tamanho);

    printf("Lista de produtos cadastrados:\n");

    for (int i = 0; i < tamanho; i++){
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", vetorProdutos[i]->nome);
        printf("Preco: %.2f\n", vetorProdutos[i]->preco);
        printf("Quantidade em estoque: %d\n", vetorProdutos[i]->quantidade);
    }
}

/** 
 * @brief Compara dois produtos.
*/
int compararProduto(const void* a, const void* b){
    Produto *p1 = *(Produto**)a;
    Produto *p2 = *(Produto**)b;
    int valorEstoque1 = p1->quantidade * p1->preco;
    int valorEstoque2 = p2->quantidade * p2->preco;

    int diff; //= valorEstoque1 - valorEstoque2;

    if (valorEstoque1 - valorEstoque2 < 0) diff = -1;
    else if (valorEstoque1 - valorEstoque2 > 0) diff = 1;

    /*if (diff != 0) {
        return diff;
    }*/

    else {
        return (strcmp(p1->nome, p2->nome));
    }

    return diff;
}

/** 
 * @brief Ordena a lista de produtos.
*/
void ordenarLista(Produto** vetorProdutos, int tamanho){
    int troca;

    for (int j = 0; j < tamanho - 1; j++){
        for (int i = 0; i < tamanho - 1; i++){
            troca = compararProduto((void*)vetorProdutos[i], (void*)vetorProdutos[i + 1]);
            if (troca < 0){
                Produto *temp = vetorProdutos[i];
                vetorProdutos[i] = vetorProdutos[i + 1];
                vetorProdutos[i + 1] = temp;
            }
        }
    }
}

/** 
 * @brief Desaloca a lista de produtos e todos os seus produtos.
*/
void desalocaLista(Produto** vetorProdutos, int tamanho){
    if (vetorProdutos != NULL){
        for (int i = 0; i < tamanho; i++){
            free(vetorProdutos[i]);
        }

        free(vetorProdutos);
    }
}

/** 
 * @brief Escreve a lista em um arquivo binário.
*/
void salvarLista(Produto** vetorProdutos, int tamanho){
    FILE *arq = fopen("produtos.bin", "wb");

    fwrite(&tamanho, sizeof(int), 1, arq);

    for (int i = 0; i < tamanho; i++){
        fwrite(vetorProdutos[i], sizeof(Produto), 1, arq);
    }
    
    fclose(arq);
}

/** 
 * @brief Le uma lista de produtos salva em formato binário e a retorna.
*/
Produto** lerLista(int* tamanho, int* alocado){
    FILE *arq = fopen("produtos.bin", "rb");

    fread(&tamanho, sizeof(int), 1, arq);
    Produto **vetorProdutos = (Produto**) calloc(*tamanho, sizeof(Produto*));

    for (int i = 0; i < tamanho; i++){
        vetorProdutos[i] = (Produto*) malloc(sizeof(Produto));
        fread(vetorProdutos[i], sizeof(Produto), 1, arq);
    }
    

    fclose(arq);

    return vetorProdutos;
}