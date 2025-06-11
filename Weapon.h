// Weapon.h
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    std::string type;
    int damage;

public:
    Weapon(std::string type, int damage);
    // Getters y Setters
    std::string getType();
    void setType(std::string type);
    int getDamage() const;
    void setDamage(int damage);
};

#endif
