/*
 * =====================================================================================
 * Experiment 8: Standard Template Library (STL) - Containers and Algorithms
 * 
 * Prompt / Objective:
 * 8. Implement STL containers (vector, map, unordered_map) and algorithms (sort, find_if, transform) for student records management.
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

// Class representing a single Student entity (OOP Encapsulation)
class Student {
private:
    int rollNo;
    string name;
    string department;
    double marks;

public:
    Student(int r, string n, string dept, double m)
        : rollNo(r), name(n), department(dept), marks(m) {}

    // Getters
    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    double getMarks() const { return marks; }

    // Display helper
    void display() const {
        cout << left << setw(8) << rollNo
             << setw(15) << name
             << setw(10) << department
             << fixed << setprecision(2) << marks << endl;
    }
};

// Manager class to process the dataset using STL containers and algorithms
class ResultProcessor {
private:
    vector<Student> studentList;                 // Stores primary dataset dynamically
    unordered_map<int, Student*> rollLookup;     // O(1) fast lookup by Roll Number
    map<string, int> deptCount;                  // Sorted frequency count by Department

public:
    // Add student and populate associative containers
    void addStudent(const Student& s) {
        studentList.push_back(s);
    }

    // Build lookup maps after all students are added (prevents pointer invalidation on vector resize)
    void buildIndexes() {
        rollLookup.clear();
        deptCount.clear();
        for (auto& s : studentList) {
            rollLookup[s.getRollNo()] = &s;
            deptCount[s.getDepartment()]++;
        }
    }

    // 1. std::sort -> Sort students by marks in descending order
    void sortByMarksDescending() {
        sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
            return a.getMarks() > b.getMarks();
        });
        buildIndexes(); // Re-sync pointers after sorting
    }

    // 2. std::find_if -> Find the first student scoring above a threshold
    void findTopScorerAbove(double threshold) const {
        auto it = find_if(studentList.begin(), studentList.end(), [threshold](const Student& s) {
            return s.getMarks() > threshold;
        });

        cout << "\n--- Search Result (Marks > " << threshold << ") ---\n";
        if (it != studentList.end()) {
            it->display();
        } else {
            cout << "No student found above " << threshold << endl;
        }
    }

    // 3. std::transform -> Convert raw marks (out of 100) into CGPA (10-point scale)
    void displayCGPAList() const {
        vector<double> cgpaList(studentList.size());

        transform(studentList.begin(), studentList.end(), cgpaList.begin(), [](const Student& s) {
            return s.getMarks() / 10.0;
        });

        cout << "\n--- Transformed CGPA List (10-Point Scale) ---\n";
        for (size_t i = 0; i < studentList.size(); ++i) {
            cout << studentList[i].getName() << " : " << fixed << setprecision(2) << cgpaList[i] << " CGPA\n";
        }
    }

    // 4. std::unordered_map -> Fast O(1) lookup by Roll Number
    void searchByRollNo(int roll) const {
        cout << "\n--- Fast Lookup for Roll No: " << roll << " ---\n";
        auto it = rollLookup.find(roll);
        if (it != rollLookup.end()) {
            it->second->display();
        } else {
            cout << "Roll Number " << roll << " not found.\n";
        }
    }

    // 5. std::map -> Display department-wise student count (automatically sorted alphabetically)
    void displayDepartmentSummary() const {
        cout << "\n--- Department-Wise Student Count (Sorted by Dept) ---\n";
        for (const auto& pair : deptCount) {
            cout << pair.first << " : " << pair.second << " student(s)\n";
        }
    }

    // Display complete table
    void displayAll() const {
        cout << "\n" << left << setw(8) << "Roll" << setw(15) << "Name" << setw(10) << "Dept" << "Marks\n";
        cout << string(40, '-') << "\n";
        for (const auto& s : studentList) {
            s.display();
        }
    }
};

int main() {
    ResultProcessor rp;

    // Sample dataset
    rp.addStudent(Student(101, "Aarav", "COMP", 88.5));
    rp.addStudent(Student(102, "Diya", "IT", 94.0));
    rp.addStudent(Student(103, "Rohan", "ENTC", 76.0));
    rp.addStudent(Student(104, "Sneha", "COMP", 91.5));
    rp.addStudent(Student(105, "Kabir", "IT", 68.0));

    rp.buildIndexes();

    cout << "=== ORIGINAL STUDENT DATASET ===";
    rp.displayAll();

    // Sort using std::sort
    rp.sortByMarksDescending();
    cout << "\n=== RANK LIST (SORTED BY MARKS DESCENDING) ===";
    rp.displayAll();

    // Search using std::find_if
    rp.findTopScorerAbove(90.0);

    // Transform using std::transform
    rp.displayCGPAList();

    // O(1) lookup using std::unordered_map
    rp.searchByRollNo(104);

    // Sorted summary using std::map
    rp.displayDepartmentSummary();

    return 0;
}
