#ifndef _bloc_h
#define _bloc_h

int rotate(int x, int y);
void step(int *l, int *r, int k);
void bloc(int *l, int *r, int k0, int k1, int nb_tour);
void attaque_un_tour(int *clair, int *chiffre, int *cle);
void init_clair_chiffre(int *clair, int *chiffre, int nb_tour, int nb_texte);
void affiche_double(int a, char *sa, int b, char *sb);

#endif 