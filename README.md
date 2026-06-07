# C++ Object-Oriented Programming Labs

## Overview

This repository contains a collection of educational projects developed to practice object-oriented programming concepts in C++.

The assignments focus on inheritance, polymorphism, dynamic memory management, operator overloading, and simulation modeling.

## Projects

### 1. Zoo Management System

A simulation of a zoo using inheritance and polymorphism.

#### Features

* Base class `Animal`
* Derived classes such as:

  * Lion
  * Elephant
  * Parrot
* Common animal properties:

  * Name
  * Age
* Animal-specific behavior through the `makeSound()` method
* Dynamic creation of objects using pointers
* Storage of different animal types in a single collection

#### OOP Concepts

* Inheritance
* Polymorphism
* Virtual methods
* Dynamic memory allocation

---

### 2. City Life Simulation

A simple simulation involving different city residents:

* Grandmother
* Doctor
* Musician

Each character performs a unique activity:

* Grandmother bakes pies
* Doctor treats people
* Musician plays the violin

Residents gradually lose energy while working and may regain energy through interactions with others.

The simulation continues until only one resident remains in the city.

#### OOP Concepts

* Class interaction
* Encapsulation
* Object collaboration
* Simulation modeling

---

### 3. Fraction Class

Implementation of a mathematical fraction class with overloaded operators.

#### Supported Operations

* Addition (`+`)
* Subtraction (`-`)
* Multiplication (`*`)
* Division (`/`)

#### OOP Concepts

* Operator overloading
* Class design
* Encapsulation
* Arithmetic abstractions

---

## Technologies

* C++
* Classes and Objects
* Inheritance
* Polymorphism
* Operator Overloading
* Dynamic Memory Management
* STL Containers

## Learning Objectives

This repository demonstrates:

* Building class hierarchies
* Working with virtual functions
* Modeling real-world entities using OOP
* Implementing custom operators
* Managing dynamically allocated objects
* Designing interactive object systems

## Compilation

Compile any project using a standard C++ compiler:

```bash
g++ source.cpp -o program
./program
```

## Author

Educational projects developed for studying object-oriented programming in C++.
