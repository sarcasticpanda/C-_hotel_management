#include "Menu.h"
#include <iostream>
#include <unordered_map>
using namespace std;

// Display the entire menu, organized by sections
void Menu::displayMenu() {
    cout << "\n--- Welcome to the Restaurant ---\n";
    cout << "|*------------------------MENU-------------------------*|\n";
    
    displayStarterMenu();
    displayMainCourseMenu();
    displayDessertMenu();
}

// Display starters menu items
void Menu::displayStarterMenu() {
    cout << "\nStarters:\n";
    cout << "(1) Vegetable Pakora - Rs. 50\n";
    cout << "(2) Samosa - Rs. 30\n";
    cout << "(3) Paneer Tikka - Rs. 120\n";
    cout << "(4) Dhokla - Rs. 40\n";
    cout << "(5) Aloo Tikki - Rs. 25\n";
    cout << "(6) Pav Bhaji - Rs. 60\n";
    cout << "(7) Chana Chaat - Rs. 35\n";
    cout << "(8) Pani Puri - Rs. 40\n";
}

// Customer menu for viewing, ordering items, and calculating bills
void Menu::customerMenu() {
    int choice;
    unordered_map<int, int> order; // Store item numbers and their quantities

    cout << "\n--- Customer Menu ---\n";
    cout << "1. View Starters\n";
    cout << "2. View Main Course\n";
    cout << "3. View Desserts\n";
    cout << "4. Calculate Bill\n";
    cout << "5. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                displayStarterMenu();
                int itemNumber, quantity;
                
                while (true) {
                    cout << "Enter item number to add to order (or 0 to stop): ";
                    cin >> itemNumber;
                    if (itemNumber == 0) break;
                    
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    order[itemNumber] += quantity;  // Add item to order
                    cout << "Item added to your order.\n";
                }
                break;
            }
            case 2: {
                displayMainCourseMenu();
                int itemNumber, quantity;
                
                while (true) {
                    cout << "Enter item number to add to order (or 0 to stop): ";
                    cin >> itemNumber;
                    if (itemNumber == 0) break;
                    
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    order[itemNumber] += quantity;
                    cout << "Item added to your order.\n";
                }
                break;
            }
            case 3: {
                displayDessertMenu();
                int itemNumber, quantity;
                
                while (true) {
                    cout << "Enter item number to add to order (or 0 to stop): ";
                    cin >> itemNumber;
                    if (itemNumber == 0) break;
                    
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    order[itemNumber] += quantity;
                    cout << "Item added to your order.\n";
                }
                break;
            }
            case 4:
                calculateBill(order);
                break;
            case 5:
                cout << "Exiting the Customer Menu.\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

// Display main course menu items
void Menu::displayMainCourseMenu() {
    cout << "\nMain Course:\n";
    cout << "(1) Chicken Biryani - Rs. 200\n";
    cout << "(2) Mutton Korma - Rs. 350\n";
    cout << "(3) Paneer Butter Masala - Rs. 180\n";
    cout << "(4) Dal Tadka - Rs. 120\n";
    cout << "(5) Tandoori Roti - Rs. 30\n";
    cout << "(6) Butter Chicken - Rs. 280\n";
    cout << "(7) Chole Bhature - Rs. 150\n";
    cout << "(8) Pulao - Rs. 100\n";
}

// Display dessert menu items
void Menu::displayDessertMenu() {
    cout << "\nDesserts:\n";
    cout << "(1) Gulab Jamun - Rs. 50\n";
    cout << "(2) Ras Malai - Rs. 70\n";
    cout << "(3) Jalebi - Rs. 40\n";
    cout << "(4) Kulfi - Rs. 60\n";
    cout << "(5) Gajar Halwa - Rs. 80\n";
    cout << "(6) Kheer - Rs. 50\n";
    cout << "(7) Ice Cream - Rs. 40\n";
    cout << "(8) Carrot Cake - Rs. 90\n";
}

// Ensure item is valid for selected category
bool isValidItem(char category, int item) {
    if (category == 's' && item >= 1 && item <= 8) return true;
    if (category == 'm' && item >= 1 && item <= 8) return true;
    if (category == 'd' && item >= 1 && item <= 8) return true;
    return false;
}

// Calculate and display the total bill based on the order
void Menu::calculateBill(const std::unordered_map<int, int>& order) {
    int total = 0;

    // Calculate price based on item number and quantity ordered
    for (const auto& item : order) {
        int itemNumber = item.first;
        int quantity = item.second;
        int price = 0;

        // Assign prices based on item number
        // Starters
        if (itemNumber == 1) price = 50;
        else if (itemNumber == 2) price = 30;
        else if (itemNumber == 3) price = 120;
        else if (itemNumber == 4) price = 40;
        else if (itemNumber == 5) price = 25;
        else if (itemNumber == 6) price = 60;
        else if (itemNumber == 7) price = 35;
        else if (itemNumber == 8) price = 40;
        // Main Course
        else if (itemNumber == 9) price = 200;
        else if (itemNumber == 10) price = 350;
        else if (itemNumber == 11) price = 180;
        else if (itemNumber == 12) price = 120;
        else if (itemNumber == 13) price = 30;
        else if (itemNumber == 14) price = 280;
        else if (itemNumber == 15) price = 150;
        else if (itemNumber == 16) price = 100;
        // Desserts
        else if (itemNumber == 17) price = 50;
        else if (itemNumber == 18) price = 70;
        else if (itemNumber == 19) price = 40;
        else if (itemNumber == 20) price = 60;
        else if (itemNumber == 21) price = 80;
        else if (itemNumber == 22) price = 50;
        else if (itemNumber == 23) price = 40;
        else if (itemNumber == 24) price = 90;

        if (price == 0) {
            cout << "Invalid item number detected. Skipping item " << itemNumber << ".\n";
            continue;
        }

        total += price * quantity; // Add to total bill
    }

    cout << "\nYour total bill is: Rs. " << total << endl;
}