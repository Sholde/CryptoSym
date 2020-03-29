#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "geffe.h"
#include "test.h"

int main(void) {
	time_t t;
	t = time(NULL);
	srand(t);
	
	int n = 16;
	
	char f = 0x8E;
	
	int *k = malloc(sizeof(int) * 2);
	k[0] = rand();
	k[1] = rand();
	
	char *res = generateur(f, k, n);
	
	affiche_suite(res, n);
	
	free(k);
	free(res);

	// Question 2
	tous_les_f();
	
	return 0;
}
