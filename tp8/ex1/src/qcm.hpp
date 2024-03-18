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

// 1. // ====================================================================================================
// Voici deux implémentations de constructeurs pour une classe Cat
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
class Human
{};

class Cat // Implémentation 1
{
public:
    Cat(std::vector<Human> o)
        : owners { std::move(o) }
    {}

private:
    std::vector<Human> owners;
};
class Cat // Implémentation 2
{
public:
    Cat(const std::vector<Human>& o)
        : owners { o }
    {}

private:
    std::vector<Human> owners;
};
#endif
// Est-ce que l'implémentation 1 est meilleure que l'implémentation 2?
#define ANSWER_1

// 2. // ====================================================================================================
// Voici deux implémentations de constructeurs pour une classe Dog
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
class Human
{};

class Dog // Implémentation 1
{
public:
    Dog(Human o)
        : owner { std::move(o) }
    {}

private:
    const Human& owner;
};
class Dog // Implémentation 2
{
public:
    Dog(const Human& o)
        : owner { o }
    {}

private:
    const Human& owner;
};
#endif
// Est-ce que l'implémentation 1 est meilleure que l'implémentation 2?
#define ANSWER_2

// 3. // ====================================================================================================
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
class AssocVector
{
public:
    void add_data(const std::string& key, const std::string& value)
    {
        keys.emplace_back(key);
        values.emplace_back(new std::string { value });
    }

private:
    std::vector<std::string> keys;
    std::vector<td::string*> values;
};
#endif
// Est-ce que l'utilisation de la classe ci-dessus est susceptible de créer des problèmes de mémoire (fuite,
// double-déallocation, etc.) ?
#define ANSWER_3

// 4. // ====================================================================================================
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
class AssocVector
{
public:
    void add_data(const std::string& key, const std::string& value)
    {
        keys.emplace_back(std::make_unique<std::string>(key));
        values.emplace_back(new std::string { value });
    }

    ~AssocVector()
    {
        for (auto a : values)
            delete a;
    }

private:
    std::vector<std::unique_ptr<std::string>> keys;
    std::vector<std::string*>                 values;
};
#endif
// Est-ce que l'utilisation de la classe ci-dessus est susceptible de créer des problèmes de mémoire (fuite,
// double-déallocation, etc.) ?
#define ANSWER_4

// 5. // ====================================================================================================
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
class AssocVector
{
public:
    void add_data(const std::string& key, const std::string& value)
    {
        keys.emplace_back(std::make_unique<std::string>(key));
        values.emplace_back(std::make_unique<std::string>(value));
    }

    ~AssocVector()
    {
        for (auto& a: values)
            delete a.get();
    }

private:
    std::vector<std::unique_ptr<std::string>> keys;
    std::vector<std::unique_ptr<std::string>> values;
};
#endif
// Est-ce que l'utilisation de la classe ci-dessus est susceptible de créer des problèmes de mémoire (fuite,
// double-déallocation, etc.) ?
#define ANSWER_5

// 1X. // ================================================================================================
// considère le code ci-dessous
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
int& f(int a, int& b)
{
    b = b + 1;
    return b
}
int g(int a, int& b)
{
    return (b + 1);
}
int main()
{
    int w = 99;                                        // ligne 0
    int x = 100;                                       // ligne 1
    int y = 101;                                       // ligne 2
    int z = 102;                                       // ligne 3
    std::cout << f(w, f(g(x + 1, y), z)) << std::endl; // ligne 4
}
#endif
// Dans les questions suivantes, on ne parle que de la ligne 4.
// 10. L'expression w est-elle une r-value?
#define ANSWER_10
// 11. L'expression 1 est-elle une r-value?
#define ANSWER_11
// 12. L'expression x+1 est-elle une r-value?
#define ANSWER_12
// 13. L'expression y est-elle une r-value?
#define ANSWER_13
// 14. L'expression g(x + 1, y) est-elle une r-value?
#define ANSWER_14
// 15. L'expression f(g(x + 1, y), z) est-elle une r-value?
#define ANSWER_15
// 16. L'expression f(w, f(g(x + 1, y), z)) est-elle une r-value?
#define ANSWER_16

// 2X. // ===================================================================================================
// On conside un programme avec deux classes, Fille et Mère, où Fille hérite de Mère.
// Les deux classes Fille et Mere possèdent une fonction-membre fct().
#ifdef CODE_IGNORE_PAR_LE_COMPILATEUR
int main()
{
    Mere* m = new Fille {}; // Ligne 1
    m->fct();               // Ligne 2
}
#endif
// 20. Si je veux redéfinir fct() dans Fille, je dois utiliser le mot-clef "virtual" dans la déclaration on de
// Mere::fct(), sans quoi Fille ::fct() ne sera pas appelée à la ligne 2 ci-dessus.
#define ANSWER_20
// 21. Si je veux redéfinir fct() dans Fille, je dois utiliser le mot-clef "virtual" dans la déclaration de
// Fille::fct(), sans quoi Fille ::fct() ne sera pas appelée à la ligne 2 ci-dessus.
#define ANSWER_21
// 22. Si je veux redéfinir fct() dans Fille, je dois utiliser le mot-clef "override" dans la définition de
// Fille::fct(), sans quoi Fille::fct() ne sera pas appelée ligne 2 ci-dessus.
#define ANSWER_22
// 23. Si Mere::fct() est virtuelle pure, il est impossible d'instancier la classe Mere.
#define ANSWER_23
// 24. On utilise le mot-clef "pure virtual" pour indiquer qu'une fonction-membre est virtuelle pure.
#define ANSWER_24
// 25. S'il est impossible d'instancier la classe Mere, le code à la ligne 1 ci-dessus ne compile pas.
#define ANSWER_25
