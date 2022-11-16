#ifndef TROCA_H
#define TROCA_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void GeraVetores(int *vetorQuick, int *vetorHeap, int *vetorMerge, int tamanho, int semente)
{
  // semente para entrada aleatória
  // srand(time(NULL));
  srand(semente);

  // gera valores aleatórios
  for (int i = 0; i < tamanho; i++) {
    vetorQuick[i] = rand() % tamanho;
    vetorHeap[i] = rand() % tamanho;
    vetorMerge[i] = rand() % tamanho;
  }
}

//função auxiliar para realizar as trocas de elementos
void troca(int *A, int i, int j)
{
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

void printvetor(int vetor[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
    cout << vetor[i] << " ";
}




#endif