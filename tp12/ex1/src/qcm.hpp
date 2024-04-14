////////////////////////////////////////////////////////////////////////////////////////
//
// Vous devez indiquer si chacune des propositions est vraie (true) ou fausse (false).
//
// Exemple : Le C++ est le meilleur langage de tous les temps.
#define ANSWER_EX1 true
//                 ^^^^ indiquez votre réponse ici
//
// Exemple : Le Java est le meilleur langage de tous les temps.
#define ANSWER_EX2 false
//                 ^^^^^
//
////////////////////////////////////////////////////////////////////////////////////////

// Question 00
// Une std::map est un conteneur associatif dont l'indexation est réalisé au moyen d'une table de hashage. 
#define ANSWER_00

// Question 01 & 02
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
struct MyObject
{
    bool operator<(const MyObject& obj) const
    {
        return attr_1 < obj.attr_1;
    }

    std::string attr_1;
    int attr_2 = 0;
};
#endif

// Je peux définir et insérer une instance de MyObject dans un std::unordered_set<MyObject>.  
#define ANSWER_01

// Je peux définir et insérer une instance de MyObject dans un std::set<MyObject>.  
#define ANSWER_02

////////////////////////////////////////////////////////////////////////////////////////

// Question 10 -> 13
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
    auto vec = std::vector<int> { 0, 1, 2, 3, 4, 5 };
    auto it_v2 = std::next(vec.begin(), 2);
    auto it_v4 = std::next(vec.begin(), 4);
#endif

// L'instruction `vec.erase(it_v2);` invalide it_v2.
#define ANSWER_10

// L'instruction `vec.erase(it_v2);` invalide it_v4.
#define ANSWER_11

// L'instruction `vec.erase(it_v4);` invalide it_v2.
#define ANSWER_12

// L'instruction `vec.push_back(6);` invalide it_v4.
#define ANSWER_13

////////////////////////////////////////////////////////////////////////////////////////

// Question 20 -> 25
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
    auto list = std::list<int> { 0, 1, 2, 3, 4, 5 };
    auto it_l2 = std::next(list.begin(), 2);
    auto it_l4 = std::next(list.begin(), 4);
#endif

// L'instruction `list.erase(it_l2);` invalide it_l2.
#define ANSWER_20

// L'instruction `list.erase(it_l2);` invalide it_l4.
#define ANSWER_21

// L'instruction `list.erase(it_l4);` invalide it_l2.
#define ANSWER_22

// L'instruction `list.push_back(6);` invalide it_l4.
#define ANSWER_23

// L'instruction `list.insert(it_l2, 6);` invalide it_l2.
#define ANSWER_24

// L'instruction `list.insert(it_l2, 6);` invalide it_l4.
#define ANSWER_25

////////////////////////////////////////////////////////////////////////////////////////

// Question 30
// La lambda `[](const std::string& v) { return v + v; }` a pour type std::function<std::string(const std::string&)>.
#define ANSWER_30

// Question 31
// Une lambda est un foncteur.
#define ANSWER_31

// Question 32
// La capture d'une lamda correspond aux attributs de l'objet associé.
#define ANSWER_32

// Question 33
// On écrit [value&] pour capturer `value` par référence. 
#define ANSWER_33

// Question 34
// On écrit [*value] pour capturer `value` par valeur.
#define ANSWER_34

// Question 35
// On écrit [v = std::move(value)] pour déplacer `value` dans la capture.
#define ANSWER_35

////////////////////////////////////////////////////////////////////////////////////////

// Question 40
// Une classe-template est un type.
#define ANSWER_40

// Question 41
// Si Type est un paramètre de template, alors Type&& est une r-value reference de Type. 
#define ANSWER_41

// Question 42
// On peut spécialiser partiellement une fonction.
#define ANSWER_42

// Question 43
// Lorsqu'on définit une spécialisation totale, il faut commencer par écrire `template <>`.
#define ANSWER_43

// Question 44
// Il est préférable de définir les fonctions-templates et les types-templates dans les
// headers pour éviter les erreurs de compilation.
#define ANSWER_44
