#include <utility>

#include "include/Character.h"
#include "include/Weapon.h"
#include "iostream"

Character::Character(std::string name, const double health, Weapon* weapon)
    : name(std::move(name)), health(health), weapon(weapon) {}

std::string Character::blockAttack() {
    return "blocked";
}

std::string Character::equipWeapon(const int index) {
    std::string message;
    if (index > 0 && index < inventory.size()+1) {
        auto it = inventory.begin();
        std::advance(it, index - 1);
        this->weapon = *it;
        message = "Weapon equipped";
        return message;
    }
    message = "Invalid index for your inventory";
    return message;
}

std::string Character::getName() {
    return name;
}

void Character::setName(std::string name) {
    this->name = std::move(name);
}

double Character::getHealth() const {
    return health;
}

void Character::setHealth(const double health) {
    this->health = health;
}

Weapon* Character::getWeapon() const {
    return weapon;
}

void Character::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

std::list<Weapon*> Character::getInventory() const {
    return inventory;
}

void Character::setInventory(std::list<Weapon*> inventory) {
    this->inventory = std::move(inventory);
}


Character& Character::operator+(Weapon* weapon) {
    this->inventory.push_back(weapon);
    return *this;
}