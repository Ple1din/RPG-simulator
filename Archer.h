// Archer.h
#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"

class Archer final : public Character {
private:
    double agility;
    int penetration;

public:
    Archer(std::string name, double health, Weapon* weapon, double agility, int penetration);

    std::string attack(Character& character) override;
    std::string attack(Character& character, Weapon& weapon) const;
    std::string practice();

    double getAgility() const;
    void setAgility(double agility);
    int getPenetration() const;
    void setPenetration(int penetration);

    std::string showStats() const override;
    std::string showInventory() const override;
};

#endif
