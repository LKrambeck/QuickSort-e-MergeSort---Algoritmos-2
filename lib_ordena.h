#define MAX 100

void gera_vetor_randomico     (int v[], int tam);
void gera_vetor_em_ordem      (int v[], int tam);
void embaralha_vetor          (int v[], int tam);
void imprime_vetor            (int v[], int tam);
void insertionsort            (int v[], int ini, int fim);
int  particiona_inicio        (int v[], int ini, int fim);
void quicksort_inicio         (int v[], int ini, int fim);
int  particiona_fim           (int v[], int ini, int fim);
void quicksort_fim            (int v[], int ini, int fim);
int  particiona_meio          (int v[], int ini, int fim);
void quicksort_meio           (int v[], int ini, int fim);
void intercala_basico         (int v[], int ini, int meio, int fim);
void mergesort_basico         (int v[], int ini, int fim);
void intercala_melhorado      (int v[], int ini, int meio, int fim);
void mergesort_melhorado      (int v[], int ini, int fim);
