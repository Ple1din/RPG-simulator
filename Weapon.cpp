#include <utility>
#include "include/Weapon.h"

/**
 * Constructor to initialize a weapon with its type and damage.
 * Uses std::move for efficiency with string handling.
 */
Weapon::Weapon(std::string type, const int damage) {
    this->type = std::move(type);
    this->damage = damage;
}

/**
 * Returns the type of the weapon (e.g., "sword", "bow").
 */
std::string Weapon::getType() {
    return type;
}

/**
 * Sets the type of the weapon.
 * @param type New type string.
 */
void Weapon::setType(std::string type) {
    this->type = std::move(type);
}

/**
 * Returns the weapon's damage value.
 */
int Weapon::getDamage() const {
    return damage;
}

/**
 * Sets the weapon's damage value.
 * @param damage New integer damage value.
 */
void Weapon::setDamage(const int damage) {
    this->damage = damage;
}
