#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"

class Wizard : public Character {
public:
    using Character::Character;

    void attack(Character& target) override;

    // Overloaded attack with magic power
    void attack(Character& target, int magicPower);
};

#endif // WIZARD_H
