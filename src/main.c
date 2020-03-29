#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "geffe.h"
#include "test.h"

int main(void) {
	time_t t;
	t = time(NULL);
	srand(t);
	
	int taille = 1000;
	
	char f = 0x8E;
	
	int *k = malloc(sizeof(int) * 2);
	k[0] = rand()%1000;
	k[1] = rand()%1000;

	int k_0 = k[0];
	int k_1 = k[1];
	
	char *res = generateur(f, k, taille);
	
	affiche_suite(res, 16);

	// Question 2
	tous_les_f();

	// Question 3

	k[0] = 0;
	k[1] = 0;

	// k2
	printf("k2 = %d\n", k_1 & 0x0000FFFF);

	int k_final = 0;
	for (int i = 0; i < 65536; i++)
	{
		k[1] = i;
		char *tmp = generateur(f, k, taille);
		
		int nb = 0;
		for (int j = 0; j < taille; j++)
		{
			if( res[j] == tmp[j] )
				nb++;
		}
		int cal = nb*100 / taille;
		if (cal >= 74 && cal <= 76)
		{
			k_final = i;
			i = 70000;
		}
		free(tmp);
	}
	printf("k2 trouvé : %d\n", k_final);

	// k0
	k[0] = 0;
	k[1] = k_final;

	printf("k0 = %d\n", k_0 & 0x0000FFFF);

	k_final = 0;
	for (int i = 0; i < 65536; i++)
	{
		k[0] = i;
		char *tmp = generateur(f, k, taille);
		
		int nb = 0;
		for (int j = 0; j < taille; j++)
		{
			if( res[j] == tmp[j] )
				nb++;
		}
		int cal = nb*100 / taille;
		if (cal >= 24 && cal <= 26)
		{
			printf("%d\n", cal);
			k_final = i;
			i = 70000;
		}
		free(tmp);
	}
	printf("k0 trouvé : %d\n", k_final);

	free(k);
	free(res);

	return 0;
}
