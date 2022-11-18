#ifndef RECURSIVO_H
#define RECURSIVO_H
#include <iostream>
#include "troca.hpp"
#include "memlog.h" 
#include "msgassert.h" 

using namespace std;

int n_trocasRec;

void ParticaoRecursivo(int Esq, int Dir, int *i, int *j, Registros *vetor)
{
  Registros x, w;

  *i = Esq;
  *j = Dir;

  x = vetor[(*i + *j) / 2];

  do
  {
    while (x.chave > vetor[*i].chave)
    {
      (*i)++;
    }
    while (x.chave < vetor[*j].chave)
    {
      (*j)--;
    }

    if (*i <= *j)
    {
      w = vetor[*i];
      ESCREVEMEMLOG((long int)(&(w)), sizeof(double),0);
      vetor[*i] = vetor[*j];
      ESCREVEMEMLOG((long int)(&(vetor[*i])), sizeof(double),0);
      vetor[*j] = w;
      ESCREVEMEMLOG((long int)(&(vetor[*j])), sizeof(double),0);
      n_trocasRec++;

      (*i)++;
      (*j)--;
    }

  } while (*i <= *j);

}

void OrdenaRecursivo(int Esq, int Dir, Registros *vetor)
{
  int i, j;

  ParticaoRecursivo(Esq, Dir, &i, &j, vetor);
  if (Esq < j)
  {
    OrdenaRecursivo(Esq, j, vetor);
  }
  if (i < Dir)
  {
    OrdenaRecursivo(i, Dir, vetor);
  }

}

void QuickSortRecursivo(Registros *vetor, int n, int *n_troca)
{
  
  OrdenaRecursivo(0, n - 1, vetor);
  *n_troca = n_trocasRec;
  n_trocasRec = 0;
}

#endif