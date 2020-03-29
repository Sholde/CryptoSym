#include <stdio.h>
#include <stdlib.h>

int my_pow(int n, int e) {
    if(e == 0)
        return 1;
    if(e == 1)
        return n;
    else
    {
        return n * my_pow(n, e-1);
    }
    
}

void int_to_char(char *s, int n, int taille) {

    for (int i = 0; i < taille; i++)
    {
        int t = my_pow(2, i);
        s[taille - i - 1] = ((n & t) >> i) + '0';
    }
} 

int fonction_f(int f, int n) {
    int a = n & 4;
    int b = n & 2;
    int c = n & 1;

    if( !a && !b && !c )
        return (f & 128) >> 7;
	if( a && !b && !c )
        return (f & 64) >> 6;
	if( !a && b && !c )
        return (f & 32) >> 5;
	if( a && b && !c )
        return (f & 16) >> 4;
	if( !a && !b && c )
		return (f & 8) >> 3;
	if( a && !b && c )
		return (f & 4) >> 2;
	if( !a && b && c )
		return (f & 2) >> 1;
	if( a && b && c )
		return f & 1;
	return 0;
}

int main(void) {

    char *tmp_f = malloc(sizeof(char) * 9);
    char *tmp_n = malloc(sizeof(char) * 4);
    tmp_f[8] = '\0';
    tmp_n[3] = '\0';

    int nb_a = 0;
    int nb_b = 0;
    int nb_c = 0;

    int store = 0;
    int ret = 0;

    FILE *file;
    file = fopen("res.txt", "w");

    for (int f = 0; f < 256; f++)
    {   
        int_to_char(tmp_f, f, 8);
        fprintf(file,"Pour f = %s :\n", tmp_f);
        fprintf(file, "\n");
        for (int n = 0; n < 8; n++)
        {
            int_to_char(tmp_n, n, 3);
            ret = fonction_f(f, n);
            store = (store << 1) + ret;
            fprintf(file, "f(%s) = %d \n", tmp_n, ret);
        }
        fprintf(file, "\n");

        int i = 128;
        int j = 7;
        for (int n = 0; n < 8; n++)
        {
            if( (n & 4) >> 2 == ((store & i) >> j) ) {
                nb_a++;
            }

            if( (n & 2) >> 1 == ((store & i) >> j) ) {
                nb_b++;
            }

            if( (n & 1) == ((store & i) >> j) ) {
                nb_c++;
            }
            i = i >> 1;
            j--;
        }

        fprintf(file, "Corrélation x0 = %d %\n", nb_a*100 / 8);
        fprintf(file, "Corrélation x1 = %d %\n", nb_b*100 / 8);
        fprintf(file, "Corrélation x2 = %d %\n", nb_c*100 / 8);
        fprintf(file, "\n");

        store = 0;
        nb_a = 0;
        nb_b = 0;
        nb_c = 0;
    }

    free(tmp_f);
    free(tmp_n);

    fclose(file);
    
    return 0;
}