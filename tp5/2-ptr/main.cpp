#include <iostream>
#include <utility>

void print_expected(const std::string& str)
{
    std::cout << "EXPECTED: " << str << std::endl;
    std::cout << "ACTUAL:   ";
}

int main()
{
    // // A1. Décommentez l'instruction ci-dessous pour vérifier que le programme compile.
    // std::cout << "Debut des tests" << std::endl;
    // std::cout << std::endl;

    // // A2. Par défaut, un CopyablePtr est null.
    // print_expected("null_ptr is null");
    // CopyablePtr null_ptr;
    // std::cout << "null_ptr is " << (null_ptr == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // // A3. On instancie un CopyablePtr avec la valeur 4.
    // print_expected("Object #0 [[ 4 ]] has been created");
    // CopyablePtr ptr_0 { 4 };
    // std::cout << std::endl;

    // print_expected("ptr_0 is not null");
    // std::cout << "ptr_0 is " << (ptr_0 == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // // A4. On déréférence pour récupérer l'Object stocké dans le pointeur.
    // print_expected("Object #0 [[ 4 ]]");
    // const auto& obj_0 = *ptr_0;
    // std::cout << obj_0 << std::endl;
    // std::cout << std::endl;

    // // A5. On assigne nullptr à ptr_0.
    // print_expected("Object #0 [[ 4 ]] has been destroyed");
    // ptr_0 = nullptr;
    // std::cout << std::endl;

    // print_expected("ptr_0 is null");
    // std::cout << "ptr_0 is " << (ptr_0 == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // // B1. On crée un nouveau pointeur et on le copie.
    // print_expected("Object #1 [[ 5 ]] has been created");
    // CopyablePtr ptr_1 { 5 };
    // std::cout << std::endl;

    // print_expected("Object #1 [[ 5 ]] has been copied into Object #2 [[ 5 ]]");
    // CopyablePtr ptr_1_copy = ptr_1;
    // std::cout << std::endl;

    // // B2. On vérifie que l'on peut aussi copier un pointeur null.
    // print_expected("null_ptr_copy is null");
    // CopyablePtr null_ptr_copy = null_ptr;
    // std::cout << "null_ptr_copy is " << (null_ptr == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // // B3. On déplace ptr_1 dans un nouveau pointeur.
    // print_expected("ptr_1 is null");
    // CopyablePtr ptr_2 = std::move(ptr_1);
    // std::cout << "ptr_1 is " << (ptr_1 == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // print_expected("ptr_2 is not null");
    // std::cout << "ptr_2 is " << (ptr_2 == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // print_expected("Object #1 [[ 5 ]]");
    // std::cout << *ptr_2 << std::endl;
    // std::cout << std::endl;

    // // C1. On réassigne à ptr_0 le contenu de ptr_2 par copie.
    // print_expected("Object #1 [[ 5 ]] has been copied into Object #3 [[ 5 ]]");
    // ptr_0 = ptr_2;
    // std::cout << std::endl;

    // // C2. On vérifie que l'instance contenue dans ptr_2 est bien détruite avant la copie.
    // print_expected("Object #1 [[ 5 ]] has been destroyed\n"
    //                "Object #3 [[ 5 ]] has been copied into Object #4 [[ 5 ]]");
    // ptr_2 = ptr_0;
    // std::cout << std::endl;

    // // C3. On s'assure que réassigner ptr_2 à lui-même n'a pas d'effet.
    // print_expected("Object #4 [[ 5 ]]");
    // ptr_2 = ptr_2;
    // std::cout << *ptr_2 << std::endl;
    // std::cout << std::endl;

    // // D1. On déplace ptr_2 dans ptr_0.
    // print_expected("Object #3 [[ 5 ]] has been destroyed");
    // ptr_0 = std::move(ptr_2);
    // std::cout << std::endl;

    // print_expected("ptr_2 is null");
    // std::cout << "ptr_2 is " << (ptr_2 == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // print_expected("ptr_0 is not null");
    // std::cout << "ptr_0 is " << (ptr_0 == nullptr ? "null" : "not null") << std::endl;
    // std::cout << std::endl;

    // print_expected("Object #4 [[ 5 ]]");
    // std::cout << *ptr_0 << std::endl;
    // std::cout << std::endl;

    // // D2. On s'assure que réassigner ptr_0 à lui-même n'a pas d'effet.
    // print_expected("Object #4 [[ 5 ]]");
    // ptr_0 = ptr_0;
    // std::cout << *ptr_0 << std::endl;
    // std::cout << std::endl;

    // // E. On vérifie que tous les Objects alloués encore en vie sont correctement détruits.
    // print_expected("Object #2 [[ 5 ]] has been destroyed\n"
    //                "Object #4 [[ 5 ]] has been destroyed");

    return 0;
}
