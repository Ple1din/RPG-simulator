# RPG-simulator
# 📚 Video Game Character Simulator (RPG Style)

This project is a character simulator based on RPG-style video game logic. It allows you to apply Object-Oriented Programming (OOP) principles, such as inheritance, polymorphism, operator overloading, and exception handling, following good practices.
### 🎮 **Context**
In role-playing video games (RPGs), characters possess attributes, abilities, and items that define their behavior in combat. This simulator allows these interactions to be modeled, facilitating the understanding of key OOP concepts. It also simulates battles between characters by applying comparisons and status restrictions, such as health and weapon availability.

### 📌 **Justification**
This project is interesting because it allows you to observe how theoretical OOP concepts are applied in practical and engaging scenarios. It also encourages the writing of clean, reusable, and secure code, improving modular design and error handling skills.

### 🛠️ **Class Structure and Relationships**

#### **Abstract Class: Character**
- Attributes:
  - `# name: str`
  - `# health: int`
  - `# strength: int`
  - `# inventory: list<Weapon*>`
- Methods:
  - `+ attack(Character)` (abstracto)
  - `+ equipWeapon(Weapon)`
  - `+ heal()`
  - `+ blockAttack()`
  - `+ getName()`
  - `+ setName(string)`
  - `+ getHealth()`
  - `+ setHealth(int)`
  - `+ getStrength()`
  - `+ setStrength(int)`
  - `+ getInventory()`
  - `+ setInventory(list<Weapon*>)`

**Description**: Abstract base class that defines attributes and behaviors common to all characters. This class is inherited by `Warrior`, `Mage`, and `Archer`.

#### **Class: Warrior**
- Inherits from: `Character`
- Methods:
  - `+ attack(Character)`

**Description**: This class inherits from `Character` and implements its own attack logic based on physical strength. It is an aggregator of the `Weapon` class.

#### **Class: Wizard**
- Inherits from: `Character`
- Methods:
  - `+ attack(Character)`

**Description**: This class inherits from `Character` and implements attacks with increased magic damage. It is an add-on to the `Weapon` class.

#### **Class: Archer**
- Inherits from: `Character`
- Methods:
  - `+ attack(Character)`

**Description**: This class inherits from `Character` and implements ranged attacks. It is an add-on to the `Weapon` class.

#### **Class: Weapon**
- Attributes:
  - `- name: str`
  - `- damage: int`
- Methods:
  - `+ attack(Character)`
  - `+ getName()`
  - `+ setName(str)`
  - `+ getDamage()`
  - `+ setDamage(int)`

**Description**: Represents the weapons that characters can use. This class does not inherit from any other class, but is related by aggregation to `Character`.

#### **Custom Exceptions**
- `InsufficientHealthError`: Thrown when a character attempts to attack with low or no health.
- `NoWeaponError`: Thrown when a character attempts to attack without having a weapon equipped.

### 📈 **Implemented Features**
- Inheritance and Polymorphism: The `Warrior`, `Mage`, and `Archer` classes inherit from `Character` and implement their own version of the `attack` method.
- Exception Handling: Use methods to handle logic errors.
- Aggregation: `Character` contains a list of `Weapon` items in its inventory.
