#pragma once

/**
 * The class `InstanceCounter` counts the number of instances.
 */
class InstanceCounter
{
public:
    InstanceCounter() { ++_count; }
    InstanceCounter(const InstanceCounter&) { ++_count; }
    InstanceCounter(InstanceCounter&&) { ++_count; }

    InstanceCounter& operator=(const InstanceCounter& other) = default;
    InstanceCounter& operator=(InstanceCounter&&)            = default;

    ~InstanceCounter() { --_count; }

    static int  count() { return _count; }
    static void reset_counters() { _count = 0; }

    // Deux InstanceCounter sont égaux s'ils sont stockés au même endroit.
    bool operator==(const InstanceCounter& other) const { return (this == &other); }

private:
    static int _count;
};

// DO NOT MODIFY THIS FILE !
