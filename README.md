# RPG-simulator
# 📚 Simulador de Personajes de Videojuego (Estilo RPG)

Este proyecto es un simulador de personajes basado en la lógica de los videojuegos estilo RPG. Permite aplicar los principios de la Programación Orientada a Objetos (POO), como herencia, polimorfismo, sobrecarga de operadores y manejo de excepciones, siguiendo las buenas prácticas de estilo PEP8.

### 🎮 **Contexto**
En los videojuegos de rol (RPG), los personajes poseen atributos, habilidades y objetos que definen su comportamiento en combate. Este simulador permite modelar estas interacciones, facilitando la comprensión de conceptos clave de POO. Además, simula batallas entre personajes aplicando comparaciones y restricciones de estado, como la vida y la disponibilidad de armas.

### 📌 **Justificación**
Este proyecto es interesante porque permite observar cómo los conceptos teóricos de la POO se aplican en escenarios prácticos y atractivos. Además, fomenta la escritura de código limpio, reutilizable y seguro, mejorando las habilidades de diseño modular y manejo de errores.

### 🛠️ **Estructura de Clases y Relaciones**

#### **Clase Abstracta: Personaje**
- Atributos:
  - `+ nombre: str`
  - `+ vida: int`
  - `+ fuerza: int`
  - `+ inventario: list`
- Métodos:
  - `+ atacar(objetivo)` (abstracto)
  - `+ equipar_arma(arma)`
  - `+ __gt__(otro)` (sobrecarga operador `>`)
  - `+ __lt__(otro)` (sobrecarga operador `<`)

**Descripción**: Clase base abstracta que define los atributos y comportamientos comunes a todos los personajes. Esta clase es heredada por `Guerrero`, `Mago` y `Arquero`.

#### **Clase: Guerrero**
- Hereda de: `Personaje`
- Métodos:
  - `+ atacar(objetivo)`

**Descripción**: Esta clase hereda de `Personaje` e implementa su propia lógica de ataque basada en fuerza física. Hace agregación a la clase `Arma`.

#### **Clase: Mago**
- Hereda de: `Personaje`
- Métodos:
  - `+ atacar(objetivo)`

**Descripción**: Esta clase hereda de `Personaje` e implementa ataques con incremento de daño mágico. Hace agregación a la clase `Arma`.

#### **Clase: Arquero**
- Hereda de: `Personaje`
- Métodos:
  - `+ atacar(objetivo)`

**Descripción**: Esta clase hereda de `Personaje` e implementa ataques a distancia. Hace agregación a la clase `Arma`.

#### **Clase: Arma**
- Atributos:
  - `+ nombre: str`
  - `+ danio: int`

**Descripción**: Representa las armas que pueden usar los personajes. Esta clase no hereda de ninguna, pero está relacionada por agregación con `Personaje`.

#### **Excepciones Personalizadas**
- `VidaInsuficienteError`: Se lanza cuando un personaje intenta atacar con poca vida.
- `SinArmaError`: Se lanza cuando un personaje intenta atacar sin haber equipado un arma.

### 📈 **Funcionalidades Implementadas**
- Herencia y Polimorfismo: Clases `Guerrero`, `Mago` y `Arquero` heredan de `Personaje` e implementan su propia versión del método `atacar`.
- Sobrecarga de Operadores: Se sobrecargan los operadores `>` y `<` para comparar la fuerza entre personajes.
- Manejo de Excepciones: Uso de clases personalizadas para controlar errores lógicos.
- Agregación: `Personaje` contiene una lista de objetos `Arma` en su inventario.
