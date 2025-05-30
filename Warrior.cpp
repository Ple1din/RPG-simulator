#include "Warrior.h"
#include <iostream>

void Warrior::attack(Character& target) {
    std::cout << name << " attacks " << target.getName() << " with a powerful strike!" << std::endl;
    int damage = strength;
    if (weapon) {
        damage += weapon->getDamage();
    }
    target.setHealth(target.getHealth() - damage);
}

void Warrior::attack(std::vector<Character*>& targets) {
    std::cout << name << " performs a sweeping attack on multiple enemies!" << std::endl;
    for (auto* target : targets) {
        attack(*target);
    }
}
