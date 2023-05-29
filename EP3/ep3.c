/* 

    Nome: Fernanda Itoda
    Nusp: 10740825

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool Des = true;
bool Ord = false;
bool pOrd = false;
bool tam = false;

int comp, mov;

void troca (int v[], int a, int b) 
{
    int aux;

    aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void bubblesort (int v[], int n)
{
    int i, inv;
    inv = true;

    while (inv) {
        inv = false;
        for (i = 0; i < n-1; i++){

            comp ++; 
            if (v[i] > v[i+1]) {
                mov++;
                troca (v, i, i+1);
                inv = true;
            }
        }
    }
}

void insercao (int v[], int n)
{
    int j, i, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        i = j-1;
        while (i >= 0) {
            comp++;
            if (v[i] > x) {
                v[i+1] = v[i];
                mov++;
                i--;
            }
            else break;
        }
        v[i+1] = x;
    }
}

void intercala (int v[], int ini, int meio, int fim)
{
    int *w = malloc ((fim - ini) * sizeof (int));
    int p = ini, s = meio, pw = 0, i;

    while (p < meio && s < fim) {
        comp++;
        mov++;
        if (v[p] < v[s]) {
            w[pw] = v[p];
            pw++;
            p++;
        }
        else {
            w[pw] = v[s];
            pw++;
            s++;
        }
    }

    while (p < meio) {
        w[pw++] = v[p++];
        mov++;
    } 
    while (s < fim) {
        w[pw++] = v[s++];
        mov++;
    }

    for (i = ini; i < fim; i++) {
        mov++;
        v[i] = w[i-ini];
    }
    free (w);


}

void mergesort (int v[], int i, int f)
{
    int meio = (i+f) / 2;

    if (f-i > 1) {
        mergesort (v, i, meio);
        mergesort (v, meio, f);
        intercala (v, i, meio, f);
    }
}

int sorteia (int ini, int fim)
{
    int numero;
    srand (time(0));
    if (fim-ini < 0)
        numero = ini;
    else
        numero = (rand() % (fim - ini + 1)) + ini;

    return numero;
}

int particiona (int v[], int ini, int fim)
{
    int i = ini, j = fim;
    
    while (i < j) {
        while (i < j) {
            if (v[j] >= v[i]) {
                comp++;
                j--;
            }
            else break;
        }
        if (i < j) {
            mov++;
            troca (v, i, j);
        } 
        while (v[i] < v[j]){
            comp++;
            i++;
        } 
        if (i < j){
            mov++;
            troca (v, i, j);
        } 
    }
    return i;
}

void quicksortAleatorio (int *v, int ini, int fim)
{
    int pivo;
    if (ini < fim) {
        pivo = sorteia (ini, fim);
        mov++;
        troca (v, pivo, fim);

        pivo = particiona (v, ini, fim);
        quicksortAleatorio (v, ini, pivo-1);
        quicksortAleatorio (v, pivo + 1, fim);
    }
}

void quicksort (int *v, int ini, int fim)
{
    int pivo;
    if (ini < fim) {
        pivo = particiona (v, ini, fim);
        quicksort (v, ini, pivo-1);
        quicksort (v, pivo + 1, fim);
    }
}

void rebaixa (int v[], int n, int i)
{
    int pai = i, filho = 2 * i + 1;

    while (filho < n) {
        if (filho + 1 < n)
            if (v[filho+1] > v[filho]) {
                comp++;
                filho++;
            }
        comp++;
        if (v[pai] < v[filho]) {
            mov++;
            troca (v, pai, filho);
        }
        else break;
        pai = filho;
        filho = 2 * pai + 1;
    }
}

void heapifica ( int v[], int n) {

    int i;
    for (i = (n-2) / 2; i >= 0; i--)
        rebaixa (v, n, i);
}

void heapsort (int v[], int n)
{
    int i, aux;
    heapifica (v, n);
    for (i = n - 1; i > 0; i--) {
        mov++;
        troca (v, 0, i);
        heapifica (v, i);
    }
}

void analise (int v[], int n, FILE *f)
{
    int i;
    int *v1 = malloc (n * sizeof (int));
    int *v2 = malloc (n * sizeof (int));
    int *v3 = malloc (n * sizeof (int));
    int *v4 = malloc (n * sizeof (int));
    int *v5 = malloc (n * sizeof (int));
    for (i = 0; i < n; i++) {
        v1[i] = v[i];
        v2[i] = v[i];
        v3[i] = v[i];
        v4[i] = v[i];
        v5[i] = v[i];
    }

    comp = 0; mov = 0;
    bubblesort (v, n);
    fprintf (f, "1 \t %d \t %d \t %d \t %d\n", n, comp+mov, mov, comp);

    comp = 0; mov = 0;
    insercao (v1, n);
    fprintf (f, "2 \t %d \t %d \t %d \t %d\n", n, comp+mov, mov, comp);

    comp = 0; mov = 0;
    mergesort (v2, 0, n);
    fprintf (f, "3 \t %d \t %d \t %d \t %d\n", n, comp+mov, mov, comp);

    comp = 0; mov = 0;
    quicksort (v3, 0, n-1);
    fprintf (f, "4 \t %d \t %d \t %d \t %d\n", n, comp+mov, mov, comp);

    comp = 0; mov = 0;
    quicksortAleatorio (v4, 0, n-1);
    fprintf (f, "5 \t %d \t %d \t %d \t %d\n", n, comp+mov, mov, comp);

    comp = 0; mov = 0;
    heapsort (v5, n);
    fprintf (f, "6 \t %d \t %d \t %d \t %d\n", n, comp+mov, mov, comp);
}

int main (int argc, char **argv)
{
    FILE *f;
    int *vOrd, *vDes, *vPOrd;
    int i, n;

    srand (12345);


    if (tam) {

    }
    else {
        if (Des) {
            f = fopen ("ep3_des.txt", "w");
            if (f == NULL) {
                printf ("Erro ao abrir arquivo\n");
                exit (1);
            }
            fprintf (f, " # Algoritmo \t n \t total \t trocas \t comparações\n");
            for (n = 250; n <= 32000; n *= 2){
                vDes = malloc (n * sizeof (int));
                for (i = 0; i < n; i++)
                    vDes[i] = rand() % 501;

                analise (vDes, n, f);
            }
        }

        else if (Ord) {
            f = fopen ("ep3_ord.txt", "w");
            if (f == NULL) {
                printf ("Erro ao abrir arquivo\n");
                exit (1);
            }
            fprintf (f, " # Algoritmo \t n \t total \t trocas \t comparações\n");
            for (n = 250; n <= 32000; n *= 2){
                vOrd = malloc (n * sizeof (int));
                for (i = 0; i < n; i++)
                    vOrd[i] = i;

                analise (vOrd, n, f);
            }
        }
        else {
            f = fopen ("ep3_pord.txt", "w");
            if (f == NULL) {
                printf ("Erro ao abrir arquivo\n");
                exit (1);
            }
            fprintf (f, " # Algoritmo \t n \t total \t trocas \t comparações\n");
            for (n = 250; n <= 32000; n*=2) {
                vPOrd = malloc (n * sizeof (int));
                for (i = 0; i < n/2; i++)
                    vPOrd[i] = rand () % 501;
                for (i = n/2; i < n; i++)
                    vPOrd[i] = i - n/2;

                analise (vPOrd, n, f);
            }
        }
    }


    return 0;
}