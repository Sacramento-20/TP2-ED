#ifndef RECURSIVO_H
#define RECURSIVO_H
#include <iostream>

using namespace std;

void ParticaoRecursivo(int Esq, int Dir, int *i, int *j, int *vetor)
{
  int x, w;

  *i = Esq;
  *j = Dir;

  x = vetor[(*i + *j) / 2];

  do
  {
    while (x > vetor[*i])
    {
      (*i)++;
    }
    while (x < vetor[*j])
    {
      (*j)--;
    }

    if (*i <= *j)
    {
      w = vetor[*i];
      
      vetor[*i] = vetor[*j];
      vetor[*j] = w;

      (*i)++;
      (*j)--;
    }

  } while (*i <= *j);

}

void OrdenaRecursivo(int Esq, int Dir, int *vetor)
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

void QuickSortRecursivo(int *vetor, int n)
{
  OrdenaRecursivo(0, n - 1, vetor);
}

#endif