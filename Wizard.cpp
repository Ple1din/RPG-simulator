#include "Wizard.h"
#include <iostream>

void Wizard::attack(Character& target) {
    std::cout << name << " casts a spell on " << target.getName() << "!" << std::endl;
    int damage = strength * 2;
    if (weapon) {
        damage += weapon->getDamage();
    }
    target.setHealth(target.getHealth() - damage);
}

void Wizard::attack(Character& target, int magicPower) {
    std::cout << name << " casts a powerful spell with magic power " << magicPower << " on " << target.getName() << "!" << std::endl;
    int damage = strength * 2 + magicPower;
    if (weapon) {
        damage += weapon->getDamage();
    }
    target.setHealth(target.getHealth() - damage);
}
