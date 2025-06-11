// Wizard.cpp
#include <utility>
#include "include/Wizard.h"

Wizard::Wizard(std::string name, double health, Weapon* weapon, double magic, int magicPenetration)
    : Character(std::move(name), health, weapon), magic(magic), magicPenetration(magicPenetration) {}

std::string Wizard::attack(Character& character) {
    double damageDone = magic * (1 + magicPenetration / 100.0);
    character.setHealth(character.getHealth() - damageDone);
    return "Casting spell, "+ name +" made " + std::to_string(damageDone) + " damage to " + character.getName()+ "(Enemy health" + std::to_string(character.getHealth()) + ")";
}

std::string Wizard::attack(Character& character, Weapon& weapon) const {
    std::string type = weapon.getType();
    double damageDone = 0;

    if (type == "staff") {
        damageDone = magic + weapon.getDamage() * 1.5;
        character.setHealth(character.getHealth() - damageDone);
        return "Attacking with staff, "+ name +" made " + std::to_string(damageDone) + " damage to " + character.getName()+ "(Enemy health" + std::to_string(character.getHealth()) + ")";
    }
    return "The weapon (" + type + ") is not suitable for wizards, you missed.";
}

std::string Wizard::meditate() {
    magic += 5;
    return "You meditate and increase your magic. New magic: " + std::to_string(magic);
}

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

std::string Wizard::showStats() const {
    std::string stats = "--- Wizard Stats ---\n";
    stats += "Name: " + name + "\n";
    stats += "Health: " + std::to_string(health) + "\n";
    stats += "Magic: " + std::to_string(magic) + "\n";
    stats += "Magic Penetration: " + std::to_string(magicPenetration) + "\n";
    stats += "Weapon: " + (weapon ? weapon->getType() : "None") + "\n";
    return stats;
}

std::string Wizard::showInventory() const {
    std::string inv = "--- Inventory ---\n";
    if (inventory.empty()) return inv + "Empty\n";
    int i = 1;
    for (Weapon* w : inventory)
        inv += std::to_string(i++) + ". " + w->getType() + " (Damage: " + std::to_string(w->getDamage()) + ")\n";
    return inv;
}