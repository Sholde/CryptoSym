#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "geffe.h"
#include "test.h"
#include "attaque_geffe.h"
#include "bloc.h"

int main(void) {
	time_t t;
	t = time(NULL);
	srand(t);
	
	int taille = 1000;
	
	char f = 0x8E;
	
	int *k = malloc(sizeof(int) * 2);
	k[0] = rand();
	k[1] = rand();

	int k_0 = k[0];
	int k_1 = k[1];
	
	char *res = generateur(f, k, taille);
	
	affiche_suite(res, 16);

	// Question 2
	tous_les_f();

	// Question 5

	int *k_find = malloc(sizeof(int) * 3);
	//attaque_geffe(res, taille, k_find);

	printf("\n");
	printf("k0 de base = %d\n", k_0 & 0x0000FFFF);
	printf("k0 trouvé  = %d\n", k_find[0]);
	printf("\n");
	printf("k1 de base = %d\n", k_1 >> 16);
	printf("k1 trouvé  = %d\n", k_find[1]);
	printf("\n");
	printf("k2 de base = %d\n", k_1 & 0x0000FFFF);
	printf("k2 trouvé  = %d\n", k_find[2]);

	free(k);
	free(res);

	// exo 2
	printf("\n");
	printf("Exo 2 :\n");
	printf("\n");

	int k0 = 0x01020304;
	int k1 = 0x98765432;
	int nb_tour = 1;
	int l = 0x45019824;
	int r = 0x51023321;

	int old_l = l;
	int old_r = r;

	bloc(&l, &r, k0, k1, nb_tour);

	printf("l1 = %08x\n", l);
	printf("r1 = %08x\n", r);

	k0 = k1 = 0;
	attaque(&old_l, &old_r, &l, &r, &k0, &k1);

	printf("\n");
	printf("Attaque un tour :\n");
	printf("\n");

	printf("k0 = %08x\n", k0);
	printf("k1 = %08x\n", k1);

	return 0;
}
