// Wizard.h
#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"

class Wizard final : public Character {
private:
    double magic;
    int magicPenetration;

public:
    Wizard(std::string name, double health, Weapon* weapon, double magic, int magicPenetration);

    std::string attack(Character& character) override;
    std::string attack(Character& character, Weapon& weapon) const;
    std::string meditate();

    double getMagic() const;
    void setMagic(double magic);
    int getMagicPenetration() const;
    void setMagicPenetration(int magicPenetration);

    std::string showStats() const override;
    std::string showInventory() const override;
};

#endif