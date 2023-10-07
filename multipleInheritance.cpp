#include <iostream>

// Base class 1
class Animal {
public:
    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }
};

// Base class 2
class Vehicle {
public:
    void drive() {
        std::cout << "Vehicle is driving." << std::endl;
    }
};

// Derived class inheriting from both Animal and Vehicle
class Car : public Animal, public Vehicle {
public:
    void honk() {
        std::cout << "Car is honking." << std::endl;
    }
};

int main() {
    Car myCar;
    myCar.eat();     // Accessing eat() from Animal
    myCar.drive();   // Accessing drive() from Vehicle
    myCar.honk();    // Accessing honk() from Car

    return 0;
}
