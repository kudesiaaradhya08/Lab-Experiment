/*
 * =====================================================================================
 * Experiment 2: Encapsulation & Inheritance - Access Specifiers and Hierarchical Inheritance
 * 
 * Prompt / Objective:
 * 2. Demonstrate access specifiers (private, protected, public) and hierarchical inheritance using BankAccount, SavingsAccount, and CurrentAccount classes.
 * =====================================================================================
 */

#include <iostream>
#include <string>
using namespace std;

// Base Class
class BankAccount {
private:
    // Private: Accessible ONLY inside BankAccount (Strict Encapsulation)
    string accountNumber;

protected:
    // Protected: Accessible inside BankAccount AND derived classes
    string holderName;
    double balance;

public:
    // Constructor to initialize base attributes
    BankAccount(string accNum, string name, double initialBalance) {
        accountNumber = accNum;
        holderName = name;
        balance = initialBalance;
    }

    // Public Member Functions: Accessible from anywhere (e.g., main)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: Rs. " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void displayDetails() {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << holderName << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

// Derived Class 1: Hierarchical Inheritance
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Calling Base Class Constructor
    SavingsAccount(string accNum, string name, double initialBalance, double rate)
        : BankAccount(accNum, name, initialBalance) {
        interestRate = rate;
    }

    // Member function accessing 'protected' balance from base class
    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added at " << interestRate << "%: Rs. " << interest << endl;
    }

    void displayDetails() override {
        cout << "\n--- Savings Account Details ---" << endl;
        BankAccount::displayDetails(); // Calling base class member function
        cout << "Interest Rate  : " << interestRate << "%" << endl;
    }
};

// Derived Class 2: Hierarchical Inheritance
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNum, string name, double initialBalance, double limit)
        : BankAccount(accNum, name, initialBalance) {
        overdraftLimit = limit;
    }

    // Member function demonstrating access to protected 'balance'
    void withdraw(double amount) {
        if (amount > 0 && (balance + overdraftLimit) >= amount) {
            balance -= amount;
            cout << "Withdrawn: Rs. " << amount << endl;
        } else {
            cout << "Withdrawal failed! Exceeds overdraft limit." << endl;
        }
    }

    void displayDetails() override {
        cout << "\n--- Current Account Details ---" << endl;
        BankAccount::displayDetails();
        cout << "Overdraft Limit: Rs. " << overdraftLimit << endl;
    }
};

// Main Function
int main() {
    // Creating Derived Class Objects
    SavingsAccount sav("SAV1001", "Aarav Sharma", 10000.0, 4.5);
    CurrentAccount cur("CUR2001", "Tech Solutions Pvt Ltd", 25000.0, 10000.0);

    // Demonstrating Public Member Functions on Savings Account
    sav.displayDetails();
    sav.deposit(2000.0);
    sav.addInterest();
    sav.displayDetails();

    // Demonstrating Public Member Functions on Current Account
    cur.displayDetails();
    cur.withdraw(30000.0); // Uses Rs. 5000 from overdraft limit
    cur.displayDetails();

    // Note: The following lines would cause a compiler error due to access specifiers:
    // sav.accountNumber = "123"; // Error: 'accountNumber' is private
    // sav.balance = 50000;       // Error: 'balance' is protected

    return 0;
}
