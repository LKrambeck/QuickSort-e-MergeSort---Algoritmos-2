#define MAX 100000000

void gera_vetor_randomico     (int v[], int tam);
void gera_vetor_em_ordem      (int v[], int tam);
void embaralha_vetor          (int v[], int tam);
void imprime_vetor            (int v[], int tam);
void troca                    (int v[], int i, int j);
void insertionsort            (int v[], int ini, int fim);
int  particiona_inicio        (int v[], int ini, int fim);
void quicksort_inicio         (int v[], int ini, int fim);
int  particiona_fim           (int v[], int ini, int fim);
void quicksort_fim            (int v[], int ini, int fim);
int  particiona_meio          (int v[], int ini, int fim);
void quicksort_meio           (int v[], int ini, int fim);
void intercala                (int v[], int ini, int meio, int fim);
void mergesort                (int v[], int ini, int fim);