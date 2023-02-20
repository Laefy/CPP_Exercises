#pragma once

/**
 * The class `InstanceCounter` counts the number of different instances present in memory.
 */
class InstanceCounter
{
public:
    InstanceCounter() { ++_counter; }
    InstanceCounter(const InstanceCounter&) { ++_counter; }
    InstanceCounter& operator=(const InstanceCounter& other);
    ~InstanceCounter() { --_counter; }

    static int counter() { return _counter; }

private:
    static int _counter;
};