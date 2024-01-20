# TP2 - Classes

## Objectifs

- Définir des classes
- Définir des constructeurs
- Utiliser la liste d'initialisation et des class-initializers
- Implémenter les fonctions-membre en dehors des classes
- Définir des fonctions-membre `const` (= lecture seule)
- Définir des opérateurs

## Exercice

Dans ce TP, vous allez implémenter le jeu de la [bataille fermée](https://www.youtube.com/watch?v=lS0dpe4GKTY).

### Représentation du jeu

Vous allez avoir besoin de représenter les éléments suivants :

- les 32 cartes
    - la valeur de chaque carte (de 7 à 10 ainsi que valet, dame, roi et as)
    - la couleur (trèfle, carreau, pique, coeur)
- les joueurs
    - son nom
    - la liste des cartes qu'il a en main
    - le nombre de plis emportés

### La classe `Card` (50min)

1. Créez trois fichiers `Card.cpp`, `Card.hpp` et `main.cpp`.
2. Dans le fichier `Card.hpp`, définissez une classe `Card` avec deux attributs privés `_value` et `_color`.  
Sachant que `_value` ne peut pas être négatif, quel type pouvez-vous utiliser ?  
Pour `_color`, vous pouvez utiliser `std::string`.
3. Définissez un constructeur à deux paramètres permettant d'initialiser les deux attributs de la classe.  
Vous placerez l'implémentation de cette fonction dans le fichier `Card.cpp`.
4. Ajoutez une fonction-membre `print` qui affichera dans un premier temps : `"<value> de <color>"`. Par exemple, pour le roi de carreau, on pourra afficher `"13 de Carreau"`.
5. Dans le fichier `main.cpp`, définissez une fonction `main` et ajoutez-y le code suivant pour vérifier que tout fonctionne :
```cpp
Card c1 { 8, "Pique" };
c1.print();
```
6. Indiquez maintenant que `c1` est `const` et vérifiez que le code compile toujours. Ajoutez ce qu'il faut sur la définition de `print` si ce n'est pas le cas.
```cpp
const Card c1 { 8, "Pique" };
c1.print();
```
7. Vous allez maintenant définir un opérateur d'égalité pour la classe `Card` en tant que **fonction-membre**. Celui-ci aura pour objectif de vérifier si deux cartes ont la même valeur (on ne considère pas la couleur).  
Ajoutez les instructions suivantes dans le `main` pour vérifier que votre code est juste :
```cpp
Card c2 { 8, "Carreau" };
std::cout << (c2 == c1) << std::endl; // -> 1
Card c3 { 10, "Carreau" };
std::cout << (c2 == c3) << std::endl; // -> 0 
```
8. Ajoutez `const` devant `c2` et `c3`.  
Vérifiez que le code compile toujours et modifiez ce qu'il faut si ce n'est plus le cas.
9. Définissez maintenant l'opérateur d'infériorité stricte, sur le même principe que l'opérateur d'égalité, afin de faire fonctionner le code suivant :
```cpp
std::cout << (c1 < c2) << std::endl; // -> 0
std::cout << (c1 < c3) << std::endl; // -> 1
std::cout << (c3 < c1) << std::endl; // -> 0
```
10. **(Bonus)** Modifiez l'implémentation de `print` pour qu'elle affiche `"As"`, `"Roi"`, `"Dame"` et `"Valet"` plutôt que les valeurs associées.  
Essayez de ne pas utiliser de `if` !
11. **(Bonus)** Remplacez la fonction `print` par un opérateur de flux.  
Que devez-vous faire pour que cette fonction puisse accéder aux attributs de `Card`, sans changer leur visibilité ?  

### La classe `Player` (40min)

1. Créez deux fichiers `Player.cpp` et `Player.hpp`.
2. Définissez une classe `Player` contenant les attributs `_name` (de type `std::string`), `_cards` (de type `std::vector<Card>`) et `_score` (de type `unsigned int`).
3. Ajoutez un constructeur à 1 paramètre permettant d'initialiser `_name`.  
Si vous ne précisez rien pour `_cards`, comment sera initialisé l'attribut ?  
Même question pour `_score`.  
Ajoutez un class-initializer pour assigner à `_score` la valeur 0.
4. Vous allez maintenant définir une **fonction-membre statique** permettant de distribuer les cartes entre les joueurs. Voici le prototype attendu : `void Player::deal_all_cards(Player& p1, Player& p2);`.  
En ce qui concerne l'implémentation :
    - Commencez par définir une variable locale `std::vector<Card> all_cards`, dans laquelle vous ajoutez toutes les cartes possibles (vous pouvez utiliser deux boucles `for` imbriquées).
    - Copiez-collez l'instruction ci-dessous (vous aurez besoin d'include `<algorithm>` et `<random>`). Elle permet de mélanger le tableau de façon aléatoire.
    ```cpp
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(seed));
    ```
    - Ajoutez la première moitié de `all_cards` à la main du premier joueur et la seconde à la main du deuxième.
5. Définissez un opérateur d'indice dans la classe `Player` pour récupérer la n-ième carte de sa main.  
Vérifiez ensuite que vos fonctions se comportent comme prévu en ajoutant les instructions ci-dessous dans le `main` :
```cpp
Player p1 { "Gerald" };
Player p2 { "Julien" };
Player::deal_all_cards(p1, p2);

for (auto i = 0; i < 16; ++i)
{
    std::cout << p1[i] << std::endl;
    std::cout << p2[i] << std::endl;
}
```

### Le jeu (30min) 

1. Définissez un attribut statique `Player::turn_number` qui servira à contenir le nombre de tours de la partie.  
Quel mot-clef devez-vous utiliser pour transformer la déclaration de l'attribut en définition ?
2. Ajoutez une fonction-membre statique `Player::play` prenant en paramètre les deux joueurs.  
Dedans, vous afficherez les deux cartes jouées au tour courant.
Vous incrémenterez le score du joueur qui remporte le pli (en cas d'égalité, pas de changement), puis vous augmenterez le nombre de tours.  
La fonction renverra sous forme de booléen si la partie est terminée ou pas.
3. Enfin, définissez un **getter** dans `Player` permettant de récupérer le score de chaque joueur.  
Assurez-vous qu'il puisse être utilisé sur des variables `const`. 
4. Modifiez la fonction `main` pour simuler une partie de bataille entre `Julien` et `Gerald`.

