#include <utility>
#include "include/Character.h"
#include "include/Weapon.h"
#include "iostream"

/**
 * Constructor for Character.
 * Initializes name, health, and equipped weapon.
 */
Character::Character(std::string name, const double health, Weapon* weapon)
    : name(std::move(name)), health(health), weapon(weapon) {}

/**
 * Static method to simulate blocking an attack.
 * Used by all character types.
 */
std::string Character::blockAttack() {
    return "blocked";
}

/**
 * Equips a weapon from the inventory by its index (1-based).
 * Returns a message indicating success or failure.
 */
std::string Character::equipWeapon(const int index) {
    std::string message;
    if (index > 0 && index < inventory.size() + 1) {
        auto it = inventory.begin();
        std::advance(it, index - 1);
        this->weapon = *it;
        message = "Weapon equipped";
        return message;
    }
    message = "Invalid index for your inventory";
    return message;
}

// ----------------- Getters and Setters -----------------

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

// ----------------- Operator Overloading -----------------

/**
 * Overloads the '+' operator to add a weapon to the inventory.
 */
Character& Character::operator+(Weapon* weapon) {
    this->inventory.push_back(weapon);
    return *this;
}

// ----------------- Inventory Management -----------------

/**
 * Adds a weapon to the character's inventory.
 */
void Character::addWeapon(Weapon* weapon) {
    inventory.push_back(weapon);
}

/**
 * Removes a weapon from the inventory based on its index (1-based).
 * Returns true if removed, false if index is invalid.
 */
bool Character::removeWeaponByIndex(int index) {
    if (index < 1 || index > inventory.size()) return false;
    auto it = inventory.begin();
    std::advance(it, index - 1);
    inventory.erase(it);
    return true;
}

/**
 * Finds a weapon by its type string (e.g. \"sword\", \"bow\").
 * Returns a pointer to the weapon or nullptr if not found.
 */
Weapon* Character::findWeaponByType(const std::string& type) {
    for (auto* w : inventory) {
        if (w->getType() == type) return w;
    }
    return nullptr;
}
