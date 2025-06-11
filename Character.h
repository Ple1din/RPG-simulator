// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <list>
#include "Weapon.h"

class Character {
protected:
    std::string name;
    double health;
    std::list<Weapon*> inventory;
    Weapon* weapon;

public:

    Character(std::string name, double health, Weapon* weapon);

    virtual std::string attack(Character& character) = 0;
    virtual std::string showStats() const = 0;
    virtual std::string showInventory() const = 0;

    static std::string blockAttack();
    std::string equipWeapon(int index);
    std::string getName();
    void setName(std::string name);
    double getHealth() const;
    void setHealth(double health);
    Weapon* getWeapon() const;
    void setWeapon(Weapon* weapon);
    std::list<Weapon*> getInventory() const;
    void setInventory(std::list<Weapon*> inventory);
    Character& operator+(Weapon* weapon);


    virtual ~Character() = default;
};

#endif
