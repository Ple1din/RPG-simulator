#ifndef WEAPON_H
#define WEAPON_H

#include <string>

/**
 * Represents a weapon that a character can use.
 * Weapons have a type (e.g. sword, bow, staff) and a damage value.
 */
class Weapon {
private:
    std::string type;   // Type of weapon (e.g. "sword", "bow", "staff")
    int damage;         // Amount of damage dealt by the weapon

public:
    /**
     * Constructor to initialize a weapon with type and damage.
     * @param type The type of the weapon.
     * @param damage The amount of damage it can deal.
     */
    Weapon(std::string type, int damage);

    // -------- Getters and Setters --------

    /**
     * Returns the type of the weapon.
     */
    std::string getType();

    /**
     * Sets the type of the weapon.
     * @param type New type name.
     */
    void setType(std::string type);

    /**
     * Returns the damage value of the weapon.
     */
    int getDamage() const;

    /**
     * Sets the damage value of the weapon.
     * @param damage New damage value.
     */
    void setDamage(int damage);
};

#endif
