#pragma once

// Il est INTERDIT de modifier ce fichier !

/**
 * La classe `InstanceCounter` compte le nombre d'objets de type InstanceCounter en mémoire.
 */
class InstanceCounter
{
public:
    InstanceCounter() { ++_constr; }
    InstanceCounter(const InstanceCounter& other)
    {
        ++_constr;
        ++_copies;
        _origin = &other;
    }
    InstanceCounter(InstanceCounter&&) { ++_constr; }
    InstanceCounter& operator=(const InstanceCounter&) = delete;
    InstanceCounter& operator=(InstanceCounter&&)      = delete;

    ~InstanceCounter() { ++_delete; }

    static int             constructions() { return _constr; }
    static int             copies() { return _copies; }
    static int             deletions() { return _delete; }
    const InstanceCounter* origin() const { return _origin; }

    // Deux InstanceCounter sont égaux s'ils sont stockés au même endroit.
    bool operator==(const InstanceCounter& other) const { return (this == &other); }

private:
    inline static int      _assign = 0;
    inline static int      _constr = 0;
    inline static int      _copies = 0;
    inline static int      _delete = 0;
    const InstanceCounter* _origin = nullptr;
};

// Il est INTERDIT de modifier ce fichier !
