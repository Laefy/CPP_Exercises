#include <iostream>
#include <utility>

int main()
{
    // A1. Décommentez l'instruction ci-dessous pour vérifier que le programme compile.
    // => "Debut des tests"
    // std::cout << "Debut des tests" << std::endl;
    // std::cout << std::endl;

    // A2. Par défaut, un CopyablePtr est null.
    // => "null_ptr is null"
    // CopyablePtr null_ptr;
    // std::cout << "null_ptr is " << (null_ptr == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // A3. On instancie un CopyablePtr avec la valeur 4.
    // => "Object #0 [[ 4 ]] has been created"
    // => "ptr_0 is not null"
    // CopyablePtr ptr_0 { 4 };
    // std::cout << "ptr_0 is " << (ptr_0 == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // A4. On déréférence pour récupérer l'Object stocké dans le pointeur.
    // => "Object #0 [[ 4 ]]"
    // const auto& obj_0 = *ptr_0;
    // std::cout << obj_0 << std::endl;
    // std::cout << std::endl;

    // A5. On assigne nullptr à ptr_0.
    // => "Object #0 [[ 4 ]] has been destroyed"
    // => "ptr_0 is null"
    // ptr_0 = nullptr;
    // std::cout << "ptr_0 is " << (null_ptr == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // B1. On crée un nouveau pointeur et on le copie.
    // => "Object #1 [[ 5 ]] has been created"
    // => "Object #1 [[ 5 ]] has been copied into Object #2 [[ 5 ]]"
    // CopyablePtr ptr_1 { 5 };
    // CopyablePtr ptr_1_copy = ptr_1;
    // std::cout << std::endl;

    // B2. On vérifie que l'on peut aussi copier un pointeur null.
    // => "null_ptr_copy is null"
    // CopyablePtr null_ptr_copy = null_ptr;
    // std::cout << "null_ptr_copy is "<< (null_ptr == nullptr ? "null" : "not null")  << std::endl;
    // std::cout << std::endl;

    // B3. On déplace ptr_1 dans un nouveau pointeur.
    // => "ptr_1 is null"
    // => "ptr_2 is not null"
    // => "Object #1 [[ 5 ]]"
    // CopyablePtr ptr_2 = std::move(ptr_1);
    // std::cout << "ptr_1 is "<< (ptr_1 == nullptr ? "null" : "not null")  << std::endl;
    // std::cout << "ptr_2 is "<< (ptr_2 == nullptr ? "null" : "not null")  << std::endl;
    // std::cout << *ptr_2 << std::endl;
    // std::cout << std::endl;

    // C1. On réassigne à ptr_0 le contenu de ptr_2 par copie.
    // => "Object #1 [[ 5 ]] has been copied into Object #3 [[ 5 ]]"
    // ptr_0 = ptr_2;
    // std::cout << std::endl;

    // C2. On vérifie que l'instance contenue dans ptr_2 est bien détruite avant la copie.
    // => "Object #1 [[ 5 ]] has been destroyed"
    // => "Object #3 [[ 5 ]] has been copied into Object #4 [[ 5 ]]"
    // ptr_2 = ptr_0;
    // std::cout << std::endl;

    // C3. On s'assure que réassigner ptr_2 à lui-même n'a pas d'effet.
    // => "Object #4 [[ 5 ]]"
    // ptr_2 = ptr_2;
    // std::cout << *ptr_2 << std::endl;
    // std::cout << std::endl;

    // D1. On déplace ptr_2 dans ptr_0.
    // => "Object #3 [[ 5 ]] has been destroyed"
    // => "ptr_2 is null"
    // => "ptr_0 is not null"
    // => "Object #4 [[ 5 ]]"
    // ptr_0 = std::move(ptr_2);
    // std::cout << "ptr_2 is "<< (ptr_2 == nullptr ? "null" : "not null")  << std::endl;
    // std::cout << "ptr_0 is "<< (ptr_0 == nullptr ? "null" : "not null")  << std::endl;
    // std::cout << *ptr_0 << std::endl;
    // std::cout << std::endl;

    // D2. On s'assure que réassigner ptr_0 à lui-même n'a pas d'effet.
    // => "Object #4 [[ 5 ]]"
    // ptr_0 = ptr_0;
    // std::cout << *ptr_0 << std::endl;
    // std::cout << std::endl;

    // E. On vérifie que tous les Objects alloués encore en vie sont correctement détruits.
    // => "Fin des tests"
    // => "Object #2 [[ 5 ]] has been destroyed"
    // => "Object #4 [[ 5 ]] has been destroyed"
    // std::cout << "Fin des tests" << std::endl;

    return 0;
}
