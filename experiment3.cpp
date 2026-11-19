/*
 * =====================================================================================
 * Experiment 3: Memory Management & Special Member Functions (Rule of 5)
 * 
 * Prompt / Objective:
 * 3. Implement Rule of 5: Default/Parameterized Constructors, Destructor, Copy Constructor, Copy Assignment, Move Constructor, and Move Assignment for dynamic memory management.
 * =====================================================================================
 */

#include <iostream>
#include <cstring>
#include <utility> // For std::move

class DynamicBuffer {
private:
    char* data;
    size_t size;

public:
    // 1. Default Constructor
    DynamicBuffer() : data(nullptr), size(0) {
        std::cout << "[Default Constructor] Created empty buffer\n";
    }

    // 2. Parameterized Constructor
    DynamicBuffer(const char* str) {
        if (str) {
            size = std::strlen(str);
            data = new char[size + 1]; // +1 for null terminator
            std::strcpy(data, str);
        } else {
            data = nullptr;
            size = 0;
        }
        std::cout << "[Parameterized Constructor] Allocated: " << (data ? data : "null") << "\n";
    }

    // ==========================================
    // THE RULE OF 5 (Special Member Functions)
    // ==========================================

    // I. Destructor
    ~DynamicBuffer() {
        std::cout << "[Destructor] Freeing memory for: " << (data ? data : "null") << "\n";
        delete[] data;
    }

    // II. Copy Constructor (Deep Copy)
    DynamicBuffer(const DynamicBuffer& other) : size(other.size) {
        if (other.data) {
            data = new char[size + 1];
            std::strcpy(data, other.data);
        } else {
            data = nullptr;
        }
        std::cout << "[Copy Constructor] Deep copied: " << (data ? data : "null") << "\n";
    }

    // III. Copy Assignment Operator (Deep Copy)
    DynamicBuffer& operator=(const DynamicBuffer& other) {
        std::cout << "[Copy Assignment] Assigning: " << (other.data ? other.data : "null") << "\n";
        
        // 1. Self-assignment guard
        if (this == &other) {
            return *this;
        }

        // 2. Free existing resource
        delete[] data;

        // 3. Allocate new memory and copy data
        size = other.size;
        if (other.data) {
            data = new char[size + 1];
            std::strcpy(data, other.data);
        } else {
            data = nullptr;
        }

        return *this;
    }

    // IV. Move Constructor (Steals resources)
    DynamicBuffer(DynamicBuffer&& other) noexcept 
        : data(other.data), size(other.size) {
        // Leave the moved-from object in a valid, destructible state
        other.data = nullptr;
        other.size = 0;
        std::cout << "[Move Constructor] Moved resource: " << (data ? data : "null") << "\n";
    }

    // V. Move Assignment Operator (Steals resources)
    DynamicBuffer& operator=(DynamicBuffer&& other) noexcept {
        std::cout << "[Move Assignment] Moving resource: " << (other.data ? other.data : "null") << "\n";
        
        // 1. Self-assignment guard
        if (this == &other) {
            return *this;
        }

        // 2. Free existing resource
        delete[] data;

        // 3. Steal pointers and reset source
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;

        return *this;
    }

    // Helper method to display content
    void print(const char* label) const {
        std::cout << label << ": " << (data ? data : "[Empty]") << " (Size: " << size << ")\n";
    }
};

int main() {
    std::cout << "--- 1. Default & Parameterized ---\n";
    DynamicBuffer buf1;                         // Default
    DynamicBuffer buf2("Hello Engineering!");   // Parameterized

    std::cout << "\n--- 2. Copy Constructor & Copy Assignment ---\n";
    DynamicBuffer buf3 = buf2;                  // Copy Constructor
    buf1 = buf2;                                // Copy Assignment

    std::cout << "\n--- 3. Move Constructor & Move Assignment ---\n";
    DynamicBuffer buf4 = std::move(buf2);       // Move Constructor (buf2 is now empty)
    DynamicBuffer buf5("Temporary");
    buf5 = std::move(buf3);                     // Move Assignment (buf3 is now empty)

    std::cout << "\n--- 4. Final States ---\n";
    buf1.print("buf1");
    buf2.print("buf2 (moved-from)");
    buf3.print("buf3 (moved-from)");
    buf4.print("buf4");
    buf5.print("buf5");

    std::cout << "\n--- 5. Scope Exit (Destructors) ---\n";
    return 0;
}
