#include <utility>
#include "include/Archer.h"

/**
 * Constructor for the Archer class.
 * Initializes base stats and equipped weapon.
 */
Archer::Archer(std::string name, double health, Weapon* weapon, double agility, int penetration)
    : Character(std::move(name), health, weapon), agility(agility), penetration(penetration) {}

/**
 * Default attack using agility and penetration.
 * Deals moderate damage based on attributes.
 */
std::string Archer::attack(Character& character) {
    double damageDone = agility * 0.75 + penetration;
    character.setHealth(character.getHealth() - damageDone);
    return "Shooting arrow, " + name + " made " + std::to_string(damageDone) +
           " damage to " + character.getName() + " (Enemy health " + std::to_string(character.getHealth()) + ")";
}

/**
 * Overloaded attack using a specific weapon.
 * Only effective with \"bow\" weapons.
 */
std::string Archer::attack(Character& character, Weapon& weapon) const {
    std::string type = weapon.getType();
    double damageDone = 0;

    if (type == "bow") {
        damageDone = agility + weapon.getDamage() + penetration * 0.5;
        character.setHealth(character.getHealth() - damageDone);
        return "Attacking with bow, " + name + " made " + std::to_string(damageDone) +
               " damage to " + character.getName() + " (Enemy health " + std::to_string(character.getHealth()) + ")";
    }
    return "The weapon (" + type + ") is not suitable for archers, you missed.";
}

/**
 * Archer's unique skill.
 * Increases agility to boost future damage output.
 */
std::string Archer::practice() {
    agility += 2.5;
    return "You practiced and increased your agility. New agility: " + std::to_string(agility);
}

// -------- Getters and Setters --------

double Archer::getAgility() const {
    return agility;
}

void Archer::setAgility(double agility) {
    this->agility = agility;
}

int Archer::getPenetration() const {
    return penetration;
}

void Archer::setPenetration(const int penetration) {
    this->penetration = penetration;
}

/**
 * Returns a formatted string with the archer's current stats.
 */
std::string Archer::showStats() const {
    std::string stats = "--- Archer Stats ---\n";
    stats += "Name: " + name + "\n";
    stats += "Health: " + std::to_string(health) + "\n";
    stats += "Agility: " + std::to_string(agility) + "\n";
    stats += "Penetration: " + std::to_string(penetration) + "\n";
    stats += "Weapon: " + (weapon ? weapon->getType() : "None") + "\n";
    return stats;
}

/**
 * Returns a formatted string listing the archer's inventory.
 */
std::string Archer::showInventory() const {
    std::string inv = "--- Inventory ---\n";
    if (inventory.empty()) return inv + "Empty\n";
    int i = 1;
    for (Weapon* w : inventory)
        inv += std::to_string(i++) + ". " + w->getType() + " (Damage: " + std::to_string(w->getDamage()) + ")\n";
    return inv;
}
