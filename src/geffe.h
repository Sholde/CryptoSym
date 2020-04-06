#ifndef _geffe_h
#define _geffe_h

int retour(int n);

char filtrage(char f, char a, char b, char c);

char *generateur(char f, int *k, int n);

void affiche_suite(char *suite, int n);

void keep_k(int *k, int *k0, int *k1, int *k2);

void affiche_res_geffe(int *k, int k0, int k1, int k2);

#endif
