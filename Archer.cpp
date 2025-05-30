#include "Archer.h"
#include <iostream>
#include <cmath>

void Archer::attack(Character& target) {
    std::cout << name << " shoots an arrow at " << target.getName() << "!" << std::endl;
    int damage = strength + (weapon ? weapon->getDamage() : 0);
    target.setHealth(target.getHealth() - damage);
}

void Archer::attack(Character& target, double distance) {
    int damage = strength + (weapon ? weapon->getDamage() : 0);
    // Damage decreases with distance (simplified)
    int adjustedDamage = std::max(0, damage - static_cast<int>(distance));
    std::cout << name << " shoots an arrow from distance " << distance << " causing " << adjustedDamage << " damage to " << target.getName() << "!" << std::endl;
    target.setHealth(target.getHealth() - adjustedDamage);
}
