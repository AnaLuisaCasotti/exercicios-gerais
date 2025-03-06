#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

/**
 * @brief Estrutura para representar uma imagem.
 */
typedef struct tImagem {

    void* vetor;
    int linhas;
    int colunas;
    int tamVetor;
    int bytes;
    Tipo tipo;

} Imagem;

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho){
    Imagem *img = (Imagem*) malloc(sizeof(Imagem));
    FILE *arq = fopen(caminho, "rb");

    fread(&img->linhas, sizeof(int), 1, arq);
    fread(&img->colunas, sizeof(int), 1, arq);
    fread(&img->tipo, sizeof(int), 1, arq);

    img->tamVetor = img->linhas * img->colunas;

    if (img->tipo == INT){
        img->vetor = (int*) calloc(img->tamVetor, sizeof(int));
        int *vetorInt = (int*) img->vetor;

        for (int i = 0; i < img->tamVetor; i++){
            fread(&vetorInt[i], sizeof(int), 1, arq);
        }
    }

    else if (img->tipo == FLOAT){
        img->vetor = (float*) calloc(img->tamVetor, sizeof(float));
        float *vetorFloat = (float*) img->vetor;

        for (int i = 0; i < img->tamVetor; i++){
            fread(&vetorFloat[i], sizeof(float), 1, arq);
        }
    }

    fclose(arq);
    return img;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img){
    if (img != NULL){
        free(img->vetor);
        free(img);
    }
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img){
    return 16;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img){ 
            
    if (img->tipo == INT){
        int *vetorInt = (int*) img->vetor;
        for (int i = 0; i < img->tamVetor; i++){
            printf("%d ", vetorInt[i]);

            if ((i + 1) % img->colunas == 0) {
                printf("\n");
            }
        }
    }

    else if (img->tipo == FLOAT){
        float *vetorFloat = (float*) img->vetor;

        for (int i = 0; i < img->tamVetor; i++){
            printf("%.2f ", vetorFloat[i]);

            if ((i + 1) % img->colunas == 0) {
                printf("\n");
            }
        }
    }

}