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
- On utilise un int pour les différente valeur de f qui va de 0 à 255, donc parcours toutes les valeurs que peut prendre f
- Et pour les valeurs de x_0 x_1 x_2, on utilise un int, on utilise que les 3 dernier bit, et on itère de 0 à 7
- On stocke le bit de sortie de la fonction de filtrage dans la variable store qui déale les bit à gauche avant
- Ensuite après avoir stocker les 8 bits de sortie pour un f on les compare avec les bits de sotie des LFSR

#### Résumé

- Tout d'abord les valeurs de f vont de [0000 0000 - 1111 1111], donc on peut stoker f sur 8 bits avec un int par exemples (plus simples pour les calculs), pariel pour x_0x_1x_2 (sortie de chaque LFSR ) qui prend une valeur dans l'intervalle  [000 -111], donc ca prend 3 bits et on a aussi décidé de le stocker dans un int
- On init deux chaine pour pouvoir ensuite écrire dans un fichier les valeurs $f$ et x_0x_1x_2
- Les variables nb_a, nb_b, nb_c permette de stocker combiens  de fois la valeurs x_0, x_1 et x_2 sont égale à s_i respectivement.
- store et ret sont deux variables qui permette de sauvegarder le contenu de s_i, ret permet de sauvegarder une valeur de $s_i$ et strore sauvegarde les 8 valeurs pour un f_i
- Ensuite comme f peut prendre 256 valeur on itère de 0 à 256, pareil pour n qui reprèsente x_0x_1x_2 on itère de 0 à 8.
- Ensuite on applique des fonction pour écrire dans le fichier
- Dans la boucle de n, on calcule les bits de sortie et on les stocks dans ret, on fait un shift de store pour pouvoir le concatener avec le nouveau bit de sortie
- Maintenant dans store on a nos 8 bits de sortis s_i
- On va calcluez la corrélation
- Pour chaque valeur de n donc de x_0x_1x_2, on récupère individuellement les 3 valeurs en faisant un &, pour x_0 et x_1 on fait un shift pour le décaler à la position 1, et on prend le bit de sortie correspondant avec un & et on le décale avec un shift à la position 1, et si ca correspond on ajoute un au compteur.
- Et ensuite c'est trivial

### L'attaque

Le code se trouve ici :
<pre>
src/attaque_geffe.h
src/attaque_geffe.c
</pre>

La fonction <bf>attaque_geffe</bf> :
- Prend en paramètre la suite chiffrante, la taille de la suite
- le résultat sera dans la variable k
- Comme on connait les corrélation, ici on commence par le 3ème registre, et on regarde le bit de la suite chiffrante et le bit de sortie du LFSR, taille fois
- Pareil pour le 1er et le 2eme
- Et on trouve les initialisation

## Exercice 2

Le code se trouve dans : 

<pre>
src/bloc.h
src/bloc.c
</pre>

Les fonction utilisé sont :

<pre>
int rotate(int x, int y);
void step(int *l, int *r, int k);
void bloc(int *l, int *r, int k0, int k1, int nb_tour);
void attaque_un_tour(int *clair, int *chiffre, int *cle);
void init_clair_chiffre(int *clair, int *chiffre, int nb_tour, int nb_texte);
int attaque_texte(int *clair, int *chiffre, int *cle);
void affiche_double(int a, char *sa, int b, char *sb);
</pre>

La fonction <bf>rotate</bf> :
- Prendd en paramètre un int x à décaler d'une positon y
- Ca fait la rotation x <<< 7

La fonction <bf>step</bf> :
- Correspond à la moitier d'un tour de notre réseaux
- Car notre réseux d'un tour est symétrique, il y a juste la clé qui diffère (et les entré puisqu'on a partagé en deux)
- Donc elle prend le message l et r, ainsi que la clé k
- Et ca écrase les valeur l et r pour mettre les nouvelles valeurs dedans

La fonction <bf>bloc</bf> :
- Applique la fonction step 2 * nb_tour (2 car il y deux clé pour un tour)
- Et la aussi ça écrase les valuer de l et r pour mettre le résultat dedans

La fonction <bf>attaque_un_tour</bf> :
- C'est une attaque d'un tour qui utilise les formules :
- K_0 = L_1 ^ ((L_0 ^ R_0) <<< 7)
- K_1 = R_1 ^ ((L_1 ^ R_0) <<< 7)

La fonction <bf>init_clair_chiffre</bf> :
- Initialise le nombre de texte clair / chiffré choisis
- Le premier texte clair sera 0 et 0
- Les suivant seront le chiffré du premier mais avec un tour

La fonction <bf>attaque_texte</bf> :
- Prend en argument les textes clair et chiffré
- Utilise la supposition que le deuxieme clair est le chiffré d'un tour du premier
- Donc on calcul K_0 et K_1 avec d'une part ($L_0$,$R_0$) et (L_0',R_0') et de l'autre part (L_N,R_N) et (L_N',R_N')

La fonction <bf>affiche_double</bf> :
- Permet d'afficher texte = nombre