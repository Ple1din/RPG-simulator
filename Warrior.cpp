// Warrior.cpp (actualizado)
#include <utility>
#include "include/Warrior.h"

Warrior::Warrior(std::string name, const double health, Weapon* weapon, const double strength, const int armor)
    : Character(std::move(name), health, weapon), strength(strength), armor(armor) {}

std::string Warrior::attack(Character& character) {
    double damageDone = strength + armor * 0.2;
    character.setHealth(character.getHealth() - damageDone);
    return "Swinging mightily, "+ name +" made " + std::to_string(damageDone) + " damage to " + character.getName()+ "(Enemy health" + std::to_string(character.getHealth()) + ")";
}

std::string Warrior::attack(Character& character, Weapon& weapon) const {
    std::string type = weapon.getType();
    double damageDone = 0;

    if (type == "sword") {
        damageDone = strength + weapon.getDamage() + armor * 0.1;
        character.setHealth(character.getHealth() - damageDone);
        return "Attacking with sword, you made " + std::to_string(damageDone) + " damage to " + character.getName()+ "(Enemy health" + std::to_string(character.getHealth()) + ")";
    }
    return "The weapon (" + type + ") is not suitable for warriors, you missed.";
}

std::string Warrior::train() {
    strength += armor * 0.15;
    return "You trained using your armor as resistance. New strength: " + std::to_string(strength);
}

double Warrior::getStrength() const {
    return strength;
}

void Warrior::setStrength(const double strength) {
    this->strength = strength;
}

int Warrior::getArmor() const {
    return armor;
}

void Warrior::setArmor(const int armor) {
    this->armor = armor;
}

std::string Warrior::showStats() const {
    std::string stats = "--- Warrior Stats ---\n";
    stats += "Name: " + name + "\n";
    stats += "Health: " + std::to_string(health) + "\n";
    stats += "Strength: " + std::to_string(strength) + "\n";
    stats += "Armor: " + std::to_string(armor) + "\n";
    stats += "Weapon: " + (weapon ? weapon->getType() : "None") + "\n";
    return stats;
}

std::string Warrior::showInventory() const {
    std::string inv = "--- Inventory ---\n";
    if (inventory.empty()) return inv + "Empty\n";
    int i = 1;
    for (Weapon* w : inventory)
        inv += std::to_string(i++) + ". " + w->getType() + " (Damage: " + std::to_string(w->getDamage()) + ")\n";
    return inv;
}