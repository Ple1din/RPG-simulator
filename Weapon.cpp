#include <utility>

#include "include/Weapon.h"

Weapon::Weapon(std::string type, const int damage) {
    this->type = std::move(type);
    this->damage = damage;
}

std::string Weapon::getType() {
    return type;
}

void Weapon::setType(std::string type) {
    this->type = std::move(type);
}

int Weapon::getDamage() const {
    return damage;
}

void Weapon::setDamage(const int damage) {
    this->damage = damage;
}
