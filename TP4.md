# TP4 - Définir des classes

Ce TP vous donnera l'occasion de vous familiariser avec la notion d'ownership et de manipuler les unique_ptr, les références et les pointeurs nus.

Nous utiliserons à nouveau le framework de test Catch2 pour les tests unitaires.

---

## 0- Mise à jour du dépôt

Vous allez devoir récupérer les sources du TP4 sur votre dépôt local.

1. Commencez par vous assurez que vous n'avez pas de changements en cours sur votre branche courante.
```b
git status
```
Si vous avez des modifications, commitez-les :
```b
git add .
git commit -m "Saved changes."
```

2. Si vous ne l'avez pas fait aux TPs précédents, ajoutez le dépôt d'origine en tant qu'upstream de votre dépôt local :
```b
git remote add upstream https://github.com/Laefy/CPP_Exercises.git
```

3. Récupérez les derniers changements du dépôt d'origine, placez-vous sur la branche tp4 et pushez-la sur votre fork :
```b
git fetch upstream
git switch tp4
git push -u origin tp4
```

4. Si vous ne l'avez pas fait au TP3, mettez à jour vos sous-modules afin de télécharger la librairie Catch2.
```c
git submodule init
git submodule update
```

5. Supprimez le répertoire `build/` pour être sûr de repartir sur de bonnes bases.

6. Si pour une raison quelconque, votre branche tp4 se retrouve toute cassée, vous pouvez la réinitialiser avec :
```b
# Assurez vous que vous êtes bien sur la branche tp4.
git status
# Réinitialiser la branche courante pour la faire pointer sur upstream/tp4. Attention, vous perdrez tous les changements faits sur cette branche.
git reset --hard upstream/tp4
```

---

## 1- Un peu de Lore

L'exercice se déroule dans l'univers des Pokémons.

Les Pokémons sont des créatures qui peuvent être capturées par des dresseurs au moyen de Pokéballs. Un dresseur peut avoir au maximum 6 Pokéballs sur lui. S'il capture un Pokémon alors que son équipe est déjà complète, ce nouveau Pokémon est envoyé dans un endroit appelé "PC". Chaque dresseur connaît le PC vers lequel ses Pokémons sont envoyés, et un même PC peut être utilisé par différents dresseurs.

---

## 2- Exercice

Le TP sera à réaliser en utilisant la méthodologie TDD.
Vous avez de la chance, tous les tests sont déjà écrits dans les fichiers Test-X.cpp (le framework utilisé est Catch2).

Pour avancer, vous pouvez :
- tenter de compiler le prochain Test-X,
- ajouter les fonctionnalités nécessaires pour faire en sorte que ce test compile,
- l'exécuter,
- modifier vos implémentations jusqu'à ce que le test passe,
- commiter vos changements,
- relancer tous les tests pour vérifier que vous n'avez pas introduit de régressions dans les tests 1 à X-1.

Faites attention à bien respecter l'ordre de ces étapes et à ne pas avancer trop vite, vous risqueriez de vous empêtrer dans un tas de bugs autrement.

Autre conseil, n'hésitez pas à faire le minimum syndical pour que les tests passent. Par exemple, si vous n'avez que le test `fonction_qui_a_lair_super_complique() == true` à faire passer, vous pouvez très bien écrire :
```cpp
void fonction_qui_a_lair_super_complique() { return true; } // ce n'est pas de la triche, au contraire
```
puis passez à l'étape suivante.

Dernier petit point avant de commencer, vous ne devriez à aucun moment avoir besoin de modifier le code des tests.

Bon courage à vous ! Si vous êtes bloqués, n'hésitez pas à utiliser les indices ci-dessous :)

---

## 3- Indices

### Test-1

> **Pokemons can be constructed with their name**\
> Quelle classe pourriez-vous utiliser pour stocker le nom d'un Pokémon ?

> **Querying the name of a Pokemon does not modify the Pokemon**\
> Comment faut-il faire pour indiquer qu'une fonction-membre ne va pas modifier les attributs de l'instance sur laquelle elle est appelée ?

### Test-2

> **Pokeballs are empty by default**\
> Faites au plus simple ici. Le but, c'est de faire en sorte que le test passe avec le moins de code possible.

### Test-3

> **Pokemons can be stored in Pokeballs**\
> Quel est le type renvoyé par `std::make_unique<T>` ?
Déduisez-en le type de `pikachu`, puis la signature de `Pokeball::store`.\
> Sachant qu'on appelle la fonction `name()` sur la valeur de retour de `Pokeball::pokemon()`, que pourrait-être son type ?

### Test-4

> **PCs are constructed with 0 pokemon inside**\
> Connaissez-vous une classe qui permet de stocker une liste d'objets et possède une fonction-membre `empty` ?\
> Déduisez-en un type de retour possible pour la fonction `PC::pokemons`. N'oubliez pas que c'est du TDD, tant que ça compile et que le test passe, on peut passer à la suite.

### Test-5

> **A Pokemon can be put inside the PC**\
> Puisqu'on utilise l'opérateur `->` sur `pokemons[0]`, de quels types selon vous peuvent être les éléments de `pokemons` ?\
> Sachant que le `PC` prend l'ownership des Pokémons qui sont stockés dedans, quel est le meilleur type à utiliser ?

### Test-6

> **Trainers are constructed with their name and they are assigned a PC**\
> Pensez-vous que les dresseurs sont propriétaires de l'instance de `PC` qui leur est passé en paramètre ?

### Test-7

> **Trainers start with 6 empty pokeballs**\
> Cherchez sur cppreference une classe permettant de représenter un conteneur qui contient toujours exactement 6 éléments.

### Test-8

Pour information, une `SECTION` dans Catch2 permet de définir plusieurs tests qui seront exécutés indépendemment les uns des autres.

Exemple:
```cpp
TEST_CASE("Test")
{
    int a = 0;

    SECTION("S1")
    {
        REQUIRE(a * 1 == 0);
    }

    SECTION("S2")
    {
        REQUIRE(a + 1 == 1);
    }

    SECTION("S3")
    {
        REQUIRE(a - 2 == -2);
    }

    REQUIRE(a == 0);
}
```
Trois tests vont être générés, qui contiendront respectivement les instructions :
```cpp
// Test-S1:
int a = 0;
REQUIRE(a * 1 == 0);
REQUIRE(a == 0);

// Test-S2:
int a = 0;
REQUIRE(a + 1 == 1);
REQUIRE(a == 0);

// Test-S3:
int a = 0;
REQUIRE(a - 2 == -2);
REQUIRE(a == 0);
```

### Test-9

> **A Pokemon knows its trainer**\
> Pensez-vous qu'un Pokémon soit propriétaire de son dresseur ? Idéalement, comment devriez-vous du coup stocker l'information du dresseur de chaque Pokémon ?\
> Sachant qu'un Pokémon peut ne pas avoir de dresseur (lorsqu'il n'est pas capturé), que pourriez-vous utiliser à la place ?
> Pour éviter les inclusions cycliques (Pokemon -> Trainer et Trainer -> Pokeball -> Pokemon), vous pouvez utiliser une forward-declaration.

### Test-10

> **A trainer can store Pokemons in the PC - If the first Pokemon is stored, it goes in the PC, and the other Pokemons stay at their places**\
> Il faudra pouvoir extraire un Pokémon d'une Pokéball pour pouvoir le placer dans le PC. 

### Test-11

> **A trainer can retrieve their Pokemons from the PC**\
> Recherchez sur cppreference comment supprimer un élément du conteneur que vous avez utilisé pour stocker les Pokémons dans le PC.\
Lorsque vous allez sur la documentation d'une fonction ou d'une classe, il faut toujours commencer par regarder les exemples.\
> Pour éviter les inclusions cycliques (PC -> Trainer et Trainer -> PC), vous pouvez utiliser une forward-declaration et implémentez certaines fonctions dans le .cpp.
> Attention aux invalidations d'itérateurs !

---

Céline Noël\
C++ Master 1\
2022 - 2023
