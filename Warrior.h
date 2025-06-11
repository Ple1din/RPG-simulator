#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

/**
 * Warrior class that inherits from Character.
 * Specializes in physical combat using strength and armor.
 */
class Warrior final : public Character {
private:
    double strength;  // Base strength used for damage calculation
    int armor;        // Armor value that increases durability or bonus damage

public:
    /**
     * Constructor to initialize a Warrior with custom attributes.
     * @param name Name of the warrior
     * @param health Starting health points
     * @param weapon Initial weapon equipped
     * @param strength Physical attack power
     * @param armor Defensive or bonus factor
     */
    Warrior(std::string name, double health, Weapon* weapon, double strength, int armor);

    /**
     * Overrides the attack method to deal damage using Warrior's strength.
     */
    std::string attack(Character& character) override;

    /**
     * Overloaded attack using a specific weapon.
     * Includes bonus damage calculation based on armor.
     */
    std::string attack(Character& character, Weapon& weapon) const;

    /**
     * Increases strength by training.
     * Depends on the current armor value.
     */
    std::string train();

    // -------- Getters and Setters --------

    double getStrength() const;
    void setStrength(double strength);
    int getArmor() const;
    void setArmor(int armor);

    /**
     * Returns a formatted string with Warrior's stats.
     */
    std::string showStats() const override;

    /**
     * Returns a formatted string with Warrior's inventory.
     */
    std::string showInventory() const override;
};

#endif
