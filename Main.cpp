#include <iostream>
#include "authentication/Authentication.h"

using namespace std;

int main() {
    int roleChoice;
    Authentication auth;

    // Welcome message
    cout << "===================================\n";
    cout << "  Welcome to Hotel Management System\n";
    cout << "===================================\n\n";

    // Role selection prompt
    cout << "Please select your role:\n";
    cout << "1. Customer\n";
    cout << "2. Owner\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> roleChoice;

    // Role-based login/registration
    if (roleChoice == 1) {
        cout << "\n--- Customer Login/Register ---\n";
        if (!auth.registerOrSignIn("customer")) {
            cout << "Failed to sign in as customer.\n";
            return 1;
        }
        cout << "Welcome, Customer! Accessing customer options...\n";
        // Future customer menu code will go here
    } 
    else if (roleChoice == 2) {
        cout << "\n--- Owner Login/Register ---\n";
        if (!auth.registerOrSignIn("owner")) {
            cout << "Failed to sign in as owner.\n";
            return 1;
        }
        cout << "Welcome, Owner! Accessing owner options...\n";
        // Future owner menu code will go here
    } 
    else {
        cout << "Invalid choice. Please restart the program and select a valid option.\n";
    }

    return 0;
}
