#include "geffe.h"
#include "attaque_geffe.h"

void attaque_geffe(char *s, int taille, int *k) {

    // k2
    int tmp;
	for (int i = 0; i < 65536; i++)
	{
		tmp = i;
		
		int nb = 0;
		for (int j = 0; j < taille; j++)
		{
			if( s[j] == (tmp & 1) )
				nb++;

			tmp = tmp | (retour(tmp & 0x0000002D) << 16);
			tmp = tmp >> 1;
		}
		int cal = (nb*100) / taille;
		if (cal >= 73 && cal <= 77)
		{
			k[2] = i;
			i = 70000;
		}
	}

	// k0
	for (int i = 0; i < 65536; i++)
	{
		tmp = i;
		
		int nb = 0;
		for (int j = 0; j < taille; j++)
		{
			if( s[j] == (tmp & 1) )
				nb++;

			tmp = tmp | (retour(tmp & 0x00000093) << 16);
			tmp = tmp >> 1;
		}
		int cal = nb*100 / taille;
		if (cal >= 22 && cal <= 28)
		{
			k[0] = i;
			i = 70000;
		}
	}

    // k1
	for (int i = 0; i < 65536; i++)
	{
		tmp = i;
		
		int nb = 0;
		for (int j = 0; j < taille; j++)
		{
			if( s[j] == (tmp & 1) )
				nb++;

			tmp = tmp | (retour(tmp & 0x00000883) << 16);
			tmp = tmp >> 1;
		}
		int cal = nb*100 / taille;
		if (cal >= 22 && cal <= 28)
		{
			k[1] = i;
			i = 70000;
		}
	}
}