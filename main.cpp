#include "Quick_Recursivo.hpp"
#include "Quick_Mediana.hpp"
#include "Quick_Selecao.hpp"
#include "Quick_nao_Recursivo.hpp"
#include <getopt.h>
#include <string.h>
#include "troca.hpp"
#include <cstdlib>
#include <ctime>

// #include "HeapSort.hpp"
// #include "MergeSort.hpp"

char casoteste[2];
FILE *input, *output, *memlog;
int k;
int seed = 0;
int algoritmo, medianak, selecaom;
int n = 0;


void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty, regmem, lognome
{
    // variaveis externas do getopt
    extern char * optarg;
    extern int optind;

    // variavel auxiliar
    int c;
    // smtc:

    while ((c = getopt(argc, argv, "i:o:v:s:k:m:i:")) != EOF)
       switch(c) {
          case 'i':
            input = fopen(optarg, "r");
            break;

          case 'o':
            output = fopen(optarg, "wb");
            break;

          case 'v':
            strcpy(casoteste,optarg);
            k = atoi(casoteste);
            
            break;

          case 'm':
            selecaom = atoi(optarg);
            break;
          
          case 'k':
            medianak = atoi(optarg);
            break;

          case 's':   
            seed = atoi(optarg);
            break;
         
         default:
          exit(1);

       }
}

/*Criar o analisamem, */

int main(int argc, char *argv[])
{
  int numero_trocas = 0;
  char nome_arquivo[50] = "log.out";
  memlog = fopen(nome_arquivo, "wb");
  
  clock_t begin, end;
  double t1 = 0.0;
  
  Registros *vetor_principal = (Registros*) malloc(1*sizeof(Registros)); 

  parse_args(argc,argv);

  
  /* Asserção para arquivo não encontrado */
  if(input == NULL){
    cout << "Arquivo não encontrado \n";
    return 0;
  }
  
  /* Asserção para o numero do algortimo não encontrado */
  if (k <= 0 || k >= 6 )
  {
    cout << "Algoritmo não encontrado \n";
    return 0;
  }

  iniciaMemLog(nome_arquivo);

  fscanf(input, "%d", &n);
  
  int indice_vetores[n];

  for (int i = 0; i < n; i++){
    fscanf(input, "%d", &indice_vetores[i]);
  }

  for (int i = 0; i < n; i++)
  {
    
    vetor_principal = (Registros *) realloc(vetor_principal, indice_vetores[i]*sizeof(Registros));
    numero_trocas = 0;

    GeraRegistros(vetor_principal, indice_vetores[i], seed);

    /* Os algoritmos entraram aqui */
    if (k == 1)
    {
      cout << "Quick Sort Recursivo\n";
      begin = clock();
      QuickSortRecursivo(vetor_principal, indice_vetores[i], &numero_trocas);
      end = clock();
      t1 += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    else if (k == 2)
    {
      cout << "Quick Sort Mediana\n";
      begin = clock();
      QuicksortMediana(vetor_principal, 0, indice_vetores[i], medianak, &numero_trocas);
      end = clock();
      t1 += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    else if (k == 3)
    {
      
      cout << "Quick Sort Seleção\n";
      QuicksortSelecao(vetor_principal, 0, indice_vetores[i], selecaom, &numero_trocas);
    }
    else if (k == 4)
    {
      cout << "Quick Sort Iterativo\n";
      QuickSortIterativo(vetor_principal, 0, indice_vetores[i], &numero_trocas);
    }
      
    printvetor(vetor_principal, indice_vetores[i]);
    cout << numero_trocas << endl;
    cout << endl;
    
  }

  cout << "Media de tempo: " << t1/n << endl;
  free(vetor_principal);

  return finalizaMemLog();
}
