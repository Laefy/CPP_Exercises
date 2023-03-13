TP8 - Algorithmes
=================

## Objectifs du TP

Voici les notions que ce TP vous fera travailler :
- l'ownership,
- les conteneurs,
- les algorithmes,
- les lambdas.

Le sujet consiste ici à créer les éléments d'une application qui gère les stocks d'ingrédients disponibles dans votre cuisine.
A l'issue du TP, votre code permettra de répondre aux besoins suivants :
- pour une recette donnée, on veut calculer la liste de courses permettant de l'exécuter,
- on souhaite obtenir la liste des recettes qu'il est possible de réaliser en n'utilisant que des ingrédients déjà disponibles.

---

## Mise à jour du dépôt

Vous allez devoir récupérer les sources du TP8 sur votre dépôt local.

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

3. Récupérez les derniers changements du dépôt d'origine, placez-vous sur la branche tp8 et pushez-la sur votre fork :
```b
git fetch upstream
git switch tp8
git push -u origin tp8
```

4. Si vous ne l'avez pas fait précédemment, mettez à jour vos sous-modules afin de télécharger la librairie Catch2.
```c
git submodule init
git submodule update
```

5. Supprimez le répertoire `build/` pour être sûr de repartir sur de bonnes bases.

6. Si pour une raison quelconque, votre branche tp8 se retrouve toute cassée, vous pouvez la réinitialiser avec :
```b
# Assurez vous que vous êtes bien sur la branche tp8.
git status
# Réinitialiser la branche courante pour la faire pointer sur upstream/tp8. Attention, vous perdrez tous les changements faits sur cette branche.
git reset --hard upstream/tp8
```

---

## Framework

Dans le répertoire lib/, vous trouverez les types et quelques fonctions utilitaires qui vous permettront de représenter l'état de votre cuisine.
**Vous ne devriez pas avoir à modifier ce répertoire.**

Vous devriez constater que certaines classes utilisent des `std::reference_wrapper<T>` en tant qu'attribut.
Pour information, un `reference_wrapper<T>` est équivalent à une référence de `T` (c'est-à-dire `T&`).
Contrairement aux `T&`, les `reference_wrapper<T>` sont réassignables.
On peut donc placer les `reference_wrapper<T>` et les objets ayant des attributs de type `reference_wrapper<T>` dans des conteneurs.

Dans le répertoire src/, vous trouverez les fichiers Kitchen.cpp et Kitchen.hpp.
Vous devez placer votre code dans ces deux fichiers.
Si vous avez besoin d'inclure un fichier du répertoire lib/ depuis un fichier du répertoire src/, vous pouvez écrire :
`#include "../lib/File.hpp"`.\
Si vous souhaitez découper votre code dans plusieurs fichiers, vous êtes libre de le faire, mais conserver ces fichiers dans le dossier src/ et pensez mettre le `CMakeLists.txt` à jour.

Enfin, dans le répertoire tests/, vous trouverez les tests unitaires à faire passer.

---

## Aides VSCode

**Afin de pouvoir lancer les tests d'un fichier donnée, il faut au préalable compiler le test en question.**

Pour recompiler tous les tests :
- `⚙ Build > [build-tests]` en bas de la fenêtre

Pour compiler les tests du fichier Tests-XX-XXXX :
- `⚙ Build > [Tests-XX-XXXX]`
- ou exécuter BUILD-Tests-XX-XXXX dans l'onglet TESTING

Pour rafraîchir la liste des tests une fois que la compilation d'un fichier est passée :
- appuyer sur le bouton `Reload tests` dans l'onglet Testing.

Pour lancer tous les tests :
- `⚙ Build > [run-tests]` en bas de la fenêtre
- ou sélectionner et exécuter tous les tests préfixés par "TEST-" dans l'onglet TESTING

Pour lancer les tests du fichier Tests-XX-XXXX :
- `⚙ Build > [run-XX-XXXX]` en bas de la fenêtre
- `▷ > [Tests-XX-XXXX]` en bas de la fenêtre
- ou exécuter tous les TEST-Tests-XX-XXXX dans l'onglet TESTING

Pour lancer un test en particulier :
- exécuter le test en question dans l'onglet TESTING

Je conseille d'utiliser l'onglet Testing pour toutes les opérations, compilation comme exécution.\
Attention néanmoins, pour les tests de type "BUILD-", ils doivent être lancé individuellement (problème d'accès concurrents à l'exécutable autrement).\
Si vous voulez builder l'intégralité des tests, vous pouvez utiliser `⚙ Build > [build-tests]`.

---
## Cuisine


### Tests-01-Units

*Units can be registered in the Kitchen*  
Ajoutez une fonction `Kitchen::register_unit` qui enregistre une nouvelle unité de mesure.

*Units can be retrieved from the Kitchen with their name*  
Ajoutez une fonction `Kitchen::find_unit` qui retourne l'unité de mesure ayant le nom donné.

*Units are not relocated in memory when another one is added*  
`Kitchen` est propriétaire des unités de mesure enregistrées.
On souhaite s'assurer que les références retournées par `register_unit` ne sont pas invalidées par une potentielle réallocation mémoire.\
Plusieurs méthodes sont possibles pour éviter ce problème.

### Tests-02-Ingredients

*Ingredients can be registered in the Kitchen*  
Pareil que pour les unités de mesure.  
On s'assure aussi que `ingredient.unit` référence toujours l'unité de mesure passée à la construction.

*Ingredients can be retrieved from the Kitchen with their name*  
Pareil que pour les unités de mesure, si ce n'est que l'on souhaite ignorer la casse dans le cas des ingrédients.

*Ingredients are not relocated in memory when another one is added*  
Pareil que pour les unités de mesure.

### Tests-03-Consumables

*The Kitchen can create random Consumables*  
On souhaite que la classe Kitchen puisse créer des instances de Consumables utilisant les Ingredients précédement enregistrés.
Vous pouvez regarder la documentation de `<random>` pour comprendre comment générer des éléments aléatoires.

### Tests-04-Cupboard

*The Kitchen contains a Cupboard*  
On vérifie que la classe `Kitchen` dispose d'un accesseur `get_cupboard()`.
Attention à retourner le type attendu.

*Consumables can be stored in the Kitchen's Cupboard*  
Vous devez ajouter une fonction `Kitchen::store_in_cupboard`.

*When time passed, the Consumable gets closer to its expiration date*  
La fonction `Kitchen::wait` sert à décrémenter la durée de validité du Consommable.
Attention, cette valeur ne peut pas descendre en dessous de 0.

*We can query the total quantity of a specific ingredient*  
Pour ce test, essayez d'utiliser la fonction `std::accumulate`.

*We can compute the total quantity of Consumables verifying a predicate*  
Il faut ajouter un deuxième overload à la fonction `Kitchen::compute_quantity`.
Si vous avez oublié comment faire pour envoyer une lambda en paramètre à une fonction, retournez voir le cours.

*The Kitchen can be tied up*  
Essayez encore une fois d'utiliser les fonctions de la librairie standard pour faire ces changements.

### Tests-05-Recipes

*Recipes can be registered in the Kitchen*  
Similaire aux autres fonctions `Kitchen::register_XXX`.

*The Kitchen can compute the list of missing Ingredients for a given Recipe*  
Essayez d'utiliser les fonctions implémentées précédemment, ainsi que `std::transform`.

*The Kitchen provides the list of Recipes that required only available Ingredients*
N'hésitez pas à ajouter des fonctions intermédiaires à la classe `Kitchen` pour décomposer les étapes.
