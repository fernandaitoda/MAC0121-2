/****************************
        EP 1 MAC0121

        Nome: Fernanda Itoda
        Nusp: 10740825
*****************************/

#include <stdio.h>
#define MAX 10000

void cripto (char *text, int len, int d1, int d2)
{
        for (int i = 0; i < len; i++){
                // ASCII for capital letters
                if (text[i] >= 65 && text[i] <= 90){
                        if (text[i] > 90 - d1)
                                text[i] = text[i] + d1 - 90 + 64;
                        else
                                text[i] += d1;
                }
                else if (text[i] >= 97 && text[i] <= 122){
                        if (text[i] > 122 - d2)
                                text[i] = text[i] + d2 - 122 + 96;
                        else
                                text[i] += d2;

                }
        }
}


int main ()
{
        char fileName[80];

        printf ("Digite o nome do arquivo que será criptografado: ");
        scanf ("%s", fileName);

        FILE* file; 
        file = fopen (fileName, "r"); 
        
        if (file == NULL) 
                printf ("Não encontrei o arquivo %s\n", fileName);
        else {
                int len = 0;
                char text[MAX];
                
                while (!feof(file)){
                        fscanf (file, "%c", &text[len]);
                        
                        switch (text[len]){
                        case ' ':
                                break;

                        case ',':
                                text[len++] = 'v'; 
                                text[len++] = 'r';
                                break;
                        
                        case '.':
                                text[len++] = 'p'; 
                                text[len++] = 't';
                                break;
                        
                        case ':':
                                text[len++] = 'd'; 
                                text[len++] = 'p';
                                break;

                        case '!':
                                text[len++] = 'e'; 
                                text[len++] = 'x';
                                break;

                        case '?':
                                text[len++] = 'i'; 
                                text[len++] = 'n';
                                break;
                        
                        case '\n':
                                text[len++] = 'n';
                                text[len++] = 'l';
                                break;

                        default:
                                len++;
                                break;
                        }

                }
                // last 'nl' correction
                //text[len-2] = 0;
                //text[len-3] = 0;
                //len -= 2;
                
                printf ("\nTexto após primeiro passo:\n %s\n\n", text);

                int d1, d2;
                printf ("Digite os inteiros positivos d1 (maiúsculas) e d2 (minúsculas): ");
                scanf ("%d %d", &d1, &d2);

                if (d1 < 0 || d2 < 0){
                        printf ("ERRO: os inteiros digitados não são positivos.\n");
                        return (-1);
                }

                cripto (text, len, d1 % 26, d2 % 26);
                printf ("\nTexto criptografado:\n %s\n\n", text);
        }

        return 0;

}
