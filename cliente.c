#include "matriz.h"
#include <stdio.h>
int main(){
    int nlinhas=2, ncolunas=3;
    //teste de inicialização
    Matriz* matrizInicial = inicializaMatriz(nlinhas, ncolunas);
    //teste de impressão
    imprimeMatriz(matrizInicial);

    //segunda matriz
    Matriz* segundaMatriz = inicializaMatriz(4, 3);

    int k=0;
    //teste de modificação
    for(int i=0; i<nlinhas; i++){
        for(int j=0; j<ncolunas; j++){
            modificaElemento(matrizInicial, i, j, k);
            k++;
        }
    }
    printf("\n");
    imprimeMatriz(matrizInicial);

    //preenche segunda matriz
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            modificaElemento(segundaMatriz, i, j, 3*i);
        }
    }

    //teste de transposta
    Matriz* matrizTransposta = transposta(matrizInicial);
    printf("\n");
    imprimeMatriz(matrizTransposta);

    //transposta da segunda matriz
    Matriz* matrizTransposta2 = transposta(segundaMatriz);
    
    
    //teste de multiplicação
    Matriz* matrizMultiplicada = multiplicacao(matrizInicial, matrizTransposta);
    printf("\n");
    imprimeMatriz(matrizMultiplicada);

    //multiplicação da segunda pela transposta
    Matriz* matrizMultiplicada2 = multiplicacao(segundaMatriz, matrizTransposta2);
    printf("\n");
    imprimeMatriz(matrizTransposta2);
    printf("\n");
    imprimeMatriz(matrizMultiplicada2);
    //teste de liberação
    destroiMatriz(matrizInicial);
    destroiMatriz(segundaMatriz);
    destroiMatriz(matrizTransposta);
    destroiMatriz(matrizTransposta2);
    destroiMatriz(matrizMultiplicada);
    destroiMatriz(matrizMultiplicada2);

    return 0;
}