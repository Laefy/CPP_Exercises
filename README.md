# CPP_Exercises

Ce dépôt contient les sujets de TP pour les étudiants en Master d'informatique de l'Université Gustave Eiffel.

En cas de mise-à-jour du dépôt, vous pouvez récupérer la dernière version en suivant la procédure ci-dessous.

1. Exécutez `git status` pour vérifier que vous êtes sur `master` :
```b
git status
```

- Si vous êtes déjà sur `master`, passez à l'étape 2.
- Si vous n'êtes pas sur `master` :
    1. Si vous avez des changements sur votre branche, commitez-les :
    ```b
    git add .
    git commit -m "<votre message de commit>"
    ```
    2. Passez ensuite sur `master` :
    ```b
    git switch master
    ```

2. Une fois sur `master`, si vous avez des changements en local, vous pouvez les **remiser** (c'est-à-dire les mettre de côté pour les récupérer ensuite) :
```b
git stash
```

3. Récupérez ensuite les derniers changements :
```b
git pull --rebase
```
A cette étape, si vous avez des conflits et que vous ne savez pas comment les résoudre, appelez votre chargé de TP pour qu'il puisse vous montre comment faire.

4. Si vous avez remisé des changements à l'étape 2, ré-appliquez les avec :
```b
git stash pop
```

5. Vous êtes prêt à travailler !