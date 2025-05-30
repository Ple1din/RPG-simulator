#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"

class Archer : public Character {
public:
    using Character::Character;

    void attack(Character& target) override;

    // Overload attack with distance factor
    void attack(Character& target, double distance);
};

#endif // ARCHER_H
