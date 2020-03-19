#include <stdlib.h>
#include <stdio.h>

#include "geffe.h"

char retour(int n) {
	char res = 0;
	for(int i = 0; i < 32; i++) {
		res ^= (n & 1);
		n >>= 1;
	}
	return res;
}

char filtrage(char *f, char a, char b, char c) {
	if( !a && !b && !c )
		return f[0];
	if( a && !b && !c )
		return f[1];
	if( !a && b && !c )
		return f[2];
	if( a && b && !c )
		return f[3];
	if( !a && !b && c )
		return f[4];
	if( a && !b && c )
		return f[5];
	if( !a && b && c )
		return f[6];
	if( a && b && c )
		return f[7];
	
	return 0;
}

char *generateur(char *f, int *k, int n) {
	
	char *res = malloc(sizeof(char) * n);
	
	int k0 = k[0];
	int k1 = k[1] >> 16;
	int k2 = (k[1] << 16 ) >> 16;
	
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
		
		k0 = k0 | retour(tmp0);
		k1 = k1 | retour(tmp1);
		k2 = k2 | retour(tmp2);
	}
	
	return res;
}

void affiche_suite(char *suite, int n) {
	printf("Suite chiffrante :\n");
	for(int i = 0; i < n; i++) {
		printf("%c", suite[i] + '0');
	}
	printf("\n");
}
