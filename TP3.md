# TP3 - Définir des classes

Dans ce TP, vous verrez comment définir vos premières classes.

Le format sera un peu spécial : vous travaillerez en suivant la méthode TDD.
TDD signifie Test-Driven-Development.
Il s'agit d'une méthode de développement qui consiste à écrire le code appelant (généralement sous forme de tests unitaires) avant de commencer à écrire le code appelé.
Il est très efficace de développer de cette manière, car :
- on sait exactement où on souhaite aller,
- on ne code que ce dont on a vraiment besoin,
- on détecte très vite les régressions.

Nous vous présenterons brièvement le framework de tests et comment lancer les tests unitaires. L'objectif sera ensuite de faire passer les tests unitaires que nous vous avons (très généreusement) fourni afin que vous puissiez travailler sur le sujet principal de ce TP : définir des classes.

---

## 0- Mise à jour du dépôt

Vous allez devoir récupérer les sources du TP3 sur votre dépôt local.

1. Commencez par vous assurez que vous n'avez pas de changements en cours sur votre branche courante.
```b
git status
```
Si vous avez des modifications, commitez-les :
```b
git add .
git commit -m "Saved changes."
```

2. Si vous ne l'avez pas fait au TP2, ajoutez le dépôt d'origine en tant qu'upstream de votre dépôt local :
```b
git remote add upstream https://github.com/Laefy/CPP_Exercises.git
```

3. Récupérez les derniers changements du dépôt d'origine, placez-vous sur la branche TP3 et pushez-la sur votre fork :
```b
git fetch upstream
git switch tp3
git push -u origin tp3
```

4. Mettez à jour vos sous-modules afin de télécharger la librairie Catch2.
```c
git submodule init
git submodule update
```

5. Supprimez le répertoire `build/` pour être sûr de repartir sur de bonnes bases.

6. Si pour une raison quelconque, votre branche tp3 se retrouve toute cassée, vous pouvez la réinitialiser avec :
```b
# Assurez vous que vous êtes bien sur la branche tp3.
git status
# Réinitialiser la branche courante pour la faire pointer sur upstream/tp3. Attention, vous perdrez tous les changements faits sur cette branche.
git reset --hard upstream/tp3
```

---

## 1- Lancement de tests unitaires

### A - Utilisation de l'onglet Testing

1. Pour visualiser l'ensemble de vos tests unitaires, installez l'extension VSCode "CMake Test Explorer".
![](doc/cmake-test-explorer.png?raw=true)

2. Relancez VSCode, sélectionnez l'onglet des tests et rechargez les tests unitaires.
![](doc/testing-tab.png?raw=true)

3. Si vous obtenez le message "Cmake: Error", reconfigurez votre projet avec `CMake: Configure` (Ctrl+Shift+P), puis rechargez une fois de plus les tests unitaires afin d'obtenir l'affichage ci-dessous.
![](doc/reload-tests.png?raw=true)

4. Si ça ne fonctionne toujours, relancez une fois de plus VSCode...

5. Compilez maintenant l'ensemble du projet après avoir sélectionner la cible "all".
![](doc/build-all.png?raw=true)

6. Rechargez une fois de plus les tests unitaires. Les tests 00 devraient maintenant apparaître.
![](doc/test-00.png?raw=true)

7. Vous pouvez désormais lancer les tests avec le bouton Play.
![](doc/run-tests.png?raw=true)

### B - Définition de tests avec Catch2

1. Dans l'onglet Testing, sélectionnez le "Test 00 - 4" qui ne passe pas. Lisez le résultat affiché sur la sortie VSCode.
![](doc/result-2.png?raw=true)
Dans la console, vous pouvez constater que l'un des test cases a échoué.\
Ici, il est indiqué que le test "Test 00 - 4. 0+0 = la tete à Toto." ne s'est pas déroulé correctement, car l'assertion "0 + 0 == toto" était fausse.\
Sur la ligne juste en-dessous, on vous indique que l'expression "0 + 0" valait 0, tandis que l'expression "toto" valait 1.

2. Maintenez Ctrl et cliquez sur le lien permettant d'accéder à l'assertion qui a échoué.
![](doc/goto.png?raw=true)

3. Prenez connaissance du fichier qui vient de s'ouvrir.
![](doc/failed.png?raw=true)
Dans ce TP, nous utilisons le framework Catch2 pour définir les tests unitaires. Chaque test est introduit par l'utilisation de la macro TEST_CASE, à laquelle une chaîne de caractères est fournie permettant de décrire le test.\
La macro REQUIRE permet de définir les assertions, c'est-à-dire les conditions que les tests permettent de vérifier.

1. Modifiez le contenu du test case "Test 00 - 4" afin que celui-ci passe, compilez à l'aide du bouton Build, puis relancez le test depuis l'onglet Testing.
Vous devriez obtenir ce résultat :
![](doc/success.png?raw=true)

---

## 2- Vente de peluches

Le but de l'exercice est de définir des classes en rapport avec la vente de peluches (oui, c'est niais, mais je m'en fiche, j'aime bien les trucs niais).

Les tests unitaires vous serviront de guide pour comprendre ce que vous implémentez et comment.\
**Vous ne devez SURTOUT pas changer le code des tests !**\
**Interdit ! INTERDIT ! IN-TER-DIT !!!**

Les fichiers à modifier se trouvent dans le dossier src/ et **uniquement** dans le dossier src/.

### A - Comprendre l'erreur

1. Dans l'onglet Testing, vous pouvez constater que le \[test-01\] n'a pas pu être compilé.\
Sélectionnez la target de Build \[test-01\] et compilez-la.
![](doc/error.png?raw=true)\
L'erreur indique que le symbole 'Plush' n'est pas défini.\
Maintenez Ctrl et cliquez sur le lien pour ouvrir le fichier de tests dans lequel l'erreur s'est produite.

1. Dans ce fichier, il n'y a qu'un seul test case, qui demande simplement à ce qu'on puisse instancier une classe appelée "Plush".
![](doc/test-case.png?raw=true)\
Ouvrez le fichier 'Plush.hpp' et définissez une classe Plush.

1. Compilez à nouveau.\
Si cela ne fonctionne pas, relisez **attentivement** ce que le compilateur vous dit, demandez à Google, et recompilez encore et encore.\
En dernier recours, demandez de l'aide à votre chargé de TP.

1. Une fois la compilation réussie, rechargez la liste des tests unitaires. Le test 01 devrait maintenant apparaître.
![](doc/test-01.png?raw=true)

1. Lancez-le pour vérifier qu'il s'exécute sans erreur. Commitez vos changements et passez à la suite.

### B - Synthèse de la méthode

Pour récapituler, voici les étapes à suivre pour ce TP :
- choisir un test à compiler,
- tant qu'il ne compile pas :
  - **prendre connaissance du test-case et des instructions qui ne compilent pas**,
  - ajouter ou modifier le code situé dans src/,
  - recompiler,
- recharger la liste des tests depuis l'onglet Testing,
- lancer le test
- tant qu'il y a des erreurs à l'exécution :
  - **prendre connaissance des assertions qui ne passent pas**,
  - ajouter ou modifier le code situé dans src/,
- une fois que le test passe, commitez vos changements.

### C - Les peluches, ça coute des sous

1. Le test-02 consiste à implémenter une fonction get_cost() et à faire en sorte que celle-ci renvoie 10 lorsqu'on vient d'instancier une peluche.
2. Le test-03 permet de s'assurer que la fonction get_cost() peut être appelée sur un objet marqué const.
3. Le test-04 vous demande d'implémenter une fonction set_cost() qui attend un entier, et le retourne lors de l'appel à get_cost.

### D - Régressions.....

Une régression désigne un bug introduit dans une fonctionnalité existante suite à l'ajout d'une autre fonctionnalité. En général, cela arrive lorsqu'on refactore du code pour rendre un système plus générique et l'utiliser ailleurs.

1. Faites passer le test-05.
2. Lancez la commande `CMake: Clean Rebuild` (Ctrl+Shift+P), puis rafraichissez ensuite la liste des tests unitaires.
3. A moins que vous ne soyiez très malins, vous devriez observer que les tests 01 à 04 ne compilent plus.
Corrigez les erreurs et vérifiez que l'ensemble des tests passent à nouveau.\
**Rappel : vous ne devez pas modifier le code des tests unitaires.**

Conclusion : Le plugin CMake Test Explorer n'étant hélas pas optimal, il faudra de temps en temps lancer la commande `CMake: Clean Rebuild` et rafraichir la liste des tests unitaires pour vous assurez qu'ils compilent tous encore correctement.

### E - Magasin de peluches

1. Ajoutez le code nécessaire dans le fichier `PlushStore.hpp` pour faire compiler et passer les tests 06 à 10.\
**Indice : Le principe du TDD, c'est qu'on code le minimum pour faire fonctionner les tests. Vous n'avez donc pas besoin d'instancier la classe Plush pour coder les fonctions demandées ici.**
1. Exécutez la commande `CMake: Clean Rebuild` et relancez tous les tests dans l'onglet Testing pour vous assurez que vous n'avez pas de régressions.

### F - Vente de peluches

1. Faites maintenant le nécessaire pour faire passer les tests 11 à 14. Si vous bloquez sur un test, passez au suivant et revenez sur celui qui vous pose problème plus tard.
2. Exécutez la commande `CMake: Clean Rebuild` et relancez tous les tests dans l'onglet Testing pour vous assurez que vous n'avez pas de régressions.


