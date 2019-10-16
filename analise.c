#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib_ordena.h"

double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {
    int i, tam;
    double ini, fim, soma_tempo;

	/* Mude aqui o numero de iterações, tamanho maximo e nome do algoritmo */
	int MAX_IT = 100;
	int TAM_MAX = 1000000;
	char *algoritmo = "mergesort_melhorado_h (O)";

	for ( tam=10; tam <= TAM_MAX; tam*=10 ) 
	{
		int *v;
		v = (int*) malloc (tam * sizeof(int)); 

		/* Mude aqui o tipo de entrada */
		gera_vetor_em_ordem (v,tam);

		soma_tempo = 0;
		for (i=0; i<MAX_IT; i++) 
		{
			ini = timestamp();
			/* Mude aqui o algoritmo usado */
			mergesort_melhorado (v,0,tam-1); 
			fim = timestamp();

			soma_tempo += (fim-ini);

			/*embaralha_vetor (v,tam);*/
		}
		
		printf("Algoritmo: %25s | Iterações: %7d | Tamanho: %10d | Tempo: %15f milisegundos.\n", algoritmo, MAX_IT, tam, soma_tempo/MAX_IT);

		free (v);

	}

	printf ("\n");

    return 0;
}
