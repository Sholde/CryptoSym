#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "geffe.h"

int main(void) {
	time_t t;
	t = time(NULL);
	srand(t);
	
	int n = 45;
	
	const int f_size = 8;
	char *f = malloc(sizeof(char) * f_size);
	f[0] = rand()%2;
	f[1] = rand()%2;
	f[2] = rand()%2;
	f[3] = rand()%2;
	f[4] = rand()%2;
	f[5] = rand()%2;
	f[6] = rand()%2;
	f[7] = rand()%2;
	
	int *k = malloc(sizeof(int) * 2);
	k[0] = rand();
	k[1] = rand();
	
	char *res = generateur(f, k, n);
	
	affiche_suite(res, n);
	
	free(k);
	free(f);
	free(res);
	
	return 0;
}
