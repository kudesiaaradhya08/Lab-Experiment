/*
 * =====================================================================================
 * Experiment 6: Compile-time Polymorphism - Function Overloading & Operator Overloading
 * 
 * Prompt / Objective:
 * 6. Implement compile-time polymorphism: function overloading and operator overloading for a Matrix or Complex Number class.
 * =====================================================================================
 */

#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // ---------------------------------------------------------
    // 1. FUNCTION OVERLOADING (Same name, different parameters)
    // ---------------------------------------------------------

    // Add two Complex numbers
    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Add a real (float) number to a Complex number
    Complex add(float val) {
        Complex temp;
        temp.real = real + val;
        temp.imag = imag;
        return temp;
    }

    // ---------------------------------------------------------
    // 2. OPERATOR OVERLOADING (Redefining '+' and '*' operators)
    // ---------------------------------------------------------

    // Overload '+' to add two Complex objects
    Complex operator + (Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Overload '*' to multiply two Complex objects
    // Formula: (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    Complex operator * (Complex c) {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }

    // Display function
    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex result;

    cout << "First Complex Number (c1): ";
    c1.display();
    cout << "Second Complex Number (c2): ";
    c2.display();
    cout << "----------------------------------------" << endl;

    // Demonstrating Function Overloading
    result = c1.add(c2);
    cout << "Function Overloading - add(c2): ";
    result.display();

    result = c1.add(5.0);
    cout << "Function Overloading - add(5.0): ";
    result.display();

    cout << "----------------------------------------" << endl;

    // Demonstrating Operator Overloading
    result = c1 + c2;
    cout << "Operator Overloading (c1 + c2): ";
    result.display();

    result = c1 * c2;
    cout << "Operator Overloading (c1 * c2): ";
    result.display();

    return 0;
}

/*
Output:
First Complex Number (c1): 3 + 4i
Second Complex Number (c2): 1 + 2i
----------------------------------------
Function Overloading - add(c2): 4 + 6i
Function Overloading - add(5.0): 8 + 4i
----------------------------------------
Operator Overloading (c1 + c2): 4 + 6i
Operator Overloading (c1 * c2): -5 + 10i
*/
