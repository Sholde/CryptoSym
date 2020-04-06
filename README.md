# Projet Crypto

## Compiler

<pre>make</pre>

## Executer

<pre>make run</pre>

## Code source

On directory src.

<pre>cd src/</pre>

## Exercice 1

<pre>src/geffe.h</pre>
<pre>src/geffe.c</pre>
<pre>src/attaque_geffe.h</pre>
<pre>src/attaque_geffe.c</pre>

### Le générateur

Il y a trois fonction pour le générateur : 
<pre>
int retour(int n);
char filtrage(char f, char a, char b, char c);
char *generateur(char f, int *k, int n);
</pre>

La fonction <bf>retour</bf> :
- Prend en paramètre un entier
- Cet entier est le résultat du and du LFSR avec les coefficient de rétroaction
- On prend les bits à xor pour calculer le bit à rajouter au début
- Et la fonction fait un xor sut tous les bits et renvoie le résultat qui est le bit à mettre au début du LFSR

La fonction <bf>filtrage</bf> :
- Prend en paramètre un char qui contient les 8 bits de la fonction de filtrage
- Elle prend aussi les 3 bits des LFSR
- Calcul le bit de sortie suivant les bit d'entrée

La fonction <bf>generateur</bf> :
- Génére la suite à partir de la fonction de filtrage et de la clé
- La clé est constitué de 2 int
- Les 16 derniers bits du premier int forme l'initialisation du premier LFSR
- Les 16 premiers bits du deuxième int forme l'initialisation du deuxième LFSR
- Les 16 derniers bits du deuxième int forme l'initialisation du troisième LFSR

## Exercice 2
