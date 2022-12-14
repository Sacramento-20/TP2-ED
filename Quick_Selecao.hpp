#ifndef SELECAO_H
#define SELECAO_H
#include <iostream>
#include "troca.hpp"

using namespace std;
 
// Número total de elementos a serem ordenados
 
int particao;
int n_trocasSel = 0;

// Função para realizar a ordenação por inserção em `vetor[]`
void insertionSort(Registros *vetor, int low, int n)
{
    // Começa a partir do segundo elemento (o elemento no índice 0
    // já está ordenado)
    for (int i = low + 1; i <= n; i++)
    {
        int value = vetor[i].chave;
        int j = i;
 
        // encontra o índice `j` dentro do subconjunto ordenado `vetor[0…i-1]`
        // onde o elemento `vetor[i]` pertence
        while (j > low && vetor[j - 1].chave > value)
        {
            vetor[j] = vetor[j - 1];
            n_trocasSel++;
            j--;
        }
 
        // note que o subvetoray `vetor[j…i-1]` é deslocado para
        // a direita por uma posição, ou seja, `vetor[j+1…i]`
 
        vetor[j].chave = value;
    }
}
 
/* Função Partição*/
int ParticaoSelecao(Registros *vetor, int inicio, int final)
{
    int x = vetor[final].chave;
    int i = (inicio - 1);
 
    for (int j = inicio; j <= final - 1; j++) {
        if (vetor[j].chave <= x) {
            i++;
            troca(vetor, i, j);
            n_trocasSel++;
            // troca(&vetor[i], &vetor[j]);
        }
    }
    troca(vetor, i + 1,final);
    n_trocasSel++;
    // troca(&vetor[i + 1], &vetor[final]);
    // trocas++;
    return (i + 1);
}

void OrdenaSelecao(Registros*vetor, int low, int high)
{
    while (low < high)
    {
        /*Colocar uma variavel que irá alternar entre 10 e 100*/
        // muda para a ordenação por inserção se o tamanho for 10 ou menor
        if (high - low < particao)
        {
            insertionSort(vetor, low, high);
            break;
        }
        else {
            int pivot = ParticaoSelecao(vetor, low, high);
 
            // otimizações de chamada de cauda – recorrente no subvetoray menor
            if (pivot - low < high - pivot)
            {
                OrdenaSelecao(vetor, low, pivot - 1);
                low = pivot + 1;
            }
            else {
                OrdenaSelecao(vetor, pivot + 1, high);
                high = pivot - 1;
            }
        }
    }
}

void QuicksortSelecao(Registros *vetor, int inicio, int fim, int ordenador, int *n_troca)
{
    particao = ordenador;
    OrdenaSelecao(vetor, 0, fim - 1);
    *n_troca = n_trocasSel;
    n_trocasSel = 0;
}
 
#endif