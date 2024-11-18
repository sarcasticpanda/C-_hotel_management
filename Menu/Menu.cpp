#include "Menu.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// Global maps for menu items and prices
unordered_map<int, int> menuPrices = {
    {1, 50}, {2, 30}, {3, 120}, {4, 40}, {5, 25}, {6, 60}, {7, 35}, {8, 40},
    {9, 200}, {10, 350}, {11, 180}, {12, 120}, {13, 30}, {14, 280}, {15, 150}, {16, 100},
    {17, 50}, {18, 70}, {19, 40}, {20, 60}, {21, 80}, {22, 50}, {23, 40}, {24, 90}
};
unordered_map<int, string> menuItems = {
    {1, "Vegetable Pakora"}, {2, "Samosa"}, {3, "Paneer Tikka"}, {4, "Dhokla"},
    {5, "Aloo Tikki"}, {6, "Pav Bhaji"}, {7, "Chana Chaat"}, {8, "Pani Puri"},
    {9, "Chicken Biryani"}, {10, "Mutton Korma"}, {11, "Paneer Butter Masala"}, 
    {12, "Dal Tadka"}, {13, "Tandoori Roti"}, {14, "Butter Chicken"}, 
    {15, "Chole Bhature"}, {16, "Pulao"}, {17, "Gulab Jamun"}, {18, "Ras Malai"}, 
    {19, "Jalebi"}, {20, "Kulfi"}, {21, "Gajar Halwa"}, {22, "Kheer"}, 
    {23, "Ice Cream"}, {24, "Carrot Cake"}
};

// Vector to store order history
vector<unordered_map<int, int>> orderHistory;

// Menu displays
void Menu::displayMenu() {
    cout << "\n--- Welcome to the Restaurant ---\n";
    cout << "|*------------------------MENU-------------------------*|\n";
    displayStarterMenu();
    displayMainCourseMenu();
    displayDessertMenu();
}

void Menu::displayStarterMenu() {
    cout << "\nStarters:\n";
    for (int i = 1; i <= 8; ++i) {
        if (menuPrices.count(i)) {
            cout << "(" << i << ") " << menuItems[i] << " - Rs. " << menuPrices[i] << "\n";
        }
    }
}

void Menu::displayMainCourseMenu() {
    cout << "\nMain Course:\n";
    for (int i = 9; i <= 16; ++i) {
        if (menuPrices.count(i)) {
            cout << "(" << i << ") " << menuItems[i] << " - Rs. " << menuPrices[i] << "\n";
        }
    }
}

void Menu::displayDessertMenu() {
    cout << "\nDesserts:\n";
    for (int i = 17; i <= 24; ++i) {
        if (menuPrices.count(i)) {
            cout << "(" << i << ") " << menuItems[i] << " - Rs. " << menuPrices[i] << "\n";
        }
    }
}

// Customer menu
void Menu::customerMenu() {
    int choice;
    unordered_map<int, int> order;

    cout << "\n--- Customer Menu ---\n";
    cout << "1. View Starters\n";
    cout << "2. View Main Course\n";
    cout << "3. View Desserts\n";
    cout << "4. Calculate Bill\n";
    cout << "5. Edit Order\n";
    cout << "6. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayStarterMenu(); addItemToOrder(order); break;
            case 2: displayMainCourseMenu(); addItemToOrder(order); break;
            case 3: displayDessertMenu(); addItemToOrder(order); break;
            case 4: calculateBill(order); saveOrderHistory(order); break;
            case 5: editOrder(order); break;
            case 6: cout << "Exiting the Customer Menu.\n"; return;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    }
}

// Add items to order
void Menu::addItemToOrder(unordered_map<int, int>& order) {
    int itemNumber, quantity;
    while (true) {
        cout << "Enter item number to add to order (or 0 to stop): ";
        cin >> itemNumber;
        if (itemNumber == 0) break;

        if (menuPrices.count(itemNumber)) {
            cout << "Enter quantity: ";
            cin >> quantity;
            order[itemNumber] += quantity;
            cout << "Item added to your order.\n";
        } else {
            cout << "Invalid item number. Please try again.\n";
        }
    }
}

// Calculate bill
void Menu::calculateBill(const unordered_map<int, int>& order) {
    int total = 0;

    cout << "\n--- Final Bill ---\n";
    cout << "Item\t\tQuantity\tPrice\n";
    cout << "-------------------------------------\n";

    for (const auto& item : order) {
        int itemNumber = item.first;
        int quantity = item.second;

        if (menuPrices.find(itemNumber) != menuPrices.end()) {
            int itemPrice = menuPrices[itemNumber];
            int itemTotal = itemPrice * quantity;

            cout << menuItems[itemNumber] << "\t\t" << quantity << "\t\tRs. " << itemTotal << "\n";
            total += itemTotal;
        }
    }

    cout << "-------------------------------------\n";
    cout << "Total Bill: Rs. " << total << endl;
}

// Save order history
void Menu::saveOrderHistory(const unordered_map<int, int>& order) {
    orderHistory.push_back(order);
    cout << "Order saved to history.\n";
}

// Display order history for owner
void Menu::displayOrderHistory() {
    if (orderHistory.empty()) {
        cout << "No orders found in history.\n";
        return;
    }

    cout << "\n--- Order History ---\n";
    int orderNumber = 1;

    for (const auto& order : orderHistory) {
        cout << "Order #" << orderNumber++ << "\n";
        for (const auto& item : order) {
            cout << menuItems[item.first] << "\tQuantity: " << item.second << "\tPrice: Rs. " 
                 << menuPrices[item.first] * item.second << "\n";
        }
        cout << "-------------------------------------\n";
    }
}

// Edit order
void Menu::editOrder(unordered_map<int, int>& order) {
    int itemNumber, quantity;
    cout << "\n--- Edit Order ---\n";
    cout << "Enter the item number you want to edit (or 0 to finish): ";
    
    while (true) {
        cin >> itemNumber;
        if (itemNumber == 0) break;
        
        if (order.find(itemNumber) != order.end()) {
            cout << "Current quantity of " << menuItems[itemNumber] << ": " << order[itemNumber] << "\n";
            cout << "Enter new quantity (0 to remove item): ";
            cin >> quantity;
            
            if (quantity == 0) {
                order.erase(itemNumber);
                cout << "Item removed from your order.\n";
            } else {
                order[itemNumber] = quantity;
                cout << "Item quantity updated.\n";
            }
        } else {
            cout << "Item not found in your order. Try again.\n";
        }
        cout << "Enter the next item number to edit (or 0 to finish): ";
    }
}

// Functions to add, update, and remove items in the menu (Owner specific)
void Menu::addItem(int itemNumber, const string& itemName, int itemPrice) {
    menuItems[itemNumber] = itemName;
    menuPrices[itemNumber] = itemPrice;
    cout << "Item added successfully.\n";
}

void Menu::updateItem(int itemNumber, const string& newItemName, int newItemPrice) {
    if (menuItems.find(itemNumber) != menuItems.end()) {
        menuItems[itemNumber] = newItemName;
        menuPrices[itemNumber] = newItemPrice;
        cout << "Item updated successfully.\n";
    } else {
        cout << "Item number not found.\n";
    }
}

void Menu::removeItem(int itemNumber) {
    if (menuItems.find(itemNumber) != menuItems.end()) {
        menuItems.erase(itemNumber);
        menuPrices.erase(itemNumber);
        cout << "Item removed successfully.\n";
    } else {
        cout << "Item number not found.\n";
    }
}
