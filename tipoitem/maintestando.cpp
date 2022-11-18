#include "Quick_Mediana.hpp"
#include "Quick_Selecao.hpp"
#include "Quick_Recursivo.hpp"
#include "Quick_nao_Recursivo.hpp"
// #include "HeapSort.hpp"
// #include "MergeSort.hpp"
#include <getopt.h>
#include <string.h>

char casoteste[2];
FILE *input, *output;
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
    
  int *vetor_principal = (int*) malloc(1*sizeof(int));


  parse_args(argc,argv);
  
  /* Asserção para arquivo não encontrado */
  if(input == NULL){
    cout << "Arquivo não encontrado \n";
    return 0;
  }
  /* Asserção para o numero do algortimo não encontrado */


  fscanf(input, "%d", &n);
  
  int indice_vetores[n];

  for (int i = 0; i < n; i++){
    fscanf(input, "%d", &indice_vetores[i]);
  }

  for (int i = 0; i < n; i++)
  {

    // cout << "Vetor com " << indice_vetores[i] << " posições\n";
    
    vetor_principal = (int *) realloc(vetor_principal, indice_vetores[i]*sizeof(int));

    GeraVetores(vetor_principal, indice_vetores[i], seed);

    /* Os algoritmos entraram aqui */
    if (k == 1)
    {
      cout << "Quick Sort Mediana\n";
      cout << "Mediana: " << medianak << "\n";
      QuicksortMediana(vetor_principal, 0, n, medianak);
    }
      
    printvetor(vetor_principal, indice_vetores[i]);
    cout << endl;
    

  }

  return 0;
}
