
#include "bloc.h"

#define rotate(x, y) ((x << y) ^ (x >> (32 - y)))

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

void attaque(int *l0, int *r0, int *l1, int *r1, int *k0, int *k1) {
    *k0 = *l1 ^ rotate(*l0 ^ *r0, 7);
    *k1 = *r1 ^ rotate(*l1 ^ *r0, 7);
}