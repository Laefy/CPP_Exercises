# TP8 - Révisions

## Objectifs

- Découvrir le format des TPs notés
- Lancer les tests unitaires
- Revoir les différentes notions du cours

## Amorce de la séance

Avant le début de l'examen, on vous demandera de prendre place à vos machines, de vous connecter et d'exécuter le script Python `prepare_station.py` fourni.
Celui-ci servira à extraire les différents fichiers au bon endroit sur la machine et à lancer VSCode.

### Documentation

Vous aurez accès à différentes ressources pour vous débloquez si nécessaire pendant la séance :
- une version statique du cours en ligne,
- [une version statique de cppreference](/usr/share/cppreference/doc/html/en/),
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

Lorsqu'on utilise CMake, les fichiers sont générés dans un répertoire séparé des sources.  
Cela permet d'isoler le code, qui est portable et à vocation à être partagé, des fichiers que vous générez pour vous seul.

La première étape correspond à la configuration du projet, qui permet de référencer les exécutables à compiler et avec quelles options.  
Pour cela, vous pouvez soit utiliser la commande `CMake: Configure` de VSCode (accessible avec le raccourci `Ctrl + Shift + P`), soit lancer les commandes suivantes dans un terminal :
```b
# Créer le dossier qui contiendra les fichiers générés
mkdir build

# Rentre à l'intérieur du dossier `build`
cd build

# Configure le projet afin qu'il utilise le CMakeLists.txt dans `tp8` et place les fichiers générés dans `build`
cmake -S chemin/vers/le/dossier/tp8 -B .
```

Une fois la configuration terminée, compilez le framework de tests unitaires avec la commande suivante :
```b
cmake --build . --target Catch2WithMain -j
```

Enfin, vous pouvez compiler les tests et les exécuter à partir du script `run_tests.sh` généré dans votre dossier de build.
```b
# Lance la compilation et l'exécution de tous les tests unitaires
./run_tests.sh

# Lance la compilation et l'exécution des tests contenant le pattern donné
./run_tests.sh <pattern>

# Par exemple
./run_tests.sh ex2      # => tous les tests de l'exercice 2
./run_tests.sh ex2-1    # => exercice 2, tests 10 à 19
./run_tests.sh ex2-23   # => exercice 2, test 23 uniquement
```

Chaque fois que vous réussirez à faire passer un test unitaire, les fichiers-sources concernés seront sauvegardés dans le dossier [backup](backup).  
Ainsi, si vous vous rendez compte que vos dernières modifications ont cassé votre code, vous pourrez retrouver la dernière version fonctionnelle de vos fichiers dans ce dossier.

## Exercice 1 - Vrai ou Faux (30 min)

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

Si vous exécutez `./run_tests.sh ex1`, le test associé deviendra vert dès lors que vous aurez répondu à toutes les questions (même si vous avez mal répondu).

## Rappel

Dans les exercices 2 et 3, vous devez coder différentes classes et fonctions afin de faire passer les tests unitaires fournis.  
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

Dans un premier temps, il faut réussir à implémenter le code permettant au test de **compiler**.  
La seconde étape est d'adapter ce code afin qu'**il se comporte comme attendu** (c'est-à-dire que les conditions spécifiées dans les `REQUIRE` s'évaluent à `true`).

Pour résoudre un test (par exemple [ex2/tests/01-ptr-alias.cpp](ex2/tests/01-ptr-alias.cpp)), il faut créer les fichiers adéquats (par exemple `ex2/src/alias.hpp`) et y écrire le code pour que le test passe.

Une fois que vous pensez avoir terminé, utilisez `./run_tests.sh ex2-01` pour compiler et exécuter ce premier test.
Si vous avez réussi à le faire passer, passez au test suivant, etc.

### Conseils

1. Attention aux régressions ! Relancez régulièrement l'intégralité des tests de l'exercice avec `./run_tests.sh ex2` pour vous assurez que vos dernières modifications n'ont pas cassé un test qui passait précédement.
2. Ne restez pas bloqué trop longtemps sur la même question. La plupart des tests sont indépendants, donc n'hésitez pas à avancer et à revenir sur ceux qui vous posaient problème s'il vous reste du temps à la fin de la séance.


## Exercice 2 - Petit exercices sur la gestion de la mémoire (45 min)

Le test `ex2-01` demande de trouver deux types qui ont le comportement attendu. Il faut utiliser des alias et il est inutile de créer de nouvelles classes.

Les questions 1X de cet exercice reposent sur la classe [`InstanceCounter`](ex2/lib/InstanceCounter.hpp) qui est fournie.  Prenez le temps de bien lire le code cette classe avant de commencer à coder.  
Le but est de coder une classe `StringInstancePair` qui représente une paire (`std::string`, `InstanceCounter`) tout en satisfaisant un certain nombre de contraintes posées par les tests.


## Exercice 3 - Petit exercice sur l'héritage (45 min)

L'exercice 3 porte sur l'héritage.  On demande de créer une classe `Base` pet puis deux classes `DerivedInt` et `DerivedString` qui hérite de `Base`.

Là encore, les tests imposent des contraintes et le but est de trouver un moyen de les satisfaire dans les code des classes.
Vérifiez bien à chaque test que vous passez encore les tests précédents.
