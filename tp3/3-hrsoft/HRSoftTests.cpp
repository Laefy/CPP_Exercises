#include "HRSoft/HRSoftSystem.hpp"

int main()
{
    auto system = HRSoftSystem {};

    auto& rd_dpt = system.add_department("R&D");
    auto& market_dpt = system.add_department("Marketing");

    auto& charline = rd_dpt.add_employee("Charline", 6000, nullptr);
    auto& jacques = rd_dpt.add_employee("Jacques", 2500, &charline);
    auto& paul = market_dpt.add_employee("Paul", 2500, &charline);

    // TODO Q2.
    // Affiche différentes informations du système.
    // rd_dpt.print_employees();
    // system.print_all_departments();
    // system.print_all_employees();

    // TODO Q3.
    // Affiche tous les employés managés par Charline.
    // charline.print_subordinates();

    // TODO Q4.
    // Jacques est licencié...
    // system.remove_employee(jacques);
    // rd_dpt.print_employees();
    // charline.print_subordinates();

    return 0;
}
