#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Character;  // Forward declaration for attack parameter

class Weapon {
private:
    std::string name;
    int damage;

public:
    Weapon(const std::string& name = "", int damage = 0);



    // Getters and setters
    std::string getName() const;
    void setName(const std::string& name);

    int getDamage() const;
    void setDamage(int damage);
};

#endif // WEAPON_H
