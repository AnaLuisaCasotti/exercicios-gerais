#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

int main(){
    Produto **vetorProdutos = (Produto**) calloc(5, sizeof(Produto*));
    int alocado = 5, tamanho = 0;
    int opcao;

    while(1){
        printf("===== Sistema de Registro de Produtos =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Exibir lista de produtos cadastrados\n");
        printf("3 - Salvar lista de produtos em arquivo\n");
        printf("4 - Ler lista de produtos de arquivo\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opcao: ");

        scanf("%d\n", &opcao);

        if (opcao == 1){
            cadastrarProduto(vetorProdutos, &tamanho, &alocado);
        }

        else if (opcao == 2){
            exibirLista(vetorProdutos, tamanho);
        }

        else if (opcao == 3){
            salvarLista(vetorProdutos, tamanho);
            desalocaLista(vetorProdutos, tamanho);
            printf("Lista de produtos salva no arquivo 'produtos.bin'.\n");
        }

        else if (opcao == 4){
            lerLista(&tamanho, &alocado);
        }

        else if (opcao == 5){
            desalocaLista(vetorProdutos, tamanho);
            printf("Encerrando o programa.\n\n");
            break;
        }
        printf("\n");
    }

    return 0;
}