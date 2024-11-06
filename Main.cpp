#include "Authentication.h"
#include "Menu.h"
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    Authentication auth;
    Menu menu;

    // Welcome message
    cout << "\n--- Welcome to the Hotel Management System ---\n";
    cout << "-------------------------------------------------\n";
    
    // Ask user for customer or owner
    int userChoice;
    cout << "Are you a customer or owner?\n";
    cout << "(1) Customer\n";
    cout << "(2) Owner\n";
    cout << "Please enter your choice (1 or 2): ";
    cin >> userChoice;

    if (userChoice == 1) {
        // Customer - Sign In or Register
        int authChoice;
        cout << "\nCustomer Section:\n";
        cout << "1. Sign In\n";
        cout << "2. Register\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> authChoice;
        
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        
        if (authChoice == 1) {
            auth.signIn(username, password);
        } else if (authChoice == 2) {
            auth.registerUser(username, password);
        }

        // Display the menu
        menu.displayMenu();

        // Example of placing an order
        unordered_map<int, int> order;
        int itemNumber, quantity;
        cout << "\nEnter the item number and quantity you want to order (0 to stop):\n";
        while (true) {
            cout << "Item number: ";
            cin >> itemNumber;
            if (itemNumber == 0) break;

            cout << "Quantity: ";
            cin >> quantity;
            
            order[itemNumber] = quantity;
        }

        // Calculate the bill for the order
        menu.calculateBill(order);

    } else if (userChoice == 2) {
        // Owner - Additional options for the owner
        cout << "\nOwner Section:\n";
        cout << "You can manage orders, view reports, etc.\n";
        // Implement owner-specific features here
    } else {
        cout << "\nInvalid choice! Please restart and select a valid option.\n";
    }

    return 0;
}
