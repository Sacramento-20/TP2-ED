#ifndef ITERATIVO_H
#define ITERATIVO_H
#include <iostream>
#include "troca.hpp"


using namespace std;

int n_trocasIt = 0; 

/* Função Partição*/
int Particaonaorecursivo(Registros *vetor, int inicio, int final)
{
    int x = vetor[final].chave;
    int i = (inicio - 1);
 
    for (int j = inicio; j <= final - 1; j++) {
        if (vetor[j].chave <= x) {
            i++;   
            troca(vetor, i, j);
            n_trocasIt++;
        }
    }
    troca(vetor, i+1, final);
    n_trocasIt++;
    return (i + 1);
}
 

void OrdenaIterativo(Registros *vetor, int inicio, int final)
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

void QuickSortIterativo(Registros *vetor, int inicio, int fim, int *n_troca)
{
    OrdenaIterativo(vetor, inicio, fim-1);
    *n_troca = n_trocasIt;
    n_trocasIt = 0;
}


 
#endif