#include <utility>
#include "include/Wizard.h"

/**
 * Constructor for the Wizard class.
 * Initializes name, health, magic stats, and equipped weapon.
 */
Wizard::Wizard(std::string name, double health, Weapon* weapon, double magic, int magicPenetration)
    : Character(std::move(name), health, weapon), magic(magic), magicPenetration(magicPenetration) {}

/**
 * Default magical attack.
 * Damage is calculated using magic and magic penetration percentage.
 */
std::string Wizard::attack(Character& character) {
    double damageDone = magic * (1 + magicPenetration / 100.0);
    character.setHealth(character.getHealth() - damageDone);
    return "Casting spell, " + name + " made " + std::to_string(damageDone) +
           " damage to " + character.getName() + " (Enemy health " + std::to_string(character.getHealth()) + ")";
}

/**
 * Overloaded attack using a weapon.
 * Only valid if the weapon is a \"staff\".
 */
std::string Wizard::attack(Character& character, Weapon& weapon) const {
    std::string type = weapon.getType();
    double damageDone = 0;

    if (type == "staff") {
        damageDone = magic + weapon.getDamage() * 1.5;
        character.setHealth(character.getHealth() - damageDone);
        return "Attacking with staff, " + name + " made " + std::to_string(damageDone) +
               " damage to " + character.getName() + " (Enemy health " + std::to_string(character.getHealth()) + ")";
    }
    return "The weapon (" + type + ") is not suitable for wizards, you missed.";
}

/**
 * Wizard's special skill to increase magic power.
 */
std::string Wizard::meditate() {
    magic += 5;
    return "You meditate and increase your magic. New magic: " + std::to_string(magic);
}

// -------- Getters and Setters --------

double Wizard::getMagic() const {
    return magic;
}

void Wizard::setMagic(double magic) {
    this->magic = magic;
}

int Wizard::getMagicPenetration() const {
    return magicPenetration;
}

void Wizard::setMagicPenetration(const int magicPenetration) {
    this->magicPenetration = magicPenetration;
}

/**
 * Returns a formatted string with the wizard's current stats.
 */
std::string Wizard::showStats() const {
    std::string stats = "--- Wizard Stats ---\n";
    stats += "Name: " + name + "\n";
    stats += "Health: " + std::to_string(health) + "\n";
    stats += "Magic: " + std::to_string(magic) + "\n";
    stats += "Magic Penetration: " + std::to_string(magicPenetration) + "\n";
    stats += "Weapon: " + (weapon ? weapon->getType() : "None") + "\n";
    return stats;
}

/**
 * Returns a formatted string listing the wizard's inventory.
 */
std::string Wizard::showInventory() const {
    std::string inv = "--- Inventory ---\n";
    if (inventory.empty()) return inv + "Empty\n";
    int i = 1;
    for (Weapon* w : inventory)
        inv += std::to_string(i++) + ". " + w->getType() + " (Damage: " + std::to_string(w->getDamage()) + ")\n";
    return inv;
}
