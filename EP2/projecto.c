#include <stdio.h>
#include "pilha.h"
#include <string.h>
#include <stdbool.h>

#define ARRAYSIZE (a) (sizeof (a) / sizeof (a[0]))
#define MAXWORDSIZE 20

typedef char* String;

bool checkWord (String *words, int pos, String word, int idx) 
// array with all the words, position (char) in words to be analized, 
// word reference, letter (char in position idx) in word reference -> true/false
{
    if (idx >= ARRAYSIZE (word))
        return true;
    if (!checkWord (words, pos, word, idx+1));
        return false;
    for (int i = 0; i < ARRAYSIZE(words); i++) 
        if (words[i][pos] == word[letter])
            return true
    return false;
}

String* getVert (int col, int last, int m, int **tabShow)
// col to analize, idx of last line, m lines, matrix of words
{
    String vert[m];

    for (int i = 0; i < last; i++) {
        if (tabShow[i][j] == -1)
            memset(vert, 0, sizeof vert);
        vert[i] = tabShow[k][j];
    }

    return vert;

}

bool ifUsed (pilha *p, String word)
// pile with all used words, word to be found in this pile
{
    aux = criaPilha (p->tam);
    
    return true;
}



bool tabPos (int **tab, int m, int n, int , string *words)
// matrix with 0 or -1, m lines, n columns, words to insert
{
    pilha *pil = criaPilha (p);
    String lastWord;

    int **tabShow = (int**) malloc (m * sizeof (int*)); 
        for (int i = 0; i < m; i++)
            tab[i] = (int*) malloc (n * sizeof (int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (tab[i][j] == '-1') {
                tabShow[i][j] = '*';
                // check word in vertical
                if (i > 0) {
                    String vert = getVert (j, i, m, tabShow);
                    for (int w = 0; vert && w < p; w++)
                        if (strcmp (vert, words[w]) && ifUsed (words, p, words[w])) {
                            empilha (pil, w);
                            vert = NULL;
                        }
                            
                    // backtracking
                    if (vert) {
                        desempilha (pil);
                        i--;
                    }
                }

            else {
                int wordSize = 0;
                for (int k = j; k < n && tab[i][k] != '-1'; k++) 
                    wordSize++;

                // check if there's a word in words[] which size is wordSize
                for (int w = 0; w < p; w++)
                    if (words[w] != lastWord && ARRAYSIZE (words[w]) == wordSize && checkWord (words, i, words[w], 0)) {
                        empilha (pil, words[w]);
                        for (int h = 0; h < wordSize; h++)
                            tabShow[i][j+h] = words[w][h];
                        j += wordSize;
                        break;
                    }

                if (topoDaPilha (pil) != lastWord)
                    lastWord = topoDaPilha (pil);
                
                // backtracking
                else {
                    desempilha (pil);
                    i--;
                }
            }            
        }       
}

int main ()
{
    int m, n, p;
    int **tab;

    printf ("*************// CAÇA-PALAVRAS \\***************");
    
    
    printf ("Digite a entrada cujo formado por várias instâncias no formato: \n"
        "'m n' (tamanho do tabuleiro)\n"
        "m vezes 'int int ... int' onde int = 0/-1 (vai letra/não vai letra)\n"
        "'p' (número de palavras)\n"
        "p vezes 'string' onde string são as palavras contidas no tabuleiro\n"
        "...\n"
        "'0 0' que representa o fim da entrada\n");
    
    while (m != 0 && n != 0) {
        scanf ("%d %d", &m, &n);

        if (m == 0 || n == 0)
            continue;

        tab = (int**) malloc (m * sizeof (int*)); 
        for (int i = 0; i < m; i++)
            tab[i] = (int*) malloc (n * sizeof (int));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) 
                scanf ("%d", &tab[i][j]);

        scanf ("%d", &p);

        String *words[p];
        for (int i = 0; i < p; i++)
            scanf ("%s", words[i]);

    }




    return 0;
}