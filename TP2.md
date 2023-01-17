# TP2 - Utiliser la librairie standard

L'objectif de ce TP est de vous habituer à utiliser quelques classes et fonctions de la librairie standard.
Vous commencerez également à modulariser vos projets en séparant vos fonctions dans différents fichiers.

Nous allons vous faire implémenter un traducteur en ligne de commande.
Si vous bloquez, vous pourrez trouver des indices à la fin de l'énoncé pour vous aider à avancer. 
Et si vous bloquez toujours, vous pouvez consulter la branche tp2-solutions.

## 0- Mise à jour du dépôt

Vous allez devoir récupérer les sources du TP2 sur votre dépôt local.
Pour ce faire, exécutez les commandes suivantes :
```b
git remote add upstream https://github.com/Laefy/CPP_Exercises.git
git fetch upstream
git switch tp2
git push -u origin tp2
```

## 1- Sortie du programme

1. Pour le moment, votre traducteur ne fait rien du tout. Modifiez le code pour que si l'utilisateur entre 'q', 'quit', 'e' ou 'exit', le programme s'arrête.
2. Quel conteneur pouvez-vous utiliser pour savoir si un élément appartient à un ensemble d'éléments ? Implémentez une fonction `make_exit_commands` qui retourne un conteneur de ce type contenant les chaînes 'q', 'quit', 'e' et 'exit'.
3. Modifiez le code de votre fonction `main` afin d'utiliser le conteneur renvoyé par cette fonction pour sortir du programme.

## 2- Ajouter une traduction

1. Modifiez le programme pour que lorsque l'utilisateur entre la commande `add <w1> <w2>`, le programme affiche "`<w1>` => `<w2>`".
2. Si l'utilisateur entre ensuite la commande `translate <w1>`, le programme affiche `<w2>`. Si aucune traduction n'a été ajouté pour `<w1>`, alors le programme affiche `???` 
3. Modifiez la dernière commande pour que l'utilisateur puisse rentrer une phrase complète, c'est à dire une commande de la forme `translate <w1> <w2> etc`.  Chaque mot est traduit indépendamment.
4. Ajoutez la commande `print` permettant d'afficher l'intégralité du dictionnaire.

## 3- Sauvegarde et restauration

1. Ajoutez un conteneur séquentiel nommé `history`, qui contient la liste des instructions `add` entrées par l'utilisateur.
2. Implémentez une commande `save <name>` qui permet de sauvegarder l'historique des commandes `add` dans le fichier nommé `<name>`.
3. Implémentez ensuite la commande `load <name>` qui recharge la liste des instructions enregistrées dans `<name>` et les réapplique. Essayez de limiter la duplication de code.

## 4- Suppression

1. Ajoutez la commande `clear` qui permet de supprimer l'ensemble des traductions enregistrées.
2. Ajoutez également `remove <word>` qui permet de supprimer l'ensemble des traductions qui référencent `<word>` (en tant que clef ou valeur).

## 5- Traducteur polyglote

1. Modifiez le programme pour qu'il attende deux arguments sur la ligne de commande: la langue source et la langue cible du traducteur.  Par défaut, si aucun argument n'est fourni, la langue source sera "fr" et la langue cible "en". 
2. Ajoutez deux commandes `from <name>` et `to <name>` qui permettent de changer la langue source et la langue cible du traducteur. Les commandes précédentes s'appliquent toujours à la paire de langues actuellement sélectionnées.

**Notez que ces deux questions demandent de changer beaucoup de choses écrites précédemment car le programme doit garder en mémoire tous les dictionnaires pour toutes les langues, et la sauvegarde/restauration doit le gérer correctement.**

## Indices

1.3. La fonction `count` permet de savoir si un élément est présent dans certains conteneurs.

2.3. Vous pouvez utiliser `std::getline` et :
- soit `std::stringstream`,
- soit `std::string::split`.

3.2. Vous pouvez utiliser `std::ofstream`.

3.3. Vous pouvez extraire le contenu de la boucle principale dans une fonction pour réutiliser son code.

4.1. N'oubliez pas qu'il faut mettre à jour l'historique.

4.2. Attention à l'invalidation potentielle des itérateurs.

5.2. Afin de rendre votre programme plus lisible, vous pouvez définir des alias.
