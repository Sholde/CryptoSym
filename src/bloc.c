
#include "bloc.h"

#define rotate(x, y) ((x << y) ^ (x >> (32 - y)))

void step(int *l, int *r, int k) {
    *l = *l ^ *r;
    *l = rotate(*l, 7);
    *l = *l ^ k;

    int tmp = *r;
    *r = *l;
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