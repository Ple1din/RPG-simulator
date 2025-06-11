#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <list>
#include "Weapon.h"

/**
 * Abstract base class representing a generic RPG character.
 * Provides common attributes and behaviors for all subclasses.
 */
class Character {
protected:
    std::string name;               // Character's name
    double health;                  // Current health points
    std::list<Weapon*> inventory;   // Inventory containing weapons
    Weapon* weapon;                 // Currently equipped weapon

public:
    /**
     * Constructor to initialize a character.
     * @param name Character's name
     * @param health Initial health value
     * @param weapon Initial equipped weapon
     */
    Character(std::string name, double health, Weapon* weapon);

    /**
     * Pure virtual method for attacking another character.
     * Must be overridden by each subclass.
     */
    virtual std::string attack(Character& character) = 0;

    /**
     * Pure virtual method to return character stats as a string.
     */
    virtual std::string showStats() const = 0;

    /**
     * Pure virtual method to return inventory as a formatted string.
     */
    virtual std::string showInventory() const = 0;

    /**
     * Simulates blocking an attack. Shared by all characters.
     */
    static std::string blockAttack();

    /**
     * Equips a weapon from the inventory by index.
     * @param index One-based index of the weapon in inventory.
     * @return Result message.
     */
    std::string equipWeapon(int index);

    // Getters and setters
    std::string getName();
    void setName(std::string name);
    double getHealth() const;
    void setHealth(double health);
    Weapon* getWeapon() const;
    void setWeapon(Weapon* weapon);
    std::list<Weapon*> getInventory() const;
    void setInventory(std::list<Weapon*> inventory);

    /**
     * Overloaded operator+ to add a weapon to the inventory.
     * @param weapon Pointer to the weapon to be added.
     * @return Reference to the updated character.
     */
    Character& operator+(Weapon* weapon);

    virtual ~Character() = default;

    // Inventory management methods

    /**
     * Adds a weapon to the character's inventory.
     */
    void addWeapon(Weapon* weapon);

    /**
     * Removes a weapon by its position in the inventory.
     * @param index One-based index of the weapon.
     * @return True if successful, false otherwise.
     */
    bool removeWeaponByIndex(int index);

    /**
     * Finds a weapon by its type in the inventory.
     * @param type Weapon type string (e.g. \"sword\")
     * @return Pointer to the found weapon or nullptr.
     */
    Weapon* findWeaponByType(const std::string& type);
};

#endif
