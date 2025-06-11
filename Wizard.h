#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"

/**
 * Wizard class that inherits from Character.
 * Focuses on magical damage and spell power.
 */
class Wizard final : public Character {
private:
    double magic;            // Base magical power
    int magicPenetration;    // Increases effectiveness against resistances

public:
    /**
     * Constructor to initialize a Wizard with specific attributes.
     * @param name Name of the wizard
     * @param health Initial health value
     * @param weapon Equipped weapon
     * @param magic Initial magic stat
     * @param magicPenetration Bonus to bypass defenses
     */
    Wizard(std::string name, double health, Weapon* weapon, double magic, int magicPenetration);

    /**
     * Basic magical attack based on the wizard's magic and penetration.
     */
    std::string attack(Character& character) override;

    /**
     * Overloaded attack using a weapon.
     * Only works effectively with a \"staff\".
     */
    std::string attack(Character& character, Weapon& weapon) const;

    /**
     * Wizard's special ability to increase magical power.
     */
    std::string meditate();

    // -------- Getters and Setters --------

    double getMagic() const;
    void setMagic(double magic);
    int getMagicPenetration() const;
    void setMagicPenetration(int magicPenetration);

    /**
     * Returns a string with the wizard's current stats.
     */
    std::string showStats() const override;

    /**
     * Returns a string listing the wizard's inventory.
     */
    std::string showInventory() const override;
};

#endif
