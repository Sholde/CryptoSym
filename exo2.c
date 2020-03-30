#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void afficher(char *tab,int taille)
{
  for(int i=0;i<taille;i++)
  {
  	printf("%c",tab[i] );
  }
   printf("\n\n");
}

char *enbinaire(char x)
{
	char * res=malloc(4*sizeof(char));

   for(int i=3;i>=0;i--)
   {
       res[i]=(x>> i)&1;
      
   }
   return res;
  
  

}
char * calculK0(char * text , char * chiffrer)
{   

    int c=strlen(text); 

   

    int c1=c/2;
    int t=strlen(chiffrer);
    int t1=t/2;

    char *k0=malloc(sizeof(char));

    char * x=malloc(c1*sizeof(char));

    char *y =malloc (c1*sizeof(char));

    char *f1=malloc(t1*sizeof(char));

    char *f2=malloc(t1*sizeof(char));

    for(int i=0;i<c1;i++)
    {
     x[i]=text[i];
    }
   

    int j=0;

    for(int i=c1;i<c;i++)
    {
	   y[j]=text[i];
	   j++;
    }
    


    for(int i=0;i<t1;i++)
    {
        f1[i]=chiffrer[i];
    }
      

     j=0;

    for(int i=t1;i<t;i++)
    {
	   f2[j]=chiffrer[i];
	   j++;
    }
   
   
   for(int i=0;i<c1;i++)
   {
   	  k0[i]= x[i] ^ y[i];

   }
  
   int ta=strlen(k0);

   char *tab=malloc(4*ta*sizeof(char));

   int pr=4;int deu=0;

   char *resultat =malloc(4*sizeof(char));
 j=3;
     for(int i=0;i<c1;i++)
     {
     	resultat=enbinaire(k0[i]);

     	j=3;
           while(deu<pr)
           {

           	tab[deu]=resultat[j];
           j--;
           	  deu++;
           }
          pr=pr*2;
     }
     

   char * sau=malloc(7*sizeof(char));

   for(int i=0;i<7;i++)
   {
   	sau[i]=tab[i];

   }  
    
    char * rempl=malloc(sizeof(char));

    int ind=0;
    for(int i=7;i<4*ta ;i++)
    {
    	rempl[ind]=tab[i];
    	
    	ind++;
    	
    }
   
    ind=0;

    for(int i=0;i<4*ta -7;i++)
    {
    	tab[i]=rempl[i];
    }
    for(int i=4*ta-7;i<4*ta;i++)
    {
    	tab[i]=sau[ind];
    	ind++;
    }
   
    //transf de f1
   char *fs=malloc(4*t1*sizeof(char));
     pr=4;deu=0;

  j=3;
     for(int i=0;i<t1;i++)
     {
     	resultat=enbinaire(f1[i]);

     	j=3;
           while(deu<pr)
           {

           	fs[deu]=resultat[j];
           j--;
           	  deu++;
           }
          pr=pr*2;
     }

   for(int j=0;j<4*ta;j++)
   {
   	  tab[j]=tab[j]^ fs[j];
   }

   
   return tab;

}

int main(int argc, char const *argv[])
{
	char * lynda=malloc(5*sizeof(char));
	lynda="123456";
	calculK0(lynda,lynda);
	
	
	return 0;
}