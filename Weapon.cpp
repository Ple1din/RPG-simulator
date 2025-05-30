#include "Weapon.h"
#include "Character.h"

Weapon::Weapon(const std::string& name, int damage) : name(name), damage(damage) {}



std::string Weapon::getName() const {
    return name;
}

void Weapon::setName(const std::string& name) {
    this->name = name;
}

int Weapon::getDamage() const {
    return damage;
}

void Weapon::setDamage(int damage) {
    this->damage = damage;
}
