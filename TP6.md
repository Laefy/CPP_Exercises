TP6 - Héritage :
=================

Le but de ce TP est d'implémenter les classes permettant de représenter en mémoire un document JSON (JavaScript Object Notation).
Des exemples de fichiers au format JSON sont donnés dans le répertoire `json`.

Nous utiliserons à nouveau le framework de test Catch2 pour les tests unitaires.

Mise à jour du dépôt
---------------------------

Vous allez devoir récupérer les sources du TP6 sur votre dépôt local.

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

3. Récupérez les derniers changements du dépôt d'origine, placez-vous sur la branche tp6 et pushez-la sur votre fork :
```b
git fetch upstream
git switch tp6
git push -u origin tp6
```

1. Si vous ne l'avez pas fait précédemment, mettez à jour vos sous-modules afin de télécharger la librairie Catch2.
```c
git submodule init
git submodule update
```

1. Supprimez le répertoire `build/` pour être sûr de repartir sur de bonnes bases.

2. Si pour une raison quelconque, votre branche tp6 se retrouve toute cassée, vous pouvez la réinitialiser avec :
```b
# Assurez vous que vous êtes bien sur la branche tp6.
git status
# Réinitialiser la branche courante pour la faire pointer sur upstream/tp6. Attention, vous perdrez tous les changements faits sur cette branche.
git reset --hard upstream/tp6


Documents JSON
-----------------

Un document JSON est une façon légère de représenter des données. Voici un exemple (fichier `json/cpp2022.json`):
```json
{
  "name": "C++",
  "level": "M1",
  "year": 2023,
  "teachers": ["Céline", "Clément", "Christophe", "Victor", "Youssef"],
  "grading": [
    { "name": "TP noté 1", "aboutChapters": [0,1,2,5] },
    { "name": "TP noté 2", "aboutChapters": [0,1,2,3,4,5] },
    { "name": "Exam", "aboutChapters": "all" }
  ]
}
```

Une **valeur JSON** est soit:
2. un *entier*, par exemple `2023`;
3. une *chaîne de caractère*, par exemple `"C++"`;
4. une *liste* de valeurs JSON, délimitées par `[`...`]` et séparées par des virgules, par exemple `["Céline", "Clément", "Christophe", "Victor", "Youssef"]`; 
5. un *dictionnaire*, noté entre `{`...`}`, qui associe des clefs (chaîne de caractères avant le `:`) à des valeurs JSON (après le `:`), par exemple `{ "name": "Exam", "aboutChapters": "all" }` associe la clef `"name"` à la valeur `"TP noté 1"` et la clef `"aboutChapters"` à la valeur `[0,1,2,5]` 

Notez qu'on ne suppose aucune cohérence particulière de typage. Par exemple les valeurs JSON dans une liste peuvent être de types différents, par exemple 
```json
[true, "hello", {"name": "Céline", "surname":"Noël" }]
``` 
est une valeur JSON valide.

Un document JSON est simplement un fichier qui contient une valeur JSON, usuellement un dictionnaire. 
Des exemples de document JSON se trouvent dans le dossier `json`; pour la plupart, ce sont de petits exemples qu'on utilisera pour les tests.  Au contraire, le document `json/pokedex.json` est représentatif de ce à quoi ressemble un document JSON réel, et sera utilisé dans les tests plus avancés.


Arbres
-------

Un document JSON peut être représenté par un arbre :
- les entiers et chaînes de caractères sont des feuilles de l'arbre.
- les listes et les dictionnaires sont des noeuds internes et ont pour fils chacune des valeurs à l'intérieur.

Par exemple, le document donné en début de TP se représente:
![Représentation du document json `cpp2023.json`](example_cpp2023_as_image.svg)


Représentation en mémoire
--------------------------

Un document JSON sera représenté en mémoire comme un arbre dont les noeuds sont polymorphes :
- La classe `Node` sera la classe-mère permettant de représenter tout élément de l'arbre dont on ne connaît pas le type exact. Elle sera abstraite.
- Les classes `IntLeaf` et `StringLeaf` représentent les deux types de feuilles de l'arbre, suivant le type de la donnée portée. Elles hériteront d'une classe abstraite `Leaf` qui héritera elle-même de `Node`.
- Les classes `ArrayNode`, `ObjectNode` représenteront les deux types de noeuds internes.
- Le type `std::unique_ptr<Node>` sera utilisée pour pointer vers les enfants d'un noeud interne. Il sera utilisé en interne pour stocker les enfants des `ArrayNode` et `ObjectNode`.  De cette manière, quand un `ArrayNode` est détruit, ses enfants le seront aussi.
- Le type `NodeKind` est fourni, c'est une `enum` listant les différents types de noeuds. A l'exécution, il sera utilisé par les `Node`'s pour indiquer leur type réel.

Pour les tests supérieurs à 20, un parseur JSON sera utilisé. Il est fourni (classe `JsonParser`) et vous n'avez pas à le modifier.


Tests
------

Quelques remarques préliminaires.
- Les tests inférieurs à 30 doivent être faits dans l'ordre, ensuite vous pouvez faire les 3X et 4X indépendamment.
- Le fichier `sandbox.cpp` est à votre disposition. Ce qu'il contient sera compilé et exécuté en sélectionnant `sandbox` dans les listes.
- Essayez de factoriser au maximum le code en écrivant, quand c'est possible, le corps des fonctions dans `Node` ou `Leaf`.
- Essayez de vous demander à chaque fois si une fonction doit être virtuelle ou pas.


Voici une courte description des tests:

- Le test 01 vous demande de créer une classe `Node` qui hérite de `InstanceCounter`.  La classe `InstanceCounter` est fournie et ne sert qu'à compter le nombre d'objets `Node` en mémoire.  Ainsi, on peut vérifier qu'on a pas de fuite mémoire.

- Le fichier `routine_memory_check` contient un `TEST_CASE` qui vérifie que tous les `Node` ont été correctement désalloués; il est systématiquement `#include` à la fin de chaque fichier de test.

- Les tests 02 à 03 demandent de créer les classes `IntLeaf` et `StringLeaf` qui correspondent aux deux types de feuille.  
  Ils devront tous deux
  * hériter du type `Leaf`
  * hériter d'une fonction-membre `Node::print()`, qui est virtuelle pure dans `Node`.
  * avoir un constructeur qui prend un argument le type approprié (par exemple `IntLeaf::IntLeaf(int)`), il s'agit de la donnée portée par la feuille.
  * avoir une fonction-membre `data()` pour accéder à la donnée portée.  Cette fonction ne sera pas une fonction virtuelle héritée de `Node` puisque `IntLeaf::data()` et `StringLeaf::data()` ont des signatures incompatibles.

- Les tests 04 et 05 demandent de créer les classes `ArrayNode` et `ObjectNode`.
  * Elles devront implémenter la fonction-membre `print()`.
  * Elles ont un constructeur par défaut (par exemple `ArrayNode::ArrayNode()`) qui crée un noeud sans enfants.

- Le test 06 demande de rajouter une fonction-membre `NodeKind Node::kind()` qui **n'est pas virtuelle**.

Dorénavant, nous n'indiquerons pas si les fonction-membre doivent être virtuelle ou non. Réfléchissez-y et demandez à votre chargé de TP en cas de doute.

- Le test 10 demande, pour chaque type de noeud, une fonction-membre statique `make_ptr(..)` (par exemple `StringLeaf::make_ptr(std::string)`) qui permet de créer un pointeur vers un nouveau noeud.
*(En temps normal, il faudrait rendre tous les constructeurs `protected` et obliger les utilisateur à utiliser `make_ptr` pour construire des `Node`; nous ne le ferons pas ici pour que les tests continuent de passer.)*

- Les tests 11 et 12 demandent de créer les fonctions-membre de `ArrayNode` et `ObjectNode` pour pouvoir leurs ajouter de nouveaux enfants. 

- Le test 13 vérifie que la classe `ObjectNode` implémente bien un dictionnaire, c'est-à-dire qu'il n'aura pas plusieurs enfants associés à la même clef.

 Les tests 21 et 22 demandent de rajouter les deux fonctions-membre suivantes:
  * `node_count()` qui renvoie le nombre de noeuds dans l'arbre JSON représenté dans `this`.
  * `height() ` qui renvoie la hauteur de l'arbre JSON représenté dans `this`.
  Ces fonction-membres serviront par la suite à vérifier que les arbres JSON construits semblent corrects.

- Les tests 22 à 25 consistent à parser les documents JSON du répertoire json et vérifier que votre représentation en mémoire est correcte.

- Les tests 30 à 33 demandent d'écrire des fonctions-membre (par exemple `as_StringLeaf`) pour caster un `Node` dans une de ses classes filles (par exemple en `StringLeaf`).  Pour éviter la duplication de code, il vaut mieux dans ce cas que `Node::as_Stringleaf()` ne soit pas virtuelle pure !

- Le test 34 demande d'écrire une des trois fonctions-membre (voir test 37) pour pouvoir naviguer dans un arbre JSON.  Il s'agit d'ajouter une fonction-membre à `ArrayNode` pour pouvoir accéder à ses enfants.

- Le test 35 vérifie que l'insertion d'un nouveau Pokémon dans le `pokedex.json` se passe correctement.

- Le test 36 demande d'écrire la deuxième fonction-membre pour pouvoir naviguer dans un arbre JSON.  Il s'agit d'ajouter les fonctions-membres nécessaires pour pouvoir effectuer une boucle *for each* sur un `ArrayNode`.

- Le test 37 vérifie que la navigation se passe bien. Il s'agit de parcourir le `pokedex.json` et de construire des dictionnaires qui associent au nom d'un Pokémon son numéro dans le Pokédex.

- Le test 38 vérifie qu'on peut naviguer dans un arbre JSON lorsqu'il est const.  Ce test demande de "dupliquer" la plupart des fonctions-membres écrites pour les tests 3X, sans quoi le test 35 ne passera pas correctement.

- Le test 40 demande d'écrire un opérateur pour tester l'égalité entre deux Nodes.

- Le test 41 demande d'écrire une fonction permettant de copier un arbre JSON.


