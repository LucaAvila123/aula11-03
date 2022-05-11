#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    int nlinhas;
    int ncolunas;
    int** matriz;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    if(nlinhas <= 0 || ncolunas <= 0){
        printf("números incorretos para inicializar matriz, faz isso direito\n");
        exit(1);
    }
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));

    mat->nlinhas = nlinhas;
    mat->ncolunas = ncolunas;
    
    mat->matriz = (int**)malloc(nlinhas*(sizeof(int*)));

    for(int i=0; i<nlinhas; i++)
        mat->matriz[i] = (int*)malloc(ncolunas*sizeof(int));
    
    for(int i=0; i<nlinhas; i++){
        for(int j=0; j<ncolunas; j++){
            mat->matriz[i][j] = 0;
            //printf("%d ", mat->matriz[i][j]);
        }
    }   
    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){ 
    if(mat==NULL){
        printf("Eh, amigao, ta fazendo besteira. Insira matriz valida\n");
        exit(1);
    }
    if(linha > mat->nlinhas || linha < 0){
        printf("Linha invalida");
        exit(1);
    }
    if(coluna > mat->ncolunas || coluna < 0){
        printf("Coluna invalida");
        exit(1);
    }
    mat->matriz[linha][coluna] = elem; 
}

int recuperaElemento(Matriz* mat, int linha, int coluna){ 
    if(mat==NULL){
        printf("Eh, amigao, ta fazendo besteira. Insira matriz valida\n");
        exit(1);
    }
    if(linha > mat->nlinhas || linha < 0){
        printf("Linha invalida");
        exit(1);
    }
    if(coluna > mat->ncolunas || coluna < 0){
        printf("Coluna invalida");
        exit(1);
    }
    return mat->matriz[linha][coluna]; 
}

int recuperaNColunas (Matriz* mat){ 
    if(mat==NULL){
        printf("Eh, amigao, ta fazendo besteira. Insira matriz valida\n");
        exit(1);
    }
    return mat->ncolunas; 
}

int recuperaNLinhas (Matriz* mat){ 
    if(mat==NULL){
        printf("Eh, amigao, ta fazendo besteira. Insira matriz valida\n");
        exit(1);
    }
    return mat->nlinhas; 
}

Matriz* transposta (Matriz* mat){
    if(mat==NULL){
        printf("Eh, amigao, ta fazendo besteira. Insira matriz valida\n");
        exit(1);
    }
    Matriz* matrizTransposta = (Matriz*) malloc (sizeof(Matriz));
    int nlinhas = mat->ncolunas;
    int ncolunas = mat->nlinhas;

    matrizTransposta->nlinhas = nlinhas;
    matrizTransposta->ncolunas = ncolunas;

    matrizTransposta->matriz = (int**)malloc(nlinhas*(sizeof(int*)));

    for(int i=0; i<nlinhas; i++)
        matrizTransposta->matriz[i] = (int*)malloc(ncolunas*sizeof(int));
    
    for(int i=0; i<nlinhas; i++){
        for(int j=0; j<ncolunas; j++){
            matrizTransposta->matriz[i][j] = mat->matriz[j][i];
            //printf("%d ", mat->matriz[i][j]);
        }
    }

    return matrizTransposta;   
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(mat1==NULL || mat2==NULL){
        printf("Eh, amigao, ta fazendo besteira. Insira matriz valida\n");
        exit(1);
    }
    if(mat1->nlinhas != mat2->ncolunas){
        printf("numero de linhas da primeira matriz nao eh igual ao numero de colunas da segunda\n");
        printf("EH SIMPLESMENTE IMPOSSIVEL CALCULAR ESSA MULTIPLICACAO, MEU CAMARADA\n");
        exit(1);
    }
    Matriz* resultado = (Matriz*) malloc (sizeof(Matriz));
    int nlinhas = mat1->nlinhas;
    int ncolunas = mat2->ncolunas;

    resultado->nlinhas = nlinhas;
    resultado->ncolunas = ncolunas;

    resultado->matriz = (int**)malloc(nlinhas*(sizeof(int*)));

    for(int i=0; i<nlinhas; i++)
        resultado->matriz[i] = (int*)malloc(ncolunas*sizeof(int));

    int final = 0;

    for(int i=0; i<nlinhas; i++){
        for(int j=0; j<ncolunas; j++){
            for(int m=0; m<mat1->ncolunas; m++){
                final += mat1->matriz[i][m]*mat2->matriz[m][j];
            }
            resultado->matriz[i][j] = final;
            final = 0;
        }
    }
    
    return resultado;
}

void imprimeMatriz(Matriz* mat){
    if(mat==NULL){
        printf("Eh, amigao, ta fazendo besteira. Insira matriz valida\n");
        exit(1);
    }
    for(int i=0; i<mat->nlinhas; i++){
        for(int j=0; j<mat->ncolunas; j++){
            printf("%d ", mat->matriz[i][j]);
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat){
    if(mat==NULL){
        printf("Eh, amigao, ta fazendo besteira. Insira matriz valida\n");
        exit(1);
    }
    for(int i=0; i<mat->nlinhas; i++)
        free(mat->matriz[i]);

    free(mat->matriz);
    free(mat);
}