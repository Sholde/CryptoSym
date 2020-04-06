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
    for(int i = 0; i < nb_texte * 2; i += 2) {
        if(i == 0) {
            chiffre[i] = clair[i] = rand();
            chiffre[i+1] = clair[i+1] = rand();
        }
        else {
            int tmp1, tmp2;
            tmp1 = clair[i-2];
            tmp2 = clair[i-1];
            bloc(&tmp1, &tmp2, k0, k1, 1);
            chiffre[i] = clair[i] = tmp1;
            chiffre[i+1] = clair[i+1] = tmp2;
        }
        bloc( (chiffre + i), (chiffre + i + 1), k0, k1, nb_tour);
    }
    printf("Clé utilisé pour chiffrer les messages :\n\n");
    affiche_double(k0, "k0", k1, "k1");
}

int attaque_texte(int *clair, int *chiffre, int *cle) {
    int a[2];
    int b[2];

    a[0] = clair[0];
    a[1] = clair[1];
    b[0] = clair[2];
    b[1] = clair[3];
    int cle_1[2];
    attaque_un_tour(a, b, cle_1);

    a[0] = chiffre[0];
    a[1] = chiffre[1];
    b[0] = chiffre[2];
    b[1] = chiffre[3];
    int cle_2[2];
    attaque_un_tour(a, b, cle_2);

    if(cle_1[0] == cle_2[0] && cle_1[1] == cle_2[1]) {
        cle[0] = cle_1[0];
        cle[1] = cle_1[1];
        return 0;
    }
    else {
        cle[0] = 0;
        cle[1] = 0;
        return 1;
    }
}

void affiche_double(int a, char *sa, int b, char *sb) {
    printf("%s = %08x\n", sa, a);
	printf("%s = %08x\n", sb, b);
    printf("\n");
}