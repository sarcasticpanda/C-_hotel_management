#include "Owner.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

// Global variables used for menu and order management
extern std::unordered_map<int, int> menuPrices;
extern std::unordered_map<int, std::string> menuItems;
extern std::vector<std::unordered_map<int, int>> orderHistory;

// Function to add an item to the menu
void Owner::addItemToMenu(int itemNumber, const std::string &itemName, int price) {
    // Check if the item number is unique
    if (menuPrices.find(itemNumber) == menuPrices.end()) {
        // Add the item to the menu
        menuPrices[itemNumber] = price;
        menuItems[itemNumber] = itemName;
        std::cout << "Item added successfully: " << itemName << " - Rs. " << price << "\n";
    } else {
        // If the item number already exists, notify the user
        std::cout << "Item number already exists. Please choose a different number.\n";
    }
}

// Function to remove an item from the menu
void Owner::removeItemFromMenu(int itemNumber) {
    // Try to erase the item from the menu
    if (menuPrices.erase(itemNumber)) {
        menuItems.erase(itemNumber);
        std::cout << "Item removed successfully.\n";
    } else {
        // If the item wasn't found, let the user know
        std::cout << "Item not found in the menu.\n";
    }
}

// Function to display the current menu
void Owner::viewMenu() {
    // Check if the menu is empty
    if (menuItems.empty()) {
        std::cout << "No items in the menu.\n";
        return;
    }

    // Display all items in the menu
    std::cout << "\n--- Menu ---\n";
    for (const auto &item : menuItems) {
        std::cout << "Item Number: " << item.first << "\n";
        std::cout << "Item Name: " << item.second << "\n";
        std::cout << "Price: Rs. " << menuPrices[item.first] << "\n";
        std::cout << "--------------------\n";
    }
}

// Function to manage the menu (add, remove, or view items)
void Owner::editMenu() {
    int choice;
    do {
        // Show menu management options
        std::cout << "\n--- Menu Management ---\n";
        std::cout << "1. View Menu\n";
        std::cout << "2. Add Item to Menu\n";
        std::cout << "3. Remove Item from Menu\n";
        std::cout << "4. Go Back\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                viewMenu(); // View the current menu
                break;
            case 2: {
                // Add a new item to the menu
                int itemNumber, price;
                std::string itemName;
                std::cout << "Enter item number: ";
                std::cin >> itemNumber;
                std::cin.ignore(); // To clear the input buffer
                std::cout << "Enter item name: ";
                std::getline(std::cin, itemName);
                std::cout << "Enter item price: ";
                std::cin >> price;
                addItemToMenu(itemNumber, itemName, price);
                break;
            }
            case 3: {
                // Remove an item from the menu
                int itemNumber;
                std::cout << "Enter item number to remove: ";
                std::cin >> itemNumber;
                removeItemFromMenu(itemNumber);
                break;
            }
            case 4:
                std::cout << "Going back to the previous menu...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (choice != 4);
}

// Function to retrieve mock orders (placeholder for now)
std::vector<std::string> Owner::getOrders() {
    return {"Order1", "Order2", "Order3"}; // Example orders
}

// Function to display the order history
void Owner::viewOrderHistory() {
    // Check if there are any orders
    if (orderHistory.empty()) {
        std::cout << "No orders found.\n";
        return;
    }

    // Display all orders in the history
    std::cout << "\n--- Order History ---\n";
    int orderNumber = 1;
    for (const auto &order : orderHistory) {
        std::cout << "Order #" << orderNumber++ << "\n";
        for (const auto &item : order) {
            std::cout << menuItems[item.first] << "\tQuantity: " << item.second << "\tPrice: Rs. "
                      << menuPrices[item.first] * item.second << "\n";
        }
        std::cout << "-------------------------------------\n";
    }
}

// Function to edit orders from the order history
void Owner::editOrderMenu() {
    if (orderHistory.empty()) {
        std::cout << "No orders found to edit.\n";
        return;
    }

    // Display all orders for editing
    std::cout << "\n--- Edit Order ---\n";
    int orderNumberIndex = 1;
    for (const auto &order : orderHistory) {
        std::cout << "Order #" << orderNumberIndex++ << "\n";
        for (const auto &item : order) {
            std::cout << menuItems[item.first] << " - Quantity: " << item.second << "\n";
        }
        std::cout << "------------------------------------\n";
    }

    // Prompt user for the order and item to edit
    int orderNumber, itemNumber, quantity;
    std::cout << "Enter the order number to edit: ";
    std::cin >> orderNumber;

    if (orderNumber <= 0 || orderNumber > orderHistory.size()) {
        std::cout << "Invalid order number.\n";
        return;
    }

    std::cout << "Enter the item number to edit: ";
    std::cin >> itemNumber;

    std::cout << "Enter the new quantity: ";
    std::cin >> quantity;

    // Update the item quantity in the selected order
    if (orderHistory[orderNumber - 1].find(itemNumber) != orderHistory[orderNumber - 1].end()) {
        orderHistory[orderNumber - 1][itemNumber] = quantity;
        std::cout << "Item updated in the order.\n";
    } else {
        std::cout << "Item not found in this order.\n";
    }
}
