#ifndef MEDIANA_H
#define MEDIANA_H

#include <iostream>
#include "troca.hpp"

using namespace std;

int n_elementos_vetor = 0;
int valor_mediana = 0;
int n_trocasMed;

/*==============================================================================================*/
/* Funções auxiliares para obtenção do valor da mediana */
void Ordenar_vetor(Registros *vetor, int n_elementos)
{
  Registros aux;

  for (int i = 0; i < n_elementos; i++)
  {
    for (int j = i; j < n_elementos; j++)
    {
      if (vetor[i].chave >= vetor[j].chave)
      {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  } 
}

int SelecionaMediana(Registros *vetor_total, int n_elementos, int k)
{
  
  srand(time(NULL));

  int indice;
  int vetor_indices[k];
  Registros vetor_amostras[k];


  /* Colocar todos os indices como -1 para certificar que todas as posiçoes são validas*/
  for (int i = 0; i < k; i++)
  {
    vetor_indices[i] = -1;
  }

  int contador = 0;
  while(vetor_indices[contador] == -1)
  {
    indice = rand() % n_elementos;

    for (int i = 0; i < k; i++){
      if (indice == vetor_indices[i])
      {
        break;
      }
      else if(indice != vetor_indices[i] && vetor_indices[i] == -1){
        vetor_indices[i] = indice;
        break;
      }
    }

    if(vetor_indices[contador] != -1)
    {
      contador++;
    }

  }

  for (int i = 0; i < k; i++)
  {
    vetor_amostras[i].chave = vetor_total[vetor_indices[i]].chave;
  }

  
  Ordenar_vetor(vetor_amostras, k);
  
  int meio = (0+k) / 2;
  return vetor_amostras[meio].chave;

}

/*==============================================================================================*/
/* Algoritmo Quicksort Mediana */




int ParticaoMediana(Registros *A, int inicio, int fim) {

    int meio = SelecionaMediana(A, n_elementos_vetor, valor_mediana);
    int a = A[inicio].chave;
    int b = A[meio].chave;
    int c = A[fim].chave;
    int medianaIndice; //índice da mediana
    
    //A sequência de if...else a seguir verifica qual é a mediana
    if (a < b) {
        if (b < c) {
            //a < b && b < c
            medianaIndice = meio;
        } else {
            if (a < c) {
                //a < c && c <= b
                medianaIndice = fim;
            } else {
                //c <= a && a < b
                medianaIndice = inicio;
            }
        }
    } else {
        if (c < b) {
            //c < b && b <= a
            medianaIndice = meio;
        } else {
            if (c < a) {
                //b <= c && c < a
                medianaIndice = fim;
            } else {
                //b <= a && a <= c
                medianaIndice = inicio;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
    troca(A, medianaIndice, fim);
    n_trocasMed++;
        
    //*******************ALGORITMO DE PARTIÇÃO DE CORMEN*********************
    //o pivo é o elemento final
    int pivo = A[fim].chave;
    int i = inicio - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.         
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (A[j].chave <= pivo) {
            i = i + 1;
            troca(A, i, j);
            n_trocasMed++;
        }
    }
    //coloca o pivô na posição de ordenação
    troca(A, i + 1, fim);
    n_trocasMed++;
    return i + 1; //retorna a posição do pivô
}

//Quicksort mediana de três
void OrdenaMediana(Registros A[], int inicio, int fim) {
    if (inicio <= fim) {
        //realiza a partição
        int pivo = ParticaoMediana(A, inicio, fim);
        //ordena a partição esquerdafim
        OrdenaMediana(A, inicio, pivo - 1);
        //ordena a partição direita
        OrdenaMediana(A, pivo + 1, fim);
    }
}

void QuicksortMediana(Registros *A, int inicio, int fim, int mediana, int *n_troca)
{
    n_elementos_vetor = fim;
    valor_mediana = mediana;
    OrdenaMediana(A, 0, n_elementos_vetor - 1);
    *n_troca = n_trocasMed;
    n_trocasMed = 0;
}

#endif