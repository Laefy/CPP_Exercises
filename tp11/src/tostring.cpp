#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Résolution possible des ambiguïtés par un type template hérité N fois
// Une fonction utilisant le type priority_tag<N+1> est plus spécialisé qu'une fonction utilisant le type
// priority_tag<N>
template <unsigned N>
struct priority_tag : priority_tag<N - 1>
{};
template <>
struct priority_tag<0>
{};

// On pourrait aussi ajouter des arguments `int` et utiliser les types `int/double` pour l'ordre

// Simples alias
using low_prior  = priority_tag<0>;
using mid_prior  = priority_tag<1>;
using high_prior = priority_tag<2>;

template <typename T>
auto to_string(T&&);

template <typename T>
auto to_string(const T& data, low_prior)
{
    std::stringstream ss;
    ss << "<" << typeid(data).name() << ": " << &data << ">";
    return ss.str();
}

auto to_string(const std::string& ctn)
{
    return ctn;
}
auto to_string(std::string&& ctn)
{
    return ctn;
}
auto to_string(const char* ctn)
{
    return std::string { ctn };
}

template <typename T>
auto to_string(const T& ctn, high_prior) -> decltype(std::to_string(ctn))
{
    return std::to_string(ctn);
}

template <typename T>
auto to_string(const T& ctn, high_prior) -> decltype(std::begin(ctn), std::string())
{
    std::stringstream ss;
    ss << "{ ";
    for (const auto& v : ctn)
        ss << to_string(v) << " ";
    ss << "}";
    return ss.str();
}

// Note: La spécialisation pour les array passe n'a pas besoin de résolution d'ambiguité avec les conteneurs
template <typename T, size_t N>
auto to_string(const std::array<T, N>& ctn)
{
    std::stringstream ss;
    ss << "[ ";
    for (const auto& v : ctn)
        ss << to_string(v) << " ";
    ss << "]";
    return ss.str();
}

template <typename T>
auto to_string(const T& ctn, high_prior) -> decltype(ctn.to_string())
{
    return ctn.to_string();
}

// Dans le cas d'une classe ayant l'opérateur de flux et la méthode to_string, il nous faut un niveau
// intermédiaire de spécialisation
template <typename T>
auto to_string(const T& ctn, mid_prior) -> decltype(std::declval<std::ostream&>() << ctn, std::string())
{
    std::stringstream ss;
    ss << ctn;
    return ss.str();
}

// Référence universel ici, il faut forward le type
template <typename T>
auto to_string(T&& t)
{
    return to_string(std::forward<T>(t), high_prior {});
    // Si on utilise les types int/double/long pour résoudre les ambiguités, on a ici
    // return to_string(std::forward<T>(t), 0, 0);
    // avec autant d'arguments suplémentaires que nécessaire
}

class Empty
{};

class Streamable
{
public:
    friend std::ostream& operator<<(std::ostream& out, const Streamable& s)
    {
        return out << "Streamable @" << &s;
    }
};

class Convertible
{
public:
    std::string to_string() const
    {
        std::stringstream ss;
        ss << "Convertible @" << this;
        return ss.str();
    }
};

class Both : public Streamable, public Convertible
{};

int main()
{
    // De base on a l'adresse des objets
    std::cout << "Vide" << std::endl << " -> " << to_string(Empty {}) << std::endl;

    // Q1: on veut gérer les chaines de caractères
    std::cout << "std::string" << std::endl << " -> " << to_string(std::string { "Machin" }) << std::endl;
    std::cout << "char*" << std::endl << " -> " << to_string("Bidule") << std::endl;

    // Q2: Puis les conversions simples fournies par la fonction std::to_string
    std::cout << "int" << std::endl << " -> " << to_string(3) << std::endl;

    // Q4: On s'attaque maintenant aux conteneurs
    std::cout << "std::vector<int>" << std::endl
              << " -> " << to_string(std::vector<int> { 1, 2, 3, 4 }) << std::endl;
    std::cout << "std::vector<std::vector<int>>" << std::endl
              << " -> "
              << to_string(std::vector<std::vector<int>> { std::vector<int> { 0, 1, 2, 3 },
                                                           std::vector<int> { 4, 5, 6, 7 } })
              << std::endl;
    // Q4b: avec une spécialisation pour les std::array
    std::cout << "std::array<int, 4>" << std::endl
              << " -> " << to_string(std::array<int, 4> { 1, 2, 3, 4 }) << std::endl;

    // Q5: Si un objet présente une fonction de conversion, on l'utilise
    std::cout << "Convertible" << std::endl << " -> " << to_string(Convertible {}) << std::endl;

    // Q6: S'il est streamable (en implémentant l'opérateur << sur ostream),
    // idem
    std::cout << "Streamable" << std::endl << " -> " << to_string(Streamable {}) << std::endl;

    // Commenter cette ligne si elle bloque la compilation trop tot dans le TP
    std::cout << "Both" << std::endl << " -> " << to_string(Both {}) << std::endl;
    return 0;
}