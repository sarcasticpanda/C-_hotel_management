#include <iostream>
#include <unordered_map>
#include "Menu.h"
#include "Authentication.h"

using namespace std;

// Function for customer menu
void customerMenu(Menu& menu) {
    unordered_map<int, int> order;  // Store the order in an unordered_map (item number, quantity)
    char sectionChoice;
    int itemNumber, quantity;
    
    cout << "\n=====================================================\n";
    cout << "            Welcome to the Restaurant Ordering System          \n";
    cout << "=====================================================\n";
    cout << "  Select a menu section:\n";
    cout << "    - Press 'S' for Starters\n";
    cout << "    - Press 'M' for Main Course\n";
    cout << "    - Press 'D' for Desserts\n";
    cout << "    - Press 'Q' to finish ordering and view your bill\n";
    cout << "=====================================================\n";

    // Allow the user to select menu sections and add items until they decide to quit
    while (true) {
        cout << "\nChoose a section (S/M/D) or 'Q' to finish ordering: ";
        cin >> sectionChoice;
        sectionChoice = toupper(sectionChoice);

        if (sectionChoice == 'Q') {
            break;  // Exit if the user presses 'Q'
        }

        // Display selected section and handle item selection
        switch (sectionChoice) {
            case 'S':
                cout << "\n--- Starters Menu ---\n";
                menu.displayStarterMenu();
                break;
            case 'M':
                cout << "\n--- Main Course Menu ---\n";
                menu.displayMainCourseMenu();
                break;
            case 'D':
                cout << "\n--- Desserts Menu ---\n";
                menu.displayDessertMenu();
                break;
            default:
                cout << "Invalid section choice. Please try again.\n";
                continue;
        }

        // Allow ordering items within the selected section
        while (true) {
            cout << "\nEnter the item number to add to your order (or '0' to return to sections): ";
            cin >> itemNumber;

            if (itemNumber == 0) {
                break;  // Go back to section menu if user enters 0
            }

            cout << "Enter quantity for item " << itemNumber << ": ";
            cin >> quantity;

            // Add the item to the order or update quantity if already exists
            if (order.find(itemNumber) != order.end()) {
                order[itemNumber] += quantity;
            } else {
                order[itemNumber] = quantity;
            }
        }
    }

    // Show the final combined bill
    menu.calculateBill(order);
}

// Function for owner menu
void ownerMenu() {
    cout << "\n=====================================================\n";
    cout << "                Welcome, Owner!                       \n";
    cout << "=====================================================\n";
    cout << "  Options:\n";
    cout << "    1. View and Edit Orders\n";
    cout << "    2. View Restaurant Statistics\n";
    cout << "    3. Exit\n";
    cout << "=====================================================\n";
    
    int choice;
    cout << "Select an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You can view and manage orders here.\n";
            break;
        case 2:
            cout << "You can view restaurant statistics here.\n";
            break;
        case 3:
            cout << "Exiting Owner menu.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

int main() {
    Authentication auth;  // Create an instance of the Authentication class
    Menu menu;  // Create an instance of the Menu class

    string username, password;
    int userType, actionChoice;

    cout << "=====================================================\n";
    cout << "        Welcome to the Hotel Management System       \n";
    cout << "=====================================================\n";

    // Main loop to allow repeated registration and sign-in
    while (true) {
        // User Authentication: Ask if the user is a customer or an owner
        cout << "\nAre you a customer (1) or an owner (2)? ";
        cin >> userType;

        // Validate input
        if (userType != 1 && userType != 2) {
            cout << "Invalid choice. Exiting...\n";
            return 0;
        }

        // Ask the user whether they want to sign in or register
        cout << "Do you want to (1) Sign In or (2) Register? ";
        cin >> actionChoice;

        if (actionChoice == 1) {  // Sign In Flow
            cout << "\n--- Sign In ---\n";
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            if (userType == 1) {  // Customer Sign In
                if (auth.validateCustomer(username, password)) {
                    cout << "\nCustomer login successful.\n";
                    customerMenu(menu);  // Show customer menu and process order
                } else {
                    cout << "\nInvalid username or password. Please try again.\n";
                }
            } else if (userType == 2) {  // Owner Sign In
                if (auth.validateOwner(username, password)) {
                    cout << "\nOwner login successful.\n";
                    ownerMenu();  // Show owner menu
                } else {
                    cout << "\nInvalid username or password. Please try again.\n";
                }
            }
        } else if (actionChoice == 2) {  // Register Flow
            cout << "\n--- Register ---\n";
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            if (userType == 1) {  // Customer Register
                if (auth.registerCustomer(username, password)) {
                    cout << "\nCustomer registration successful. You can now sign in.\n";
                } else {
                    cout << "\nRegistration failed. Username may already exist.\n";
                }
            } else if (userType == 2) {  // Owner Register
                if (auth.registerOwner(username, password)) {
                    cout << "\nOwner registration successful. You can now sign in.\n";
                } else {
                    cout << "\nRegistration failed. Username may already exist.\n";
                }
            }
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
        
        // Ask if the user wants to go back to the main menu or exit
        cout << "\nPress 1 to go back to the main menu or any other key to exit: ";
        int continueChoice;
        cin >> continueChoice;
        if (continueChoice != 1) {
            cout << "\nExiting program. Goodbye!\n";
            break;
        }
    }

    return 0;
}
