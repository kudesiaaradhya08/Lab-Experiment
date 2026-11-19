/*
 * =====================================================================================
 * Experiment 1: Basic C++ Concepts - Variables, Constants, Operators, and I/O Formatting
 * 
 * Prompt / Objective:
 * 1. Demonstrate variables, constants, primitive data types, arithmetic/relational/logical/ternary operators, and formatted I/O.
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class StudentProfile {
private:
    // 1. Constants (cannot be modified after initialization)
    const int MAX_MARKS = 100;
    const float PASS_PERCENTAGE = 40.0f;

    // 2. Variables of different primitive & standard data types
    string studentName;
    int rollNumber;
    char division;
    double subject1Marks, subject2Marks;
    bool isEligibleForScholarship;

public:
    // Input Method (Demonstrates I/O)
    void inputDetails() {
        cout << "Enter Student Full Name: ";
        getline(cin, studentName);

        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "Enter Division (A/B/C): ";
        cin >> division;

        cout << "Enter Marks for Subject 1 (out of " << MAX_MARKS << "): ";
        cin >> subject1Marks;

        cout << "Enter Marks for Subject 2 (out of " << MAX_MARKS << "): ";
        cin >> subject2Marks;
    }

    // Processing & Output Method (Demonstrates Operators & Output formatting)
    void displayReport() {
        // Arithmetic Operators (+, /, *)
        double totalMarks = subject1Marks + subject2Marks;
        double percentage = (totalMarks / (2 * MAX_MARKS)) * 100.0;

        // Relational (>=, ==) and Logical (&&) Operators
        bool isPassed = (percentage >= PASS_PERCENTAGE);
        isEligibleForScholarship = (isPassed && percentage >= 85.0);

        cout << "\n================ STUDENT REPORT ================\n";
        cout << "Name        : " << studentName << "\n";
        cout << "Roll No     : " << rollNumber << " | Division: " << division << "\n";
        cout << fixed << setprecision(2);
        cout << "Total Marks : " << totalMarks << " / " << (2 * MAX_MARKS) << "\n";
        cout << "Percentage  : " << percentage << "%\n";
        
        // Ternary Operator (? :)
        cout << "Result      : " << (isPassed ? "PASS" : "FAIL") << "\n";
        cout << "Scholarship : " << (isEligibleForScholarship ? "Eligible" : "Not Eligible") << "\n";
        cout << "================================================\n";
    }
};

int main() {
    // Creating an object of StudentProfile
    StudentProfile s1;

    s1.inputDetails();
    s1.displayReport();

    return 0;
}
