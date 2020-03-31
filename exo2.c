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
    for(int i=0;i<4*ta;i++)
    {
    	printf("%d",tab[i] );
    }
    printf("\n\n");
   
   return tab;

}
char *calculK1(char*text , char * chiffrer)
{
       int t=strlen(text);

       int t1=strlen(chiffrer);

       //recupere la deuxieme partie text

       char * xr=malloc((t/2)*sizeof(char));

   int j=0;
     for(int i=t/2;i<t;i++)
    {
	   xr[j]=text[i];
	   j++;
    }
    char *xl =malloc((t1/2)*sizeof(char));
    char *xR=malloc((t1/2)*sizeof(char));
    for(int i=0;i<t1/2;i++)
    {
    	xl[i]=chiffrer[i];
    }
    j=0;

    for(int i=t1/2;i<t1;i++)
    {
    	xR[j]=chiffrer[i];
    	j++;
    }
     char *xor=malloc((t1/2)*sizeof(char));
     for(int i=0;i<t1/2;i++)
     {
     	xor[i]=xr[i]^xl[i];
     }
    
     char *tra =malloc((4*(t1/2))*sizeof(char));
     char *res=malloc(4*sizeof(char));

   int   pr=4,deu=0;

  j=3;
     for(int i=0;i<t1/2;i++)
     {
     	res=enbinaire(xor[i]);

     	j=3;
           while(deu<pr)
           {

           	tra[deu]=res[j];
           j--;
           	  deu++;
           }
          pr=pr*2;
     }
   //decalage 7 

     char * sau=malloc(7*sizeof(char));

   for(int i=0;i<7;i++)
   {
   	sau[i]=tra[i];

   }  
   
    char * rempl=malloc(((2*t1)-7)*sizeof(char));

    int ind=0;
    for(int i=7;i<2*t1 ;i++)
    {
    	rempl[ind]=tra[i];
    	
    	ind++;
    	
    }
     
     ind=0;

    for(int i=0;i<2*t1-7;i++)
    {
    	tra[i]=rempl[i];
    }

    
    for(int i=2*t1-7;i<2*t1;i++)
    {
    	tra[i]=sau[ind];
    	ind++;
    }
       //xor avec x_(r+1)^R
     char *fs=malloc(2*t1*sizeof(char));
     pr=4;deu=0;

  j=3;
     for(int i=0;i<t1;i++)
     {
     	res=enbinaire(xR[i]);

     	j=3;
           while(deu<pr)
           {

           	fs[deu]=res[j];
           j--;
           	  deu++;
           }
          pr=pr*2;
     }
     for(int i=0;i<2*t1;i++)
     {
     	tra[i]=tra[i]^ fs[i];
     }
     for(int i=0;i<2*t1;i++)
     {
     	printf("%d",tra[i] );
     }
     return tra;
   
}

int main(int argc, char const *argv[])
{
	char * lynda=malloc(5*sizeof(char));

	char *cle0;

	char *cle1;

	lynda="123456";
    
    cle0=calculK0(lynda,lynda);
	cle1=calculK1(lynda,lynda);
	

	
	
	return 0;
}
