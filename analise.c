#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib_ordena.h"

#define LIMITE 1000000

double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {
    int i, tam;
    double ini, fim, soma_tempo;

	/* Mude aqui o numero de iterações e nome do algoritmo */
	int MAX_IT = 100;
	char *algoritmo = "mergesort_basico (R)";

	for ( tam=10; tam <= LIMITE; tam*=10 ) 
	{
		int *v;
		v = (int*) malloc (tam * sizeof(int)); 

		/* Mude aqui o tipo de entrada */
		gera_vetor_randomico (v,tam);

		soma_tempo = 0;
		for (i=0; i<MAX_IT; i++) 
		{
			/*imprime_vetor (v, tam);*/

			ini = timestamp();
			/* Mude aqui o algoritmo usado */
			mergesort_basico (v,0,tam-1); 
			fim = timestamp();

			soma_tempo += (fim-ini);

			/*imprime_vetor (v, tam);*/
			embaralha_vetor (v,tam);
		}
		
		printf("Algoritmo: %25s | Iterações: %5d | Tamanho: %10d | Tempo: %15f milisegundos.\n", algoritmo, MAX_IT, tam, soma_tempo/MAX_IT);

		free (v);

	}
    return 0;
}
