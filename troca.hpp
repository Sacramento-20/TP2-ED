#ifndef TROCA_H
#define TROCA_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include "memlog.h" 
#include "msgassert.h" 

using namespace std;

struct Registros
{
  int chave;
  string caracteres[15];
  float numeros[10];

};

float Criafloat(){
  float retorno;

  retorno = rand();
  return retorno;
}

string CriaStrings(){
  string retorno;

  retorno.reserve(200);

  for (int i = 0; i < 200; i++)
  {
    retorno += 'a' + (char)(rand()%26);
  }
  return retorno;
}

void GeraRegistros(Registros *vetor, int tamanho, int semente)
{
  srand(semente);
  
  for (int i = 0; i < tamanho; i++) {
    vetor[i].chave = rand() % tamanho;

    for (int j = 0; j < 15; j++)
    {
      vetor[i].caracteres[j] = CriaStrings();
    }
    for (int k = 0; k < 10; k++)
    {
      vetor[i].numeros[k] = Criafloat();
    } 
  }
}

//função auxiliar para realizar as trocas de elementos
void troca(Registros *A, int i, int j)
{
  Registros temp = A[i];
  A[i] = A[j];
  ESCREVEMEMLOG((long int)(&(A[i])), sizeof(double),0);
  A[j] = temp;
  ESCREVEMEMLOG((long int)(&(A[j])), sizeof(double),0);
}

void printvetor(Registros vetor[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
  {
    LEMEMLOG((long int)(&(vetor[i].chave)), sizeof(double),0);
    // cout << vetor[i].chave << " ";
  }
}




#endif