# TP5 - Héritage statique

Dans ce TP, vous travaillerez l'héritage dit "statique" (c'est-à-dire sans utiliser de fonction virtuelle).
Ce type d'héritage sert principalement à éviter la duplication de code.

Nous utiliserons à nouveau le framework de test Catch2 pour les tests unitaires.

---

## 0- Mise à jour du dépôt

Vous allez devoir récupérer les sources du TP5 sur votre dépôt local.

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

3. Récupérez les derniers changements du dépôt d'origine, placez-vous sur la branche tp5 et pushez-la sur votre fork :
```b
git fetch upstream
git switch tp5
git push -u origin tp5
```

1. Si vous ne l'avez pas fait précédemment, mettez à jour vos sous-modules afin de télécharger la librairie Catch2.
```c
git submodule init
git submodule update
```

1. Supprimez le répertoire `build/` pour être sûr de repartir sur de bonnes bases.

2. Si pour une raison quelconque, votre branche tp5 se retrouve toute cassée, vous pouvez la réinitialiser avec :
```b
# Assurez vous que vous êtes bien sur la branche tp5.
git status
# Réinitialiser la branche courante pour la faire pointer sur upstream/tp5. Attention, vous perdrez tous les changements faits sur cette branche.
git reset --hard upstream/tp5
```

---

## 1- Yu-Gi-Oh!

Yu-Gi-Oh! est un jeu de cartes dans lequel deux adversaires s'affrontent.
Chacun d'entre eux disposent d'un deck de 60 cartes réparties sur trois types : les monstres, les sorts et les pièges.

Cet exercice consistera à modéliser quelques uns des éléments de ce jeu.

### A. Tests unitaires

Implémentez le code permettant de faire passer les tests présents dans le répertoire `tests/`.\
Si vous souhaitez ajouter d'autres fichiers sources, pensez à les ajouter également dans le `CMakeLists.txt`.

### B. Polymorphisme statique

Afin de faire passer les tests de fichier Test-9, il y a différentes manières d'implémenter la classe `Board` :
   - avec 1 seul conteneur de `std::unique_ptr<Card>`,
   - avec 3 conteneurs (1 par type de cartes),
   - sans stocker les cartes, en utilisant seulement des compteurs pour les cartes.

1. Chacune des méthodes ci-dessus présente des inconvénients. Identifiez-les.

**Avec 1 seul conteneur de `std::unique_ptr<Card>`**\
Si la classe n'est pas polymorphe, alors on peut avoir des fuites de mémoire, puisque les destructeurs des classes-filles ne seront pas correctement appelées.
Si la classe est polymorphe, alors on ajoute un appel virtuel à la destruction de chaque `std::unique_ptr<Card>`.

**Avec 3 conteneurs (1 par type de cartes)**\
On a de la redondance de code.

**Sans stocker les cartes, en utilisant seulement des compteurs pour les cartes**\
Les cartes sont détruites à la fin de l'appel à `put`, donc si des références ont été stockées avant, ces références ne sont plus valides ensuite.

2. Recherchez sur Internet des exemples d'utilisation du type `std::variant`. Modifiez votre code afin de stocker les cartes du `Board` dans un conteneur de `std::variant<...>`.

---

Céline Noël\
C++ Master 1\
2022 - 2023