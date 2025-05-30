#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, int health, int strength)
    : name(name), health(health), strength(strength), weapon(nullptr) {}

void Character::equipWeapon(Weapon* newWeapon) {
    weapon = newWeapon;
    std::cout << name << " equipped " << (weapon ? weapon->getName() : "no weapon") << std::endl;
}

void Character::heal() {
    health += 10;
    std::cout << name << " healed 10 health points. Total health: " << health << std::endl;
}

void Character::blockAttack() {
    std::cout << name << " blocked the attack!" << std::endl;
}

std::string Character::getName() const {
    return name;
}

void Character::setName(const std::string& name) {
    this->name = name;
}

int Character::getHealth() const {
    return health;
}

void Character::setHealth(int health) {
    this->health = health < 0 ? 0 : health;
}

int Character::getStrength() const {
    return strength;
}

void Character::setStrength(int strength) {
    this->strength = strength;
}

std::vector<Weapon*> Character::getInventory() const {
    std::vector<Weapon*> weapons;
    for (const auto& w : inventory) {
        weapons.push_back(w.get());
    }
    return weapons;
}

void Character::addWeaponToInventory(std::unique_ptr<Weapon> newWeapon) {
    inventory.push_back(std::move(newWeapon));
}

void Character::setInventory(std::vector<std::unique_ptr<Weapon>>&& newInventory) {
    inventory = std::move(newInventory);
}

Weapon* Character::getWeapon() const {
    return weapon;
}

void Character::setWeapon(Weapon* newWeapon) {
    weapon = newWeapon;
}
