#pragma once

#include "Employee.hpp"

#include <list>
#include <string>

class Department
{
public:
    Department(const std::string& name)
        : _name { name }
    {}

    Employee& add_employee(const std::string& name, unsigned int salary, Employee* manager)
    {
        auto& employee = _employees.emplace_back(name, salary);

        if (manager != nullptr)
        {
            manager->add_subordinate(employee);
        }

        return employee;
    }

private:
    std::string _name;
    std::list<Employee> _employees;
};
