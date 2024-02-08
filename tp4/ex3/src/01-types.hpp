///////////////////////////////////////////////////////////////////////////////////////
//
// Choisissez les types les plus appropriés pour que les fonctions puissent faire leur travail de la manière
// la plus sécurisée et optimisée possible.
// Attention donc aux copies inutiles sur les types coûteux à copier et à si la fonction est censée modifier
// le paramètre ou pas.
//
// Exemple
// get_char retourne un caractère
//  ANSWER_EX get_char();
#define ANSWER_EX char
//                ^^^^ -> indiquez votre réponse ici
//
///////////////////////////////////////////////////////////////////////////////////////

// Si vous devez ajouter des directives d'inclusion pour faire compiler le test, vous pouvez dupliquer et 
// décommenter la ligne ci-dessous.
// #include <...>

// Question 1
// stringify_integer convertit un entier en chaîne de caractères
//  ANSWER_1A stringify_integer(ANSWER_1B integer);
#define ANSWER_1A
#define ANSWER_1B

// Question 2
// count_nb_elements permet de retourner le nombre d'éléments présents dans un tableau dynamique
//  ANSWER_2A count_nb_elements(ANSWER_2B elements);
#define ANSWER_2A
#define ANSWER_2B

// Question 3
// WrappedString permet de stocker une chaîne et d'encapsuler ses accès en lecture et en écriture
// Pour le constructeur, vous devez indiquer le type du paramètre qui permettra d'intialiser _content:
//  WrappedString(ANSWER_3A initial_content)
#define ANSWER_3A
// La fonction get_readonly_content() doit donner un accès en lecture seule à _content
// ANSWER_3B get_readonly_content() ANSWER_3C { return _content; }
#define ANSWER_3B
#define ANSWER_3C
// La fonction get_readonly_content() doit donner un accès en lecture et écriture à _content
// ANSWER_3D get_modifiable_content() ANSWER_3E { return _content; }
#define ANSWER_3D
#define ANSWER_3E
