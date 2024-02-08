# TP4 - Révisions

## Objectifs

- Découvrir le format des TPs notés
- Utiliser le Test Explorer de VSCode
- Revoir les différentes notions du cours 

## Amorce de la séance

Avant le début de l'examen, on vous demandera de prendre place à vos machines, de vous connecter et d'exécuter une commande qui servira à extraire les différents fichiers au bon endroit sur la machine.

Une fois l'examen commencé, vous pourrez double-cliquer sur le fichier `${HOME}/launch_vscode.sh` pour ouvrir le dossier du TP noté dans VSCode.  
Si à un moment, vous devez réouvrir VSCode, passez toujours par le script `${HOME}/launch_vscode.sh`.
Cela vous évitera les **lags habituels du mode exam** ainsi que d'autres soucis de configuration.

### Documentation

Vous aurez accès à différentes ressources pour vous débloquez si nécessaire pendant la séance :
- une version statique du cours en ligne,
- [une version statique de cppreference](../resources/cppreference),
- [les slides du cours magistral](../resources/slides).

### Contenu du dossier

Le dossier du TP noté sera extrait dans `${HOME}/EXAM/`.

Il sera structuré à peu près de la même manière que le dossier de ce TP4.
- `cmake`: un dossier contenant des fichiers de configuration pour CMake
- `exN`: le code de l'exercice n°N
  - `src`: **les fichiers de code que vous devrez modifier**
  - `tests`: les fichiers contenant les **tests unitaires** à faire passer
- `extern`: contient des librairies externes, notamment la librairie Catch2 pour les tests unitaires
- `CMakeLists.txt`: le fichier de configuration pour CMake
- `TPNx.md` ou `TPNx.pdf`: le sujet du TP

Tous les fichiers que vous aurez **à modifier ou à ajouter** se trouvent dans **`src`**.  
Vous devrez aller consulter le contenu de `tests`, mais il ne faudra en aucun cas modifier les fichiers.  
Si vous arrivez à faire passer un test en le réécrivant, vous n'aurez pas les points !

Ne vous préoccupez pas du restant des fichiers, ils sont là pour faire en sorte que tout fonctionne.

## Compilation et exécution

Commencez par vous assurez-que vous avez ouvert VSCode à la racine du dossier `tp4`.  
Si ce n'est pas le cas, réouvrez-le.
![](images/open-right-folder.png)

TODO: expliquer la compilation

Chaque fois que vous réussirez à faire passer un test unitaire, les fichiers-sources concernés seront sauvegardés dans le dossier ["backup"](backup).  
Ainsi, si vous vous rendez compte que vos dernières modifications ont cassé votre code, vous pourrez retrouver la dernière version valide de vos fichiers dans ce dossier.

## Exercice 1 - Vrai ou Faux (20 min)

Le premier exercice est un vrai ou faux.

Ouvrez le fichier [ex1/src/qcm.hpp](ex1/src/qcm.hpp).  
Vous devez indiquer pour chaque proposition si celle-ci est vraie (`true`) ou fausse (`false`).  
Attention, une réponse incorrecte peut vous retirer des points, donc laissez le champ vide si vous ne savez pas.

Par exemple, si je sais que Victor a les cheveux courts, que Céline a les cheveux longs, mais que je ne sais pas pour Antoine, je réponds :
```cpp
// Question 1
// Victor a les cheveux longs.
#define ANSWER_1 false

// Question 2
// Céline a les cheveux longs.
#define ANSWER_2 true

// Question 3
// Antoine a les cheveux longs.
#define ANSWER_3
```

Si vous répondez à toutes les questions, le test `ex1-qcm` deviendra vert (même si vous avez mal répondu).

## Exercice 2 - Implémentation d'un répertoire téléphonique

Dans cet exercice, vous devrez coder différentes classes et fonctions afin de faire passer la série de tests unitaires proposés.  
Avec le framework Catch2, les tests unitaires ont la forme suivante :
```cpp
TEST_CASE("Titre du test")
{
  // Des instructions...
  REQUIRE(/** une assertion **/);

  // D'autres instructions...
  REQUIRE(/** une autre assertion **/);
}
``` 
Dans un premier temps, il faut réussir à implémenter le code permettant au test de compiler.  
La seconde étape est d'adapter le code afin qu'il se comporte comme attendu (c'est-à-dire que les conditions spécifiées dans les `REQUIRE` s'évaluent à `true`).

Ouvrez le premier fichier de tests [ex2/tests/test1.cpp](ex2/tests/test1.cpp).  
Le but est de définir une classe `PhoneNumber`, qui servira à représenter un numéro de téléphone.  
Ajoutez le fichier requis par le test et implémentez son contenu.




Attention aux régressions ! Relancez régulièrement l'intégralité des tests pour vous assurez que vos dernières modifications n'ont pas cassé un test qui passait précédement.

## Exercice 3 - Code à trous


## Exercice 4 - Utilisation de la librairie standard


