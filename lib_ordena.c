#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib_ordena.h"

void imprime_vetor (int v[], int tam) {
    int i;

    for (i=0; i<tam-1; i++)
        printf("%d ",v[i]);
    printf("%d\n",v[tam-1]);
}

void troca (int v[], int i, int j) {
    int aux;

    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void gera_vetor_em_ordem (int v[], int tam) {
    int i;

    for (i=0; i<tam; i++)
        v[i] = i;
}

void gera_vetor_randomico (int v[], int tam) {
    int i;

    srand(time(0));
    for (i=0; i<tam; i++)
        v[i] = (unsigned int) (rand() % (tam*3)); /* pode modificar se quiser */
}

void embaralha_vetor (int v[], int tam) {
    int k, i, j, max_trocas;

    max_trocas = (unsigned int) (rand() % tam) + tam; /* pode modificar */
    for (k=0; k<max_trocas; k++) {
        i = (unsigned int) (rand() % tam);
        j = (unsigned int) (rand() % tam);
        troca (v,i,j);
    }
}

void inserctionsort (int v[], int ini, int fim) {
    printf("implementar insertionsort\n");
}

/* particiona com pivo no inicio */
int particiona_inicio (int v[], int ini, int fim)
{
	int pivo, i, j;

	pivo = v[ini];
	i = ini+1;

	for ( j=i; j <= fim; j++ )
	{
		if ( v[j] < pivo ) 
		{
			troca (v, i, j);
			i++;
		}
	}

	troca (v, ini, i-1);

	return i-1;
}

void quicksort_inicio (int v[], int ini, int fim)
{
	int pivo;		

	if (ini < fim)
	{
		pivo = particiona_inicio (v, ini, fim);
		quicksort_inicio (v, ini, pivo-1);
		quicksort_inicio (v, pivo+1, fim);
	}
}

/* particiona com pivo no fim */
int particiona_fim (int v[], int ini, int fim)
{
	int pivo, i, j;

	pivo = v[fim];
	i = ini;

	for ( j=i; j < fim; j++ )
	{
		if ( v[j] < pivo ) 
		{
			troca (v, i, j);
			i++;
		}
	}

	troca (v, fim, i);

	return i;
}

void quicksort_fim (int v[], int ini, int fim)
{
	int pivo;		

	if (ini < fim)
	{
		pivo = particiona_fim (v, ini, fim);
		quicksort_fim (v, ini, pivo-1);
		quicksort_fim (v, pivo+1, fim);
	}
}

void intercala (int v[], int ini, int meio, int fim) {
    printf("implementar intercala\n");
}

void mergesort (int v[], int ini, int fim) {
    printf("implementar mergesort\n");
}

