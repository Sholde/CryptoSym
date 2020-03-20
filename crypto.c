#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void initiregi(int taille ,int *registres)
{
	  //vecteur d'initialisation
	for(int i=0;i<taille;i++)
	{
		registres[i]=rand()%2;
	}
}



int LFSRtour1(int *registres, int *coefficients, int taille)
 {

 	int dernier = registres[taille - 1];

	// calcul de xor
	int xor=0;

	for (int i = 0; i<taille; i++) 
	{
		if (coefficients[i]==1) 
		{
			xor = xor ^  registres[i];
		}
	}

	

	// Décalage du registre
	
	for (int i = taille - 1; i > 0; i--) 
	{
		registres[i] = registres[i - 1];
	}

	// mettre le bit calculer avec xor dans la premiere case

	registres[0] = xor;

	
	return dernier;
}

int fonctionf(int *f,int b1,int b2,int b3)
{

	  if(!b1 && !b2 && !b3)
	  {
	  	return f[0];

	  }
	  else
	  {
	  	 if(b1 && !b2 && !b3)
	  {
	  	return f[1];

	  }
	  
     else
	  {
	  	 if(b1 && b2 && !b3)
	  {
	  	return f[2];

	  }
	  
 else
	  {
	  	 if(b1 && b2 && b3)
	  {
	  	return f[3];

	  }
	  
 else
	  {
	  	 if(!b1 && b2 && !b3)
	  {
	  	return f[4];

	  }
	  
 else
	  {
	  	 if(!b1 && !b2 && b3)
	  {
	  	return f[5];

	  }
	  
 else
	  {
	  	 if(!b1 && b2 && b3)
	  {
	  	return f[6];

	  }
	  
 else
	  {
	  	 if(b1 && !b2 && b3)
	  {
	  	return f[7];

	  }
	  }
}}}}}}}

int *final(int *f,int *k,int n)
{
	
	 int *resultats=malloc(n*sizeof(int));
	
	 int res1[n];

	 int res2[n];
	 
	 int res3[n];

	 int t=48;
	
	 int sauv=t;
	 t=t/3;
	 int reg1[t];

	 int reg2[t];

	 int reg3[t];

	 for(int i=0;i<t;i++)
	 {
	 	reg1[i]=k[i];
	 }
	    
     int i=0;
	 for(int j=16;j<32;j++)
	 {
	 	reg2[i]=k[j]; 
	 	i++;
	 }

    
       int k1=0;

     for(int i=32;i<48;i++)
	 {
	 	reg3[k1]=k[i];k1++;
	 }
	

	int coefficients1[16]={0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1};
	int coefficients2[16]={0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1};

	int coefficients3[16]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1};

	

	  for(int i=0;i<n;i++)
	  {
           res1[i]= LFSRtour1(reg1,coefficients1,t);

	  }
	  for(int i=0;i<n;i++)
	  {
               res2[i]= LFSRtour1(reg2,coefficients2,t);

	  }
	  for(int i=0;i<n;i++)
	  {
                    
                     res3[i]= LFSRtour1(reg3,coefficients3,t);
           }

	 for(int i=0;i<n;i++)
	 {
            resultats[i]=fonctionf(f,res1[i],res2[i],res3[i]);       
	 }
return resultats;

}

int main()
 {

     srand((unsigned int) time(NULL));

	
	
	int registres1[16];
	int registres2[16];
	int registres3[16];
	
	initiregi(16,registres1);
   
     
     initiregi(16,registres2);

     initiregi(16,registres3);

     int registres[16*3];

     for(int i=0;i<16;i++)
     {
     	registres[i]=registres1[i];

     }
      for(int i=16;i<16*2;i++)
     {
     	registres[i]=registres2[i];

     }
      for(int i=16*2;i<16*3;i++)
     {
     	registres[i]=registres3[i];

     }
    
     
     int *f=malloc(8*sizeof(int));
     initiregi(8,f);

     int *resultats;

	 resultats= final(f,registres,20);
	 printf("la suite chiffrante est \n");
	for(int i=0;i<20;i++)
	{
		printf("%d", resultats[i]);
	}
	printf("\n");

	return 0;
}
