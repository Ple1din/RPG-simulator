#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
public:
    using Character::Character;

    // Override attack method
    void attack(Character& target) override;

    // Overload attack to accept multiple targets (example of overloading)
    void attack(std::vector<Character*>& targets);
};

#endif // WARRIOR_H
