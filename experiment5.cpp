/*
 * =====================================================================================
 * Experiment 5: Runtime Polymorphism - Virtual Functions and Abstract Base Class
 * 
 * Prompt / Objective:
 * 5. Demonstrate runtime polymorphism using virtual functions and an abstract base class. Implement a Shape hierarchy (Circle, Rectangle, Triangle) with an area() method.
 * =====================================================================================
 */

#include <iostream>
#include <cmath>
using namespace std;

// Abstract Base Class
class Shape {
public:
    // Pure virtual function making Shape an abstract class
    virtual double area() const = 0;

    // Virtual function to display the result
    virtual void display() const {
        cout << "Area: " << area() << endl;
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() {}
};

// Derived Class 1: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Overriding the pure virtual function
    double area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        cout << "Circle (Radius = " << radius << ") -> Area: " << area() << endl;
    }
};

// Derived Class 2: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Overriding the pure virtual function
    double area() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle (Length = " << length << ", Width = " << width << ") -> Area: " << area() << endl;
    }
};

// Derived Class 3: Triangle
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    // Overriding the pure virtual function
    double area() const override {
        return 0.5 * base * height;
    }

    void display() const override {
        cout << "Triangle (Base = " << base << ", Height = " << height << ") -> Area: " << area() << endl;
    }
};

int main() {
    // Array of base class pointers
    Shape* shapes[3];

    // Allocating derived class objects dynamically
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Triangle(3.0, 8.0);

    cout << "--- Runtime Polymorphism Demonstration ---" << endl;

    // Calling overridden methods through base class pointers
    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}

/*
Output:
--- Runtime Polymorphism Demonstration ---
Circle (Radius = 5) -> Area: 78.5398
Rectangle (Length = 4, Width = 6) -> Area: 24
Triangle (Base = 3, Height = 8) -> Area: 12
*/
