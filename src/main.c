#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "geffe.h"
#include "test.h"
#include "attaque_geffe.h"
#include "bloc.h"

void init_random(void) {
	time_t t;
	t = time(NULL);
	srand(t);
}

int *random_k(void) {
	int *k = malloc(sizeof(int) * 2);
	k[0] = rand();
	k[1] = rand();
	return k;
}

int main(void) {

	// Exo 1
	printf("Exo 1 : \n\n");

	init_random();
	
	int taille = 1000;
	char f = 0x8E;
	
	int *k = random_k();

	int k_0, k_1, k_2;
	keep_k(k, &k_0, &k_1, &k_2);
	
	char *res = generateur(f, k, taille);
	
	affiche_suite(res, 16);

	// Question 2
	tous_les_f();

	// Question 5
	int *k_find = malloc(sizeof(int) * 3);
	attaque_geffe(res, taille, k_find);

	affiche_res_geffe(k_find, k_0, k_1, k_2);

	// Libère la mémoire
	free(k);
	free(res);
	free(k_find);

	///////////////////////////////////////////////////

	// Exo 2
	printf("####################################\n\n");
	printf("Exo 2 :\n\n");

	// init
	int nb_tour = 1;
	int k0 = 0x01020304;
	int k1 = 0x98765432;
	int l = 0x45019824;
	int r = 0x51023321;

	bloc(&l, &r, k0, k1, nb_tour);

	printf("L1 et R1 après %d tour :\n\n", nb_tour);
	affiche_double(l, "l1", r, "r1");

	// Attaque 1 tour

	printf("Attaque à %d tour :\n\n", nb_tour);

	nb_tour = 1;
	int nb_texte = 1;
	int *clair = malloc(sizeof(int) * 2 * nb_texte);
	int *chiffre = malloc(sizeof(int) * 2 * nb_texte);
	int *cle = malloc(sizeof(int) * 2);

	init_clair_chiffre(clair, chiffre, nb_tour, nb_texte);

	attaque_un_tour(clair, chiffre, cle);

	printf("Clé trouvé :\n\n");
	affiche_double(cle[0], "k0", cle[1], "k1");

	// Libère la mémoire
	free(clair);
	free(chiffre);

	// Attaque 12 tour
	nb_tour = 12;
	printf("Attaque à %d tour :\n\n", nb_tour);

	nb_texte = 2;
	clair = malloc(sizeof(int) * 2 * nb_texte);
	chiffre = malloc(sizeof(int) * 2 * nb_texte);

	init_clair_chiffre(clair, chiffre, nb_tour, nb_texte);

	if(attaque_texte(clair, chiffre, cle)) {
		printf("Les clés n'ont pas été trouvé.\n\n");
	}
	else {
		printf("Clé trouvé :\n\n");
		affiche_double(cle[0], "k0", cle[1], "k1");
	}

	free(clair);
	free(chiffre);
	free(cle);

	return 0;
}