#include "Quick_Mediana.hpp"
#include "Quick_Selecao.hpp"
#include "Quick_Recursivo.hpp"
#include "Quick_nao_Recursivo.hpp"
#include "HeapSort.hpp"
#include "MergeSort.hpp"

#include <getopt.h>
#include <string.h>

char casoteste[2];
FILE *input, *output;
int k;
int seed;
int algoritmo, medianak, selecaom;
// int k = 5;
// int m = 100;
int n;


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
    parse_args(argc,argv);
    fscanf(input, "%d", &n);
    
    int vetor[n];
    int vetorMerge[n];
    int vetorHeap[n];

    GeraVetores(vetor, vetorHeap, vetorMerge, n, seed);

    cout << "Valor da seed: " << seed << endl;
    cout << "Valor da mediana: " << medianak << endl;
    cout << "Valor da selecao: " << selecaom << endl;
    cout << "Versão do algoritmo: " << k << endl;
    cout << "Tamanho do vetor: " << n << endl;
    
    cout << endl;

    if (k == 1)
    {
        // cout << "Quick Recursivo" << endl;
        QuickSortRecursivo(vetor, n);
        /*Função que escreve as estatisticas na saida*/
        fprintf(output, "Quick Sort Recursivo\n");
        fprintf(output, "Valor da seed: %d\nTamanho do vetor: %d\n",  seed,n);

    }
    else if (k == 2)
    {
        cout << "Quick Mediana " << medianak << endl;
        QuicksortMediana(vetor, 0, n, medianak);
        /*Função que escreve as estatisticas na saida*/
        fprintf(output, "Quick Sort Mediana\n");
        fprintf(output, "Valor da seed: %d\nTamanho do vetor: %d\nValor da mediana: %d\n",  seed,n, medianak);
    }
    else if (k == 3)
    {
        cout << "Quick Selecao "<< selecaom << endl;
        QuicksortSelecao(vetor, 0, n, selecaom);
        /*Função que escreve as estatisticas na saida*/
        fprintf(output, "Quick Sort Selecao\n");
        fprintf(output, "Valor da seed: %d\nTamanho do vetor: %d\nValor da selecao: %d\n",  seed,n,selecaom);
        
    }
    else if (k == 4)
    {
        cout << "Quick Iterativo" << endl;
        QuickSortIterativo(vetor, 0, n);
        /*Função que escreve as estatisticas na saida*/
        fprintf(output, "Quick Sort Iterativo\n");
        fprintf(output, "Valor da seed: %d\nTamanho do vetor: %d\n",  seed,n);
        
    }
    else if (k == 5)
    {
        printf("olá");
    }

    /*=======================================================================*/
    /*Heapsort e MergSort*/
    /*O Quick com seleção é mais eficiente que o outros, logo ele será comparado com o merge e o heap*/

    heapsort(vetorHeap, n);
    mergeSort(vetorMerge,0,n);

    cout << "QuickSort" << endl;
    printvetor(vetor, n);
    cout << endl;

    cout << "HeapSort" << endl;
    printvetor(vetorHeap, n);
    cout << endl;

    cout << "MergeSort" << endl;
    printvetor(vetorMerge, n);
    cout << endl;


    return 0;
}
