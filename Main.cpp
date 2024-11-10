#include <iostream>
#include <unordered_map>
#include "Menu.h"
#include "Authentication.h"

using namespace std;

// Function for customer menu
void customerMenu(Menu& menu) {
    unordered_map<int, int> order;  // Store the order in an unordered_map (item number, quantity)
    int choice;
    int quantity;

    menu.displayMenu();  // Display the menu

    // Allow the user to select items and add them to their order
    while (true) {
        cout << "\nEnter the item number to add to your order (0 to finish): ";
        cin >> choice;

        if (choice == 0) {
            break;  // Exit the loop if the user enters 0
        }

        // Ensure the choice is valid
        if (choice < 1 || choice > 24) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        cout << "Enter the quantity for item " << choice << ": ";
        cin >> quantity;

        // Add the item to the order (if the item already exists, update the quantity)
        if (order.find(choice) != order.end()) {
            order[choice] += quantity;
        } else {
            order[choice] = quantity;
        }
    }

    // Show the final bill
    menu.calculateBill(order);
}

// Function for owner menu
void ownerMenu() {
    cout << "\n--- Welcome, Owner! ---\n";
    cout << "1. View and Edit Orders\n";
    cout << "2. View Restaurant Statistics\n";
    cout << "3. Exit\n";
    int choice;
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

    cout << "--- Welcome to the Hotel Management System ---\n";

    // User Authentication: Ask if the user is a customer or an owner
    cout << "Are you a customer (1) or an owner (2)? ";
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
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        if (userType == 1) {  // Customer Sign In
            if (auth.validateCustomer(username, password)) {
                cout << "Customer login successful.\n";
                customerMenu(menu);  // Show customer menu and process order
            } else {
                cout << "Invalid username or password. Exiting...\n";
            }
        } else if (userType == 2) {  // Owner Sign In
            if (auth.validateOwner(username, password)) {
                cout << "Owner login successful.\n";
                ownerMenu();  // Show owner menu
            } else {
                cout << "Invalid username or password. Exiting...\n";
            }
        }
    } else if (actionChoice == 2) {  // Register Flow
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        if (userType == 1) {  // Customer Register
            if (auth.registerCustomer(username, password)) {
                cout << "Customer registration successful. You can now sign in.\n";
                // Ask the user if they want to sign in after registration
                cout << "Would you like to sign in now? (1 for Yes, 2 for No): ";
                int signInChoice;
                cin >> signInChoice;
                if (signInChoice == 1) {
                    cout << "Enter your username: ";
                    cin >> username;
                    cout << "Enter your password: ";
                    cin >> password;

                    if (auth.validateCustomer(username, password)) {
                        cout << "Customer login successful.\n";
                        customerMenu(menu);  // Show customer menu and process order
                    } else {
                        cout << "Invalid username or password. Exiting...\n";
                    }
                } else {
                    cout << "You can sign in later.\n";
                }
            } else {
                cout << "Registration failed. Username may already exist.\n";
            }
        } else if (userType == 2) {  // Owner Register
            if (auth.registerOwner(username, password)) {
                cout << "Owner registration successful. You can now sign in.\n";
                // Ask the user if they want to sign in after registration
                cout << "Would you like to sign in now? (1 for Yes, 2 for No): ";
                int signInChoice;
                cin >> signInChoice;
                if (signInChoice == 1) {
                    cout << "Enter your username: ";
                    cin >> username;
                    cout << "Enter your password: ";
                    cin >> password;

                    if (auth.validateOwner(username, password)) {
                        cout << "Owner login successful.\n";
                        ownerMenu();  // Show owner menu
                    } else {
                        cout << "Invalid username or password. Exiting...\n";
                    }
                } else {
                    cout << "You can sign in later.\n";
                }
            } else {
                cout << "Registration failed. Username may already exist.\n";
            }
        }
    } else {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}
