#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"

/**
 * Archer class that inherits from Character.
 * Specializes in ranged attacks and agility-based combat.
 */
class Archer final : public Character {
private:
    double agility;      // Base agility for calculating damage
    int penetration;     // Value that boosts attack effectiveness

public:
    /**
     * Constructor to initialize an Archer with specific attributes.
     * @param name Name of the archer
     * @param health Initial health value
     * @param weapon Initial equipped weapon
     * @param agility Base agility stat
     * @param penetration Penetration bonus
     */
    Archer(std::string name, double health, Weapon* weapon, double agility, int penetration);

    /**
     * Performs a base attack using agility and penetration.
     */
    std::string attack(Character& character) override;

    /**
     * Performs an attack using a specific weapon.
     * Only effective with bows.
     */
    std::string attack(Character& character, Weapon& weapon) const;

    /**
     * Archer's special ability to increase agility.
     */
    std::string practice();

    // -------- Getters and Setters --------

    double getAgility() const;
    void setAgility(double agility);
    int getPenetration() const;
    void setPenetration(int penetration);

    /**
     * Returns formatted string showing archer stats.
     */
    std::string showStats() const override;

    /**
     * Returns formatted string listing the archer's inventory.
     */
    std::string showInventory() const override;
};

#endif
