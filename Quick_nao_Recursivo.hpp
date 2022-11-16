#ifndef ITERATIVO_H
#define ITERATIVO_H
#include <iostream>
#include "troca.hpp"


using namespace std;
 
/* Função Partição*/
int Particaonaorecursivo(int *vetor, int inicio, int final)
{
    int x = vetor[final];
    int i = (inicio - 1);
 
    for (int j = inicio; j <= final - 1; j++) {
        if (vetor[j] <= x) {
            i++;
            // troca(&vetor[i], &vetor[j]);    
            troca(vetor, i, j);
        }
    }
    troca(vetor, i+1, final);
    // troca(&vetor[i + 1], &vetor[final]);
    return (i + 1);
}
 

void OrdenaIterativo(int *vetor, int inicio, int final)
{
    
    int pilha[final - inicio + 1];
 
    int topo = -1;
 
    pilha[++topo] = inicio;
    pilha[++topo] = final;
 
    while (topo >= 0) {

        final = pilha[topo--];
        inicio = pilha[topo--];
 
        int pivo = Particaonaorecursivo(vetor, inicio, final);
 
        if (pivo - 1 > inicio) {
            pilha[++topo] = inicio;
            pilha[++topo] = pivo - 1;
            // trocas++;
        }
        if (pivo + 1 < final) {
            pilha[++topo] = pivo + 1;
            pilha[++topo] = final;
            // trocas++;
        }
    }
}

void QuickSortIterativo(int *vetor, int inicio, int fim)
{
    OrdenaIterativo(vetor, inicio, fim-1);
}


 
#endif