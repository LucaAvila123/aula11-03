#include "matriz.h"
#include <stdio.h>
int main(){
    int nlinhas=0, ncolunas=0;
    printf("Insira numero de linhas e numero de colunas para a primeira matriz:");
    scanf("%d %d", &nlinhas, &ncolunas);
    //teste de inicialização
    Matriz* matrizInicial = inicializaMatriz(nlinhas, ncolunas);
    //teste de impressão
    //imprimeMatriz(matrizInicial);

    int k=0;
    //teste de modificação
    for(int i=0; i<nlinhas; i++){
        for(int j=0; j<ncolunas; j++){
            modificaElemento(matrizInicial, i, j, k);
            k++;
        }
    }

    //segunda matriz
    printf("Insira numero de linhas e numero de colunas para a segunda matriz:");
    scanf("%d %d", &nlinhas, &ncolunas);
    Matriz* matrizSegunda = inicializaMatriz(nlinhas, ncolunas);

    
    //preenche segunda matriz
    for(int i=0; i<nlinhas; i++){
        for(int j=0; j<ncolunas; j++){
            modificaElemento(matrizSegunda, i, j, 3*i);
        }
    }

    //teste de transposta
    Matriz* matrizTransposta = transposta(matrizInicial);
    printf("\n");

    //transposta da segunda matriz
    Matriz* matrizTransposta2 = transposta(matrizSegunda);
    
    
    //teste de multiplicação
    Matriz* matrizMultiplicada = multiplicacao(matrizInicial, matrizTransposta);

    //multiplicação da segunda pela transposta
    Matriz* matrizMultiplicada2 = multiplicacao(matrizSegunda, matrizTransposta2);

    //impressoes
    printf("\n");
    printf("Primeira Matriz:\n");
    imprimeMatriz(matrizInicial);

    printf("Primeira Transposta:\n");
    imprimeMatriz(matrizTransposta);

    printf("\n");
    printf("Multiplicacao da primeira matriz pela sua transposta:\n");
    imprimeMatriz(matrizMultiplicada);

    printf("\n");
    printf("Segunda Matriz: \n");
    imprimeMatriz(matrizSegunda);

    printf("\n");
    printf("Segunda Transposta: \n");
    imprimeMatriz(matrizTransposta2);

    printf("\n");
    printf("Multiplicacao da segunda matriz pela sua transposta:\n");
    imprimeMatriz(matrizMultiplicada2);

    //teste de liberação
    destroiMatriz(matrizInicial);
    destroiMatriz(matrizSegunda);
    destroiMatriz(matrizTransposta);
    destroiMatriz(matrizTransposta2);
    destroiMatriz(matrizMultiplicada);
    destroiMatriz(matrizMultiplicada2);

    return 0;
}