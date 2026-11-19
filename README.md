# OOP Lab Experiments (C++)

This repository contains 8 C++ lab experiments covering core Object-Oriented Programming (OOP) concepts, memory management, templates, and the Standard Template Library (STL).

---

## Index of Experiments

| Experiment | File | Topic / Description |
| :--- | :--- | :--- |
| **Experiment 1** | [`experiment1.cpp`](experiment1.cpp) | **Basic C++ Concepts & I/O Formatting**<br>Demonstrates `StudentProfile` class, constants, primitive data types, arithmetic/relational/logical/ternary operators, and formatted I/O using `<iomanip>`. |
| **Experiment 2** | [`experiment2.cpp`](experiment2.cpp) | **Encapsulation & Hierarchical Inheritance**<br>Demonstrates access specifiers (`private`, `protected`, `public`) and hierarchical inheritance with `BankAccount` base class and `SavingsAccount` & `CurrentAccount` derived classes. |
| **Experiment 3** | [`experiment3.cpp`](experiment3.cpp) | **Memory Management & The Rule of 5**<br>Demonstrates `DynamicBuffer` class with Default/Parameterized constructors, Destructor, Deep Copy constructor/assignment, and Move constructor/assignment (`std::move`). |
| **Experiment 4** | [`experiment4.cpp`](experiment4.cpp) | **Single & Multilevel Inheritance**<br>Demonstrates single and multilevel inheritance hierarchy in a university scenario: `Person` &rarr; `Student` &rarr; `GraduateStudent`. |
| **Experiment 5** | [`experiment5.cpp`](experiment5.cpp) | **Runtime Polymorphism & Abstract Base Class**<br>Demonstrates abstract base class `Shape` with pure virtual function `area()`, overridden by `Circle`, `Rectangle`, and `Triangle`, dispatched through base class pointers. |
| **Experiment 6** | [`experiment6.cpp`](experiment6.cpp) | **Compile-Time Polymorphism**<br>Demonstrates function overloading (`add()`) and operator overloading (`operator+`, `operator*`) for a `Complex` number class. |
| **Experiment 7** | [`experiment7.cpp`](experiment7.cpp) | **Generic Programming with Templates**<br>Demonstrates a generic `Stack<T>` class template tested with `int`, `float`, and `std::string`. |
| **Experiment 8** | [`experiment8.cpp`](experiment8.cpp) | **Standard Template Library (STL)**<br>Demonstrates STL sequence container (`std::vector`), associative containers (`std::map`, `std::unordered_map`), and algorithms (`std::sort`, `std::find_if`, `std::transform`) in a `ResultProcessor` system. |

---

## Compilation & Execution

Compile any experiment using a modern C++ compiler (`g++` or `clang++` with C++17 or later):

```bash
# Example: Compile Experiment 1
clang++ -std=c++17 experiment1.cpp -o exp1
./exp1

# Example: Compile Experiment 7
clang++ -std=c++17 experiment7.cpp -o exp7
./exp7
```
