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

void insertionsort (int v[], int ini, int fim) 
{
	int i, j, chave;
	int tam = fim - ini + 1;
	
	for ( i=1; i<tam; i++ )
	{		
		chave = v[i];
		j = i-1;

		while ( j >= 0 && chave < v[j] )
		{
			v[j+1] = v[j];
			j--;
		}

		v[j+1] = chave;
	}
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

/* particiona com pivo da mediana de 3 */
int particiona_mediana3 (int v[], int ini, int fim, int pivo)
{
	int i, j;

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

/* calcula a mediana entre v[ini], v[meio] e v[fim] */
int mediana3 (int v[], int ini, int fim)
{
	int meio = ini + (fim-ini)/2;

	if (v[ini] < v[meio])
	{
		if (v[ini] >= v[fim])
			return v[ini];
		else if (v[meio] < v[fim])
			return v[meio];
	}

	else
	{
		if (v[ini] < v[fim])
			return v[ini];
		else if (v[meio] >= v[fim])
			return v[meio];
	}
	return v[fim];
}

/* calcula a mediana de 3 entre v[ini], v[meio] e v[fim] usando vetor e insertion */
int mediana3_vetor (int v[], int ini, int fim)
{
	int meio = ini + (fim-ini)/2;

	int m[3] = {v[ini], v[meio], v[fim]};

	insertionsort (m, 0, 2);

	return m[1];	
}

void quicksort_mediana3 (int v[], int ini, int fim)
{
	if (ini < fim)
	{
		int pivo = mediana3 (v, ini, fim);
		int pivo_i = particiona_mediana3 (v, ini, fim, pivo);
		quicksort_mediana3 (v, ini, pivo_i);
		quicksort_mediana3 (v, pivo_i+1, fim);
	}
}

/* particiona com pivo da mediana de 3 */
int particiona_mediana5 (int v[], int ini, int fim, int pivo)
{
	int i, j;

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

/* calcula a mediana de 3 entre v[ini], v[meio] e v[fim] usando vetor e insertion */
int mediana5_vetor (int v[], int ini, int fim)
{
	int meio = ini + (fim-ini)/2;
	int esq = ini + (meio-ini)/2;
	int dir = meio + (fim-meio)/2;

	int m[5] = {v[ini], v[esq], v[meio], v[dir], v[fim]};

	insertionsort (m, 0, 4);

	return m[2];	
}

void quicksort_mediana5 (int v[], int ini, int fim)
{
	if (ini < fim)
	{
		int pivo = mediana5_vetor (v, ini, fim);
		int pivo_i = particiona_mediana5 (v, ini, fim, pivo);
		quicksort_mediana5 (v, ini, pivo_i);
		quicksort_mediana5 (v, pivo_i+1, fim);
	}
}

void copia_vetor (int v[], int aux[], int ini, int fim)
{
	int i, tam = fim-ini+1;

	for ( i=0; i < tam; i++ )
	{
		aux[i] = v[ini];
		ini++;
	}
}

void copia_vetor2 (int v[], int aux[], int ini, int fim)
{
	int i, tam = fim-ini+1;

	for ( i=0; i < tam; i++ )
	{
		v[ini] = aux[i];
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
	int tam_aux = fim-ini+1;
	int aux[tam_aux];


	int i = ini;
	int j = meio +1;
	int k = 0;

	/* intercala entre as duas seções do vetor aux */
	while ( (i <= meio) && (j <= fim) )
	{
		if ( v[i] < v[j] )
		{
			aux[k] = v[i];
			i++;
		}

		else
		{
			aux[k] = v[j];
			j++;
		}
	
		k++;
	}		

	/* copia o restante do vetor que ainda houver elementos */
	while (i <= meio)
	{
		aux[k] = v[i];
		i++;
		k++;
	}

	while (j <= fim)
	{
		aux[k] = v[j];
		j++;
		k++;
	}
	
	copia_vetor2 (v, aux, ini, fim);
}

/* testa se duas particoes do merge já estao ordenadas */
int esta_ordenado (int v[], int meio)
{
	if ( v[meio] < v[meio+1] )
		return 1;

	return 0;
}

/* mergesort com melhorias */
void mergesort_melhorado (int v[], int ini, int fim) 
{
	/* evita overflow */
	int meio = ini + (fim - ini)/2;

	if (ini < fim)
	{
		mergesort_melhorado (v, ini, meio);
		mergesort_melhorado (v, meio+1, fim);
		if (!esta_ordenado (v, meio))
			intercala_melhorado (v, ini, meio, fim);
	}
}
