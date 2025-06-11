# RPG-simulator
# 📚 Video Game Character Simulator (RPG Style)

This project is a character simulator based on role-playing game (RPG) logic. It allows you to apply key Object-Oriented Programming (OOP) principles such as inheritance, polymorphism, operator overloading, exception handling, and the use of abstract classes, all within an interactive environment.
### 🎮 **Context**
In RPG video games, characters possess attributes, unique abilities, and an inventory of weapons. This simulator allows for the representation of these interactions, including combat turns, dynamic inventories, attack blocking, treasure hunting, and the use of special abilities. Each character's logic is designed to demonstrate differentiated behaviors through polymorphism.

### 📌 **Justification**
This project is valuable because it allows you to:

Observe how theoretical OOP concepts are applied in a practical and entertaining setting.

Write clean, reusable, and modular code.

Practice object-oriented design, abstraction, composition, and error handling with your own classes.

### 🛠️ **General Structure**

** 🧱 Character** (Abstract Class)
Defines common behavior among characters and is the basis for the Warrior, Wizard, and Archer classes. Each subclass implements its own attack logic and unique abilities. It also manages health, inventory, and weapons.

** 🟥 Warrior**
Specializes in physical combat. Its unique ability increases strength and leverages armor to increase damage. It is most effective with swords.

** 🔷 Wizard**
Uses magical attacks and can increase its magical power with its special ability. It can only use staves to perform effective attacks.

**🟢 Archer**
Ranged attacker. Increases agility with its unique ability and is most effective with bows.

**⚔️ Weapon**
Independent class that represents a weapon. Each weapon has a type (sword, staff, or bow) and a damage value. Weapons can be found in combat and added to the inventory.
![RPG drawio (1)](https://github.com/user-attachments/assets/e71bbb83-7472-4e99-890c-5f244dc0b629)


### **🔁 Implemented Mechanics**
- Turn-based combat system between player and enemy.

- Interactive character creation.

- Enemy selection from a group with polymorphic behavior.

- Weapon selection and switching from the inventory.

- Treasure hunts that grant random weapons.

- Use of unique abilities based on class.

- A blocking system that prevents damage if it was the opponent's last action.

- Custom showStats() and showInventory() methods with detailed output based on character type.

- Robust input validation: does not allow letters or out-of-range options.

### **📈 Applied OOP Concepts**
- Inheritance: The Warrior, Wizard, and Archer classes inherit from Character, reusing and specializing their behavior.

- Polymorphism: Methods such as attack(), showStats(), and showInventory() are executed dynamically based on the object's actual type.

- Pure virtual methods: attack(), showStats(), and showInventory() are defined as pure virtual in Character, forcing each subclass to implement its own version.

- Method overriding: Each subclass redefines its own behavior for inherited methods such as attack() and showStats().

- Operator overloading: The + operator is overloaded to allow weapons to be added to the character's inventory (Character& operator+(Weapon*)).

- Aggregation: Character has a list of Weapon pointers, which can be equipped and queried.

- Abstract classes: Character encapsulates common behaviors, leaving specific details to subclasses.
