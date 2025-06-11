#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include "include/Warrior.h"
#include "include/Wizard.h"
#include "include/Archer.h"

// Clears the input buffer after an invalid input
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Validates that the user enters a number within a given range
int getValidatedInput(int min, int max) {
    int input;
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (ss >> input && !(ss >> line) && input >= min && input <= max) {
            return input;
        } else {
            std::cout << "Invalid choice. Try again: ";
        }
    }
}

// Creates a weapon with random type and random damage value
Weapon* generateRandomWeapon() {
    std::vector<std::string> types = {"sword", "staff", "bow"};
    int damage = 10 + rand() % 31;
    std::string type = types[rand() % types.size()];
    return new Weapon(type, damage);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Create basic weapons
    Weapon* sword = new Weapon("sword", 30);
    Weapon* staff = new Weapon("staff", 25);
    Weapon* bow = new Weapon("bow", 20);
    std::vector<Weapon*> allWeapons = {sword, staff, bow};

    std::string name;
    int choice;
    Character* player = nullptr;

    // --- Character creation ---
    std::cout << "Enter your character's name: ";
    std::getline(std::cin, name);
    std::cout << "Choose your class (1-Warrior, 2-Wizard, 3-Archer): ";
    choice = getValidatedInput(1, 3);

    if (choice == 1) player = new Warrior(name, 150, nullptr, 50, 20);
    else if (choice == 2) player = new Wizard(name, 120, nullptr, 40, 30);
    else player = new Archer(name, 110, nullptr, 35, 25);

    // Choose starting weapon
    std::cout << "Choose your weapon: 1-sword, 2-staff, 3-bow: ";
    choice = getValidatedInput(1, 3);
    player->setWeapon(allWeapons[choice - 1]);
    *player + allWeapons[choice - 1];

    // --- Enemy creation ---
    std::vector<Character*> enemies;
    enemies.push_back(new Warrior("Enemy Warrior", 150, sword, 45, 25));
    enemies.push_back(new Wizard("Enemy Wizard", 120, staff, 35, 20));
    enemies.push_back(new Archer("Enemy Archer", 110, bow, 30, 15));
    for (auto* e : enemies) *e + e->getWeapon();

    // Choose enemy to fight
    std::cout << "Choose your enemy:\n";
    for (size_t i = 0; i < enemies.size(); ++i) {
        std::cout << i + 1 << ". " << enemies[i]->getName() << "\n";
    }
    choice = getValidatedInput(1, enemies.size());
    Character* enemy = enemies[choice - 1];

    std::string lastEnemyAction = "";
    std::string lastPlayerAction = "";

    // --- Turn-based combat loop ---
    while (player->getHealth() > 0 && enemy->getHealth() > 0) {
        std::cout << "\n--- Your Turn ---\n";
        std::cout << "1. Attack\n2. Attack with Weapon\n3. Unique Skill\n4. Block\n5. Show Stats\n6. Show Inventory\n7. Equip Weapon\n8. Search Treasure\nChoose an action: ";
        choice = getValidatedInput(1, 8);

        if (choice == 1) {
            if (lastEnemyAction == "block") std::cout << "Enemy blocked your attack.\n";
            else std::cout << player->attack(*enemy) << "\n";
            lastPlayerAction = "attack";

        } else if (choice == 2) {
            if (lastEnemyAction == "block") std::cout << "Enemy blocked your attack.\n";
            else {
                if (auto warrior = dynamic_cast<Warrior*>(player))
                    std::cout << warrior->attack(*enemy, *player->getWeapon()) << "\n";
                else if (auto wizard = dynamic_cast<Wizard*>(player))
                    std::cout << wizard->attack(*enemy, *player->getWeapon()) << "\n";
                else if (auto archer = dynamic_cast<Archer*>(player))
                    std::cout << archer->attack(*enemy, *player->getWeapon()) << "\n";
            }
            lastPlayerAction = "attack";

        } else if (choice == 3) {
            if (auto w = dynamic_cast<Warrior*>(player)) std::cout << w->train() << "\n";
            else if (auto w = dynamic_cast<Wizard*>(player)) std::cout << w->meditate() << "\n";
            else if (auto a = dynamic_cast<Archer*>(player)) std::cout << a->practice() << "\n";
            lastPlayerAction = "skill";

        } else if (choice == 4) {
            std::cout << Character::blockAttack() << "\n";
            lastPlayerAction = "block";

        } else if (choice == 5) {
            std::cout << player->showStats();
            continue;

        } else if (choice == 6) {
            std::cout << player->showInventory();
            continue;

        } else if (choice == 7) {
            std::cout << player->showInventory();
            std::cout << "Enter index to equip weapon: ";
            int idx = getValidatedInput(1, player->getInventory().size());
            std::cout << player->equipWeapon(idx) << "\n";
            continue;

        } else if (choice == 8) {
            Weapon* treasure = generateRandomWeapon();
            std::cout << "You found a " << treasure->getType() << " with " << treasure->getDamage() << " damage!\n";
            *player + treasure;
            allWeapons.push_back(treasure);
            continue;
        }

        // Check if enemy defeated
        if (enemy->getHealth() <= 0) break;

        // --- Enemy Turn ---
        std::cout << "\n--- Enemy Turn ---\n";
        if (lastPlayerAction == "block") {
            std::cout << "You blocked the enemy attack.\n";
            lastEnemyAction = "attack";
        } else {
            std::cout << enemy->attack(*player) << "\n";
            lastEnemyAction = "attack";
        }
    }

    // --- Battle Result ---
    std::cout << (player->getHealth() > 0 ? "\nYou won!\n" : "\nYou lost!\n");

    // Cleanup
    delete player;
    for (auto e : enemies) delete e;
    for (auto w : allWeapons) delete w;

    return 0;
}