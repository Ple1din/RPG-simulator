#include <iostream>
#include "Warrior.h"
#include "Wizard.h"
#include "Archer.h"
#include "Weapon.h"

int main() {
    Warrior w("Conan", 120, 15);
    Wizard wiz("Gandalf", 100, 12);
    Archer archer("Legolas", 90, 14);

    // Create some weapons
    auto sword = std::make_unique<Weapon>("Sword", 10);
    auto staff = std::make_unique<Weapon>("Staff", 8);
    auto bow = std::make_unique<Weapon>("Bow", 7);

    // Add weapons to inventory
    w.addWeaponToInventory(std::move(sword));
    wiz.addWeaponToInventory(std::move(staff));
    archer.addWeaponToInventory(std::move(bow));

    // Equip weapons
    w.equipWeapon(w.getInventory()[0]);
    wiz.equipWeapon(wiz.getInventory()[0]);
    archer.equipWeapon(archer.getInventory()[0]);

    // Characters attack each other
    w.attack(wiz);
    wiz.attack(w);
    archer.attack(w);

    // Overloaded attacks
    wiz.attack(w, 5);  // Wizard with magic power
    archer.attack(w, 3.5);  // Archer with distance factor

    return 0;
}
