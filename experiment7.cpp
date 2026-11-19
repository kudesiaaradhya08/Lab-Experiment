/*
 * =====================================================================================
 * Experiment 7: Generic Programming with Class Templates (Stack)
 * 
 * Prompt / Objective:
 * 7. Write a generic Stack or Queue class using templates. Test with int, float, and std::string
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <stdexcept>

// Template declaration for a generic Stack class
template <typename T>
class Stack {
private:
    T* arr;           // Pointer to dynamic array
    int topIndex;     // Index of the top element
    int capacity;     // Maximum capacity of the stack

public:
    // Parameterized Constructor
    Stack(int size = 5) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    // Destructor to free dynamically allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return topIndex == capacity - 1;
    }

    // Push an element onto the stack
    void push(const T& element) {
        if (isFull()) {
            throw std::overflow_error("Stack Overflow: Cannot push onto a full stack.");
        }
        arr[++topIndex] = element;
    }

    // Pop an element from the stack
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: Cannot pop from an empty stack.");
        }
        return arr[topIndex--];
    }

    // Peek at the top element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: Nothing to peek.");
        }
        return arr[topIndex];
    }

    // Display all elements in the stack
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack elements (top to bottom): ";
        for (int i = topIndex; i >= 0; --i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    try {
        // 1. Testing with int
        std::cout << "=== Testing Stack with int ===" << std::endl;
        Stack<int> intStack(3);
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.display();
        std::cout << "Top element: " << intStack.peek() << std::endl;
        std::cout << "Popped: " << intStack.pop() << std::endl;
        intStack.display();
        std::cout << std::endl;

        // 2. Testing with float
        std::cout << "=== Testing Stack with float ===" << std::endl;
        Stack<float> floatStack(3);
        floatStack.push(1.5f);
        floatStack.push(2.75f);
        floatStack.push(9.99f);
        floatStack.display();
        std::cout << "Top element: " << floatStack.peek() << std::endl;
        std::cout << "Popped: " << floatStack.pop() << std::endl;
        floatStack.display();
        std::cout << std::endl;

        // 3. Testing with std::string
        std::cout << "=== Testing Stack with std::string ===" << std::endl;
        Stack<std::string> stringStack(3);
        stringStack.push("Data Structures");
        stringStack.push("OOP");
        stringStack.push("C++");
        stringStack.display();
        std::cout << "Top element: " << stringStack.peek() << std::endl;
        std::cout << "Popped: " << stringStack.pop() << std::endl;
        stringStack.display();

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

/*
Output:
=== Testing Stack with int ===
Stack elements (top to bottom): 30 20 10 
Top element: 30
Popped: 30
Stack elements (top to bottom): 20 10 

=== Testing Stack with float ===
Stack elements (top to bottom): 9.99 2.75 1.5 
Top element: 9.99
Popped: 9.99
Stack elements (top to bottom): 2.75 1.5 

=== Testing Stack with std::string ===
Stack elements (top to bottom): C++ OOP Data Structures 
Top element: C++
Popped: C++
Stack elements (top to bottom): OOP Data Structures
*/
