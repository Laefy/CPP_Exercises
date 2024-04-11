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

template <typename T>
void print_test(std::string type, T&& value) {
    std::cout << type << std::endl;
    std::cout << "** Error: value is not a std::string" << std::endl;
}

void print_test(std::string type, std::string value)
{
    std::cout << type << std::endl;
    std::cout << " -> " << value << std::endl;
}

int main()
{
    // De base on a l'adresse des objets
    print_test("Vide", to_string(Empty {}));

    // Q1: on veut gérer les chaines de caractères
    print_test("std::string", to_string(std::string { "Machin" }));
    print_test("char*", to_string("Bidule"));

    // Q2: Puis les conversions simples fournies par la fonction std::to_string
    print_test("int", to_string(3));

    // Q4: On s'attaque maintenant aux conteneurs
    print_test("std::vector<int>", to_string(std::vector<int> { 1, 2, 3, 4 }));
    print_test("std::vector<std::vector<int>>",
               to_string(std::vector<std::vector<int>> { std::vector<int> { 0, 1, 2, 3 },
                                                         std::vector<int> { 4, 5, 6, 7 } }));
    // Q4b: avec une spécialisation pour les std::array
    print_test("std::array<int, 4>", to_string(std::array<int, 4> { 1, 2, 3, 4 }));

    // Q5: Si un objet présente une fonction de conversion, on l'utilise
    print_test("Convertible", to_string(Convertible {}));

    // Q6: S'il est streamable (en implémentant l'opérateur << sur ostream), idem
    print_test("Streamable", to_string(Streamable {}));

    // Commenter cette ligne si elle bloque la compilation trop tot dans le TP
    print_test("Both", to_string(Both {}));
    return 0;
}
