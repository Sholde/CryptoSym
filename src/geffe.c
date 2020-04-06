#include <stdlib.h>
#include <stdio.h>

#include "geffe.h"

int retour(int n) {
	int res = 0;
	for(int i = 0; i < 32; i++) {
		res ^= (n & 1);
		n = n >> 1;
	}
	return res;
}

char filtrage(char f, char a, char b, char c) {
	if( !a && !b && !c )
        return (f & 128) >> 7;
	else if( a && !b && !c )
        return (f & 64) >> 6;
	else if( !a && b && !c )
        return (f & 32) >> 5;
	else if( a && b && !c )
        return (f & 16) >> 4;
	else if( !a && !b && c )
		return (f & 8) >> 3;
	else if( a && !b && c )
		return (f & 4) >> 2;
	else if( !a && b && c )
		return (f & 2) >> 1;
	else if( a && b && c )
		return f & 1;
	return 0;
}

char *generateur(char f, int *k, int n) {
	
	char *res = malloc(sizeof(char) * n + 1);
	
	int k0 = k[0] & 0x0000FFFF;
	int k1 = k[1] >> 16;
	int k2 = k[1] & 0x0000FFFF;
	
	int tmp0, tmp1, tmp2;
	
	for(int i = 0; i < n; i++) {
		tmp0 = k0 & 1;
		tmp1 = k1 & 1;
		tmp2 = k2 & 1;
		
		res[i] = filtrage(f, tmp0, tmp1, tmp2);
		
		tmp0 = k0 & 0x00000093;
		tmp1 = k1 & 0x00000883;
		tmp2 = k2 & 0x0000002D;
		
		k0 = k0 >> 1;
		k1 = k1 >> 1;
		k2 = k2 >> 1;
		
		k0 = k0 | (retour(tmp0) << 15);
		k1 = k1 | (retour(tmp1) << 15);
		k2 = k2 | (retour(tmp2) << 15);
	}
	
	return res;
}

void affiche_suite(char *suite, int n) {
	printf("Suite chiffrante :\n");
	for(int i = 0; i < n; i++) {
		printf("%c", suite[i] + '0');
	}
	printf("\n\n");
}

void keep_k(int *k, int *k0, int *k1, int *k2) {
	*k0 = k[0] & 0x0000FFFF;
	*k1 = k[1] >> 16;
	*k2 = k[1] & 0x0000FFFF;
}

void affiche_res_geffe(int *k, int k0, int k1, int k2) {
	printf("k0 de base = %d\n", k0);
	printf("k0 trouvé  = %d\n", k[0]);
	printf("\n");
	printf("k1 de base = %d\n", k1);
	printf("k1 trouvé  = %d\n", k[1]);
	printf("\n");
	printf("k2 de base = %d\n", k2);
	printf("k2 trouvé  = %d\n", k[2]);
	printf("\n");
}
