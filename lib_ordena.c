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

/* função interna da biblioteca */
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
	int pivo_i;		

	if (ini < fim)
	{
		pivo_i = particiona_inicio (v, ini, fim);
		quicksort_inicio (v, ini, pivo_i-1);
		quicksort_inicio (v, pivo_i+1, fim);
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
	int pivo_i;		

	if (ini < fim)
	{
		pivo_i = particiona_fim (v, ini, fim);
		quicksort_fim (v, ini, pivo_i-1);
		quicksort_fim (v, pivo_i+1, fim);
	}
}

/* particiona com pivo no meio */
int particiona_meio (int v[], int ini, int fim)
{
	int pivo, i, j;

	/* evita overflow */
	pivo = v[ini + (fim-ini)/2];
	i = ini-1;
	j = fim+1;

	while (1)
	{
		do 
			i++;
		while ( v[i] < pivo );

		do 
			j--;
		while ( v[j] > pivo );

		if ( i >= j )
			return j;

		troca (v, i, j);	
	}
}

void quicksort_meio (int v[], int ini, int fim)
{
	int pivo_i;		

	if (ini < fim)
	{
		pivo_i = particiona_meio (v, ini, fim);
		quicksort_meio (v, ini, pivo_i);
		quicksort_meio (v, pivo_i+1, fim);
	}
}

/* função interna da biblioteca */
void copia_vetor (int v[], int aux[], int ini, int fim)
{
	int i, tam = fim-ini+1;

	for ( i=0; i < tam; i++ )
	{
		aux[i] = v[ini];
		ini++;
	}
}

/* intercala sem melhorias */
void intercala_basico (int v[], int ini, int meio, int fim) 
{
	int tam_esq = meio - ini + 1;
	int tam_dir = fim - meio;
	int esquerdo[tam_esq], direito[tam_dir];

	copia_vetor (v, esquerdo, ini, meio);
	copia_vetor (v, direito, meio+1, fim);

	int i = 0;
	int j = 0;

	/* intercala entre os dois vetores auxiliares */
	while ( (i < tam_esq) && (j < tam_dir) )
	{
		if ( esquerdo[i] < direito[j] )
		{
			v[ini] = esquerdo[i];
			i++;
		}

		else
		{
			v[ini] = direito[j];
			j++;
		}
	
		ini++;
	}		

	/* copia o restante do vetor que ainda houver elementos */
	while (i < tam_esq)
	{
		v[ini] = esquerdo[i];
		i++;
		ini++;
	}

	while (j < tam_dir)
	{
		v[ini] = direito[j];
		j++;
		ini++;
	}
}

/* mergesort sem melhorias */
void mergesort_basico (int v[], int ini, int fim) 
{
	/* evita overflow */
	int meio = ini + (fim - ini)/2;

	if ( ini < fim )
	{
		mergesort_basico (v, ini, meio);
		mergesort_basico (v, meio+1, fim);
		intercala_basico (v, ini, meio, fim);
	}
}

/* intercala com melhorias */
void intercala_melhorado (int v[], int ini, int meio, int fim) 
{
	/* implementar passar o vetor por parametro */
	int tam_esq = meio - ini + 1;
	int tam_dir = fim - meio;
	int esquerdo[tam_esq], direito[tam_dir];

	copia_vetor (v, esquerdo, ini, meio);
	copia_vetor (v, direito, meio+1, fim);

	int i = 0;
	int j = 0;

	/* intercala entre os dois vetores auxiliares */
	while ( (i < tam_esq) && (j < tam_dir) )
	{
		if ( esquerdo[i] < direito[j] )
		{
			v[ini] = esquerdo[i];
			i++;
		}

		else
		{
			v[ini] = direito[j];
			j++;
		}
	
		ini++;
	}		

	/* copia o restante do vetor que ainda houver elementos */
	while (i < tam_esq)
	{
		v[ini] = esquerdo[i];
		i++;
		ini++;
	}

	while (j < tam_dir)
	{
		v[ini] = direito[j];
		j++;
		ini++;
	}
}

/* função interna da biblioteca */
/* testa se duas particoes do merge já estao ordenadas */
int esta_ordenado (int v[], int meio)
{
	if ( v[meio] < v[meio+1] )
		return 1;

	return 0;
}

/* função interna da biblioteca */
/* testa se duas particoes do merge estão ordenadas invertidas */
int esta_invertido (int v[], int ini, int fim)
{
	/*if ( v[ini] > v[fim] )
		return 1; falta inverter */

	return 0;
}

/* mergesort com melhorias */
void mergesort_melhorado (int v[], int ini, int fim) 
{
	/* evita overflow */
	int meio = ini + (fim - ini)/2;

	if (ini < fim)
	{
		if (esta_ordenado(v, meio))
			printf ("ta ordenado lek\n");

		else if (esta_invertido(v, ini, fim))
			printf ("ta ordenado invertido lek\n");
			/* falta inverter */

		else 
		{
			int aux[fim-ini+1];

			copia_vetor (v, aux, ini, fim);
			
			mergesort_basico (v, ini, meio);
			mergesort_basico (aux, meio+1, fim);
			intercala_basico (v, ini, meio, fim);
		}
	}
}
