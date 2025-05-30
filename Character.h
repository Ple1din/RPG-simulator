#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <memory>
#include "Weapon.h"

class Character {
protected:
    std::string name;
    int health;
    int strength;
    std::vector<std::unique_ptr<Weapon>> inventory;
    Weapon* weapon;  // Currently equipped weapon (not owning)

public:
    Character(const std::string& name = "", int health = 100, int strength = 10);

    // Virtual destructor for proper cleanup of derived classes
    virtual ~Character() = default;

    // Pure virtual method to force derived classes to implement attack
    virtual void attack(Character& target) = 0;

    // Equip a weapon from inventory (pointer to Weapon)
    virtual void equipWeapon(Weapon* newWeapon);

    // Heal self by fixed amount
    virtual void heal();

    // Block an attack (simple example)
    virtual void blockAttack();

    // Getters and setters
    std::string getName() const;
    void setName(const std::string& name);

    int getHealth() const;
    void setHealth(int health);

    int getStrength() const;
    void setStrength(int strength);

    // Inventory management
    std::vector<Weapon*> getInventory() const; // returns raw pointers (non-owning)
    void addWeaponToInventory(std::unique_ptr<Weapon> newWeapon);
    void setInventory(std::vector<std::unique_ptr<Weapon>>&& newInventory);

    Weapon* getWeapon() const;
    void setWeapon(Weapon* newWeapon);
};

#endif // CHARACTER_H
