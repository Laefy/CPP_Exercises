#include "InstanceCounter.hpp"

int InstanceCounter::_counter = 0;

InstanceCounter& InstanceCounter::operator=(const InstanceCounter& other)
{
    if (this != &other)
        ++_counter;
    return *this;
}