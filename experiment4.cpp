/*
 * =====================================================================================
 * Experiment 4: Single and Multilevel Inheritance
 * 
 * Prompt / Objective:
 * 4. Implement Single and Multilevel Inheritance for a university management scenario (Person -> Student -> GraduateStudent).
 * =====================================================================================
 */

#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived Class 1: Demonstrates Single Inheritance (Person -> Student)
class Student : public Person {
protected:
    int rollNo;
    string branch;

public:
    Student(string n, int a, int r, string b)
        : Person(n, a), rollNo(r), branch(b) {}

    void displayStudent() {
        displayPerson(); // Reusing base class function
        cout << "Roll Number: " << rollNo << endl;
        cout << "Branch: " << branch << endl;
    }
};

// Derived Class 2: Demonstrates Multilevel Inheritance (Person -> Student -> GraduateStudent)
class GraduateStudent : public Student {
private:
    string researchTopic;
    string advisorName;

public:
    GraduateStudent(string n, int a, int r, string b, string topic, string advisor)
        : Student(n, a, r, b), researchTopic(topic), advisorName(advisor) {}

    void displayGraduateStudent() {
        displayStudent(); // Reusing intermediate class function
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Thesis Advisor: " << advisorName << endl;
    }
};

int main() {
    cout << "=== Single Inheritance (Student) ===" << endl;
    Student ugStudent("Aarav Sharma", 19, 204, "Computer Engineering");
    ugStudent.displayStudent();

    cout << "\n=== Multilevel Inheritance (GraduateStudent) ===" << endl;
    GraduateStudent pgStudent("Priya Nair", 23, 501, "Artificial Intelligence", 
                              "Neural Network Optimization", "Dr. R. K. Verma");
    pgStudent.displayGraduateStudent();

    return 0;
}

/*
Output:
=== Single Inheritance (Student) ===
Name: Aarav Sharma
Age: 19
Roll Number: 204
Branch: Computer Engineering

=== Multilevel Inheritance (GraduateStudent) ===
Name: Priya Nair
Age: 23
Roll Number: 501
Branch: Artificial Intelligence
Research Topic: Neural Network Optimization
Thesis Advisor: Dr. R. K. Verma
*/
