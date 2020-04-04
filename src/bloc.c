#include <stdio.h>
#include <stdlib.h>
#include "bloc.h"

int rotate(int x, int y) {
    return ((x << y) ^ (x >> (32 - y)));
}

void step(int *l, int *r, int k) {
    int tmp = *r;
    *r = k ^ rotate(*l ^ *r, 7);
    *l = tmp;
}

void bloc(int *l, int *r, int k0, int k1, int nb_tour) {
    if (nb_tour == 0)
        return;
    
    step(l, r, k0);
    step(l, r, k1);
    nb_tour--;
    bloc(l, r , k0, k1, nb_tour);
}

void attaque_un_tour(int *clair, int *chiffre, int *cle) {
    cle[0] = chiffre[0] ^ rotate(clair[0] ^ clair[1], 7);
    cle[1] = chiffre[1] ^ rotate(chiffre[0] ^ clair[1], 7);
}

void init_clair_chiffre(int *clair, int *chiffre, int nb_tour, int nb_texte) {
    int k0 = rand();
    int k1 = rand();
    printf("k0 = %08x\n", k0);
	printf("K1 = %08x\n", k1);
    for(int i = 0; i < nb_texte * 2; i += 2) {
        chiffre[i] = clair[i] = i;
        chiffre[i+1] = clair[i+1] = 0;
        bloc( (chiffre + i), (chiffre + i + 1), k0, k1, nb_tour);
    }
}

void attaque_texte(int *clair, int *chiffre, int *cle, int nb_tour, int nb_texte) {
    
}

void affiche_double(int a, char *sa, int b, char *sb) {
    printf("%s = %08x\n", sa, a);
	printf("%s = %08x\n", sb, b);
}