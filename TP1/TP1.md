# TP1 - Premiers pas

L'objectif de ce premier TP est de vous familiariser avec un environnement de développement pour C++.\
On ne vous présentera pas énormément de notions du langage aujourd'hui, mais vous découvrirez l'utilisation d'outils vous permettant de développer dans de bonnes conditions.
Essayez de les prendre en main, d'explorer leurs interfaces, de vous familiariser avec raccourcis et commandes, de manière à pouvoir programmer et debugger efficacement par la suite.

## 1- Hello World

Le but de ce premier exercice est d'**écrire le code** d'un hello world et de **compiler** le programme.

### Définition du main

1. Créez un fichier texte et nommez-le helloworld.cpp.
2. Ouvrez-le dans un éditeur de texte comme VSCode.
3. Définissez une fonction ``main`` qui n'attend aucun paramètre et qui retourne 0.

### Compilation

Pour compiler le programme en ligne de commande, il faut utiliser le compilateur installé sur votre machine. Vous pouvez vous référer à [cette page](https://laefy.github.io/CPP_Learning/chapter0/1-compiler/) pour l'installation.

1. Ouvrez un terminal et placez-vous dans le répertoire contenant votre fichier helloworld.cpp.
2. Pour compiler un programme écrit en C++, la ligne de commande est la suivante :\
avec g++ => `g++ f1.cpp f2.cpp f2.cpp -o executable`\
avec clang => `clang++ f1.cpp f2.cpp f2.cpp -o executable`\
Adaptez cette ligne de commande pour compiler le ficher `helloworld.cpp` et créer un exécutable nommé hello-world.
3. Recompilez votre programme en ajoutant les options de compilation suivantes :\
`-std=c++17` => pour utiliser le standard C++17\
`-W -Wall -Wextra` => permet d'activer un certain nombre de warnings à la compilation\
`-Werror` => permet de transformer les warnings en erreurs à la compilation

### Affichage en console

Pour afficher du texte sur la sortie standard, on utilise l'instruction suivante :
```cpp
std::cout << "Plein de texte" << std::endl;
```

`std::cout` désigne la sortie standard.\
`std::endl` est un manipulateur qui permet d'ajouter un saut de ligne et de vider le buffer d'écriture (c'est-à-dire de déclencher l'écriture dans le flux de sortie).\
`<<` est un opérateur binaire, au même titre que `+` ou `%`, qui permet ici d'écrire du texte dans un flux de sortie.

Pour pouvoir utiliser cette instruction, il faut inclure le header `iostream`.
```cpp
#include <iostream>
```

1. Modifiez le programme de manière à écrire `"Hello world!"` suivi d'un retour à la ligne.
2. Compilez et testez le programme.

---

## 2- Outils

Afin de programmer dans de bonnes conditions, nous allons utiliser différents outils.

### IDE

Un IDE, ou environnement de développement intégré, est un programme dans lequel vous pouvez à la fois écrire vos programme, les compiler et les débugger.

1. Installez [VSCode](https://laefy.github.io/CPP_Learning/chapter0/2-vscode/) si ce n'est pas déjà fait.

### Générateur de fichiers de build

Il s'agit d'un outil destiné à générer les fichiers qui servent à la compilation d'un programme (les MakeFiles par exemple), indépendamment de votre système d'exploitation.

1. Installez [CMake](https://laefy.github.io/CPP_Learning/chapter0/3-cmake/) si ce n'est pas déjà fait, ainsi que les extensions associées pour VSCode.

### Versionning

Un outil de versionning peut adresser plusieurs besoins :
- suivre l'évolution du code;
- sauvegarder son état;
- travailler à plusieurs sur un projet;
- ...
  
1. Installez [Git](https://laefy.github.io/CPP_Learning/chapter0/4-git/) si ce n'est pas déjà fait, ainsi que les extensions associées pour VSCode.
2. Rendez-vous sur GitHub et créez-vous un compte si vous n'en avez pas déjà un.
3. Si vous n'avez pas encore de clef SSH, suivez les instructions sur [cette page](https://docs.github.com/fr/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent) pour la générer, puis sur [cette page](https://docs.github.com/fr/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account) pour l'ajouter à votre compte GitHub.

### Git en pratique

1. Forkez [ce dépôt](https://github.com/Laefy/CPP_Exercises) sur votre compte GitHub au moyen du bouton "Fork" situé en haut à droite de la page.
2. Clonez ensuite votre fork en local à l'aide de Git avec la méthode SSH :\
`git clone <git@github.com:url_depot.git>`
3. Ouvrez le dossier `CPP_Exercises/` dans VSCode.
4. Placez vous sur la branche `tp1`:
> avec la ligne de commande => `git switch tp1`\
> avec VSCode => onglet versionning, catégorie BRANCHES, sélectionnez tp1
5. Déplacez votre fichier `helloworld.cpp` dans le dossier `CPP_Exercices/TP1`.
6. Stagez le fichier `helloworld.cpp`:
> avec la ligne de commande => `git add TP1/helloworld.cpp`\
> avec VSCode => onglet versionning, catégorie SOURCE CONTROL, sélectionnez le petit `+` qui apparaît au survol du fichier.
7. Commitez le fichier avec le message "Adding hello world program.":
> avec la ligne de commande => `git commit -m "Adding hello world program."`\
> avec VSCode => onglet versionning, catégorie SOURCE CONTROL, tappez le message puis appuyez sur le bouton "Commit".

### CMake en pratique

1. Dans l'interface de VSCode, retournez dans l'onglet d'exploration des fichiers.
2. Ouvrez le fichier `CPP_Exercices/TP1/CMakeLists.txt`.
3. Pour compilez un exécutable `mon_executable` à partir des fichiers `f1.cpp`,`f2.cpp` et `f3.cpp`, il faut utilisez l'instruction `add_executable(mon_executable f1.cpp f2.cpp f3.cpp)`.\
Ajoutez l'instruction appropriée pour générer un exécutable hello-world à partir de votre fichier source.
4. Lancez la génération des fichiers de build en utilisant Ctrl(/Cmd)+Shift+P, puis en tappant `CMake: Configure`. Si VSCode vous demande un générateur, choisissez le GCC ou le Clang le plus récent.\
Un certain nombre de boutons devraient apparaître dans la barre bleu en bas de VSCode.
5. Cliquez sur le bouton Build pour lancer la génération de hello-world.
6. Suivez ensuite les instructions [ici](https://laefy.github.io/CPP_Learning/chapter0/3-cmake/#lancement-du-programme) pour lancer le programme pour la première fois.

---

## 3- Un peu d'interactivité

Vous allez modifier le programme afin qu'il vous demande votre nom avant de vous saluer.

### Debugger

1. Pour récupérer une valeur entrée par l'utilisateur depuis la ligne de commande dans une variable nommée `var`, il faut utiliser l'instruction suivante :\
`std::cin >> var;`\
Modifiez votre programme afin de récupérer une valeur de type `int` puis compilez.
2. Dans l'éditeur de votre fichier, passez le curseur sur la gauche des numéros de ligne. Vous devriez voir un petit point rouge apparaître. Cliquez sur la ligne où vous avez défini votre variable pour y ajouter un breakpoint. Ajoutez également un autre breakpoint sur l'instruction `return` du `main`. 
3. Lancez le programme en mode Debug en cliquant sur le bouton "Debug" (représenté par un insecte) situé à gauche du bouton "Play".
4. Le programme devrait se lancer et s'arrêter sur la ligne où vous avez placé le breakpoint. Vous devriez voir la valeur de votre variable sur la gauche de l'interface de VSCode.\
Avancez dans l'exécution du programme en appuyant sur la touche F10 ou en utilisant les boutons en haut de l'écran.
5. Dans le terminal en bas de VSCode, rentrez une valeur comme demandé par le programme. Le programme devrait à nouveau s'arrêter sur l'instruction `return` et vous devriez pouvoir constater que la valeur de votre variable a changé sur la gauche de VSCode.
6. Commitez vos changements. 

### Chaîne de caractères

Votre programme permet actuellement de récupérer un nombre entier.
Pour obtenir le nom de l'utilisateur, nous souhaiterions à la place stocker une chaîne de caractères.

1. Recherchez sur Internet quel type permet de représenter des chaînes de caractères en C++.\
Confirmez votre réponse avec votre chargé de TP et modifiez le type de votre variable.
2. Compilez et testez votre programme.\
Si vous avez des erreurs de compilation, vérifiez que vous avez bien inclus le header permettant d'utiliser les chaînes de caractères.
3. Modifiez une dernière fois le programme afin qu'il vous demande d'abord : "What's your name?" puis qu'il affiche "Hello <votre_nom>!"
4. Commitez vos changements.

---

## Conclusion

Vous trouverez ci-dessous les connaissances qu'il est attendu que vous ayiez acquises à la fin de la séance.
Tant que vous n'êtes pas parfaitement à l'aise avec elles, nous vous conseillons de continuer à vous entraîner sur ce TP.

### Langage

- Ecrire une fonction `main`
- Ecrire dans le flux de sortie standard `std::cout` (header: `<iostream>`)
- Ecrire un retour à la ligne avec `std::endl`
- Récuperer des valeurs depuis le flux d'entrée standard `std::cin` (header: `<iostream>`)
- Définir des chaînes de caractères avec <à compléter> (header: `<...>`)
 
### Méthodologie

#### Compilation

- Compiler en ligne de commande avec g++ ou clang++

#### Git

- Changez de branche avec git Stagez 