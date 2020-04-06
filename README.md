# Projet Crypto

## Compiler

<pre>make</pre>

## Executer

<pre>make run</pre>

## Code source

On directory src.

<pre>cd src/</pre>

## Exercice 1

<pre>
src/geffe.h
src/geffe.c
src/test.h
src/test.c
src/attaque_geffe.h
src/attaque_geffe.c
</pre>

### Le générateur

Se trouve dans :
<pre>
src/geffe.h
src/geffe.c
</pre>

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
- Calcule le bit de sorti s_i en fonction de f et x_0x1x_2
- On récupère d'abord individuellement x_0, x_1 et x_2
- Ensuite on fait les test
- Et on retourne le bon f_i en faisant en & pour prendre le bit et un >> pour le décaler à la position 1

La fonction <bf>generateur</bf> :
- Génére la suite à partir de la fonction de filtrage et de la clé
- La clé est constitué de 2 int
- Les 16 derniers bits du premier int forme l'initialisation du premier LFSR
- Les 16 premiers bits du deuxième int forme l'initialisation du deuxième LFSR
- Les 16 derniers bits du deuxième int forme l'initialisation du troisième LFSR

Ensuite il y a 3 autres fonctions :
<pre>
void affiche_suite(char *suite, int n);
void keep_k(int *k, int *k0, int *k1, int *k2);
void affiche_res_geffe(int *k, int k0, int k1, int k2);
</pre>

La fonction <bf>affiche_suite</bf> :
- simple affichage de la suite chiffrante
- comme dans les char on stocke des 0 et des 1 et non des caractère, on fait + '0', pour afficher les caractère 0 et 1.

La fonction <bf>keep_k</bf> :
- Sert dans le main a récuperer les 3 initialisation des LFSR pour comparer

La fonction <bf>affiche_res_geffe</bf> :
- affiche les initialisation de base et ceux trouver par l'attaque
- les initialisation trouvé sont dans k

### Calcul de la corrélation

Le code se trouve ici :
<pre>
src/test.h
src/test.c
</pre>

Le résultat se trouve ici :
<pre>
res.txt
</pre>

Les fonctions sont :
<pre>
int my_pow(int n, int e);
void int_to_char(char *s, int n, int taille);
int fonction_f(int f, int n);
void tous_les_f(void);
</pre>

La fonction <bf>my_pow</bf> :
- Juste une fonction récursive qui calcule n^e.

La fonction <bf>int_to_char</bf> :
- Elle prend en paramètre une chaine de caractère dans laquelle écrire, le nombre à transformer en chaine de caractère, et la taille en bit du nombre
- Pour chaque itération de i, ca va prendre le bit a la position i (avec le &) et le décaler à la position 1 (avec le >>), ensuite on ajoute la valeur du caractère 0 pour avoir le caractère 0 ou 1.

La fonction <bf>fonction_f</bf> :
- La même fonction de filtrage que dans le code du générateur de geffe mais ici on utilise des int pour faciliter les calculs
- Calcule le bit de sorti s_i en fonction de f et x_0x1x_2
- On récupère d'abord individuellement x_0, x_1 et x_2
- Ensuite on fait les test
- Et on retourne le bon f_i en faisant en & pour prendre le bit et un >> pour le décaler à la position 1

La fonction <bf>tous_les_f</bf> :
- Fonction principale, elle ouvre un fichier et écris les résultat dedans

### L'attaque

## Exercice 2
