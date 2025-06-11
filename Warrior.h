// Warrior.h
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior final : public Character {
private:
    double strength;
    int armor;

public:
    Warrior(std::string name, double health, Weapon* weapon, double strength, int armor);

    std::string attack(Character& character) override;
    std::string attack(Character& character, Weapon& weapon) const;
    std::string train();

    // Getters y Setters
    double getStrength() const;
    void setStrength(double strength);
    int getArmor() const;
    void setArmor(int armor);

    std::string showStats() const override;
    std::string showInventory() const override;
};

#endif
