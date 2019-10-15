#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib_ordena.h"

#define MAX_IT 5 
#define TAM_VETOR 50

double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {
    int i, tam;
    double ini, fim, soma_tempo;

    tam = TAM_VETOR;
    int v[tam]; 

    gera_vetor_randomico (v,tam);

    soma_tempo = 0;
    for (i=0; i<MAX_IT; i++) 
	{
		printf ("\n");
		imprime_vetor (v, tam);

        ini = timestamp();
        mergesort_melhorado (v,0,tam-1); 
        fim = timestamp();

        soma_tempo += (fim-ini);

		imprime_vetor (v, tam);
        embaralha_vetor (v,tam);
	}

    printf("\nTempo medio do quicksort: %f segundos.\n", soma_tempo/MAX_IT);

    return 0;
}
