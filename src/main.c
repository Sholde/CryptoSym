#include <stdlib.h>
#include <stdio.h>

#include "geffe.h"

int main(void) {
	
	int n = 45;
	
	const int f_size = 8;
	char *f = malloc(sizeof(char) * f_size);
	f[0] = 0;
	f[1] = 0;
	f[2] = 0;
	f[3] = 1;
	f[4] = 0;
	f[5] = 0;
	f[6] = 1;
	f[7] = 0;
	
	int *k = malloc(sizeof(int) * 2);
	k[0] = 0x0000A056;
	k[1] = 0x59488F9F;
	
	char *res = generateur(f, k, n);
	
	affiche_suite(res, n);
	
	free(k);
	free(f);
	free(res);
	
	return 0;
}
