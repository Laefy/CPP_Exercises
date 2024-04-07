#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
auto to_string(const T& data)
{
    std::stringstream ss;
    ss << "<" << typeid(data).name() << ": " << &data << ">";
    return ss.str();
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

    // Q6: S'il est streamable (en implémentant l'opérateur << sur ostream), idem
    std::cout << "Streamable" << std::endl << " -> " << to_string(Streamable {}) << std::endl;

    // Commenter cette ligne si elle bloque la compilation trop tot dans le TP
    std::cout << "Both" << std::endl << " -> " << to_string(Both {}) << std::endl;
    return 0;
}