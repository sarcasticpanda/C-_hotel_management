#include "Owner.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

extern std::unordered_map<int, int> menuPrices;
extern std::unordered_map<int, std::string> menuItems;
extern std::vector<std::unordered_map<int, int>> orderHistory;

// Function to add an item to the menu
void Owner::addItemToMenu(int itemNumber, const std::string &itemName, int price) {
    if (menuPrices.find(itemNumber) == menuPrices.end()) {
        menuPrices[itemNumber] = price;
        menuItems[itemNumber] = itemName;
        std::cout << "Item added successfully: " << itemName << " - Rs. " << price << "\n";
    } else {
        std::cout << "Item number already exists. Please choose a different number.\n";
    }
}

// Function to remove an item from the menu
void Owner::removeItemFromMenu(int itemNumber) {
    if (menuPrices.erase(itemNumber)) {
        menuItems.erase(itemNumber);
        std::cout << "Item removed successfully.\n";
    } else {
        std::cout << "Item not found in the menu.\n";
    }
}

// Function to view the current menu
void Owner::viewMenu() {
    if (menuItems.empty()) {
        std::cout << "No items in the menu.\n";
        return;
    }

    std::cout << "\n--- Menu ---\n";
    for (const auto& item : menuItems) {
        std::cout << "Item Number: " << item.first << "\n";
        std::cout << "Item Name: " << item.second << "\n";
        std::cout << "Price: Rs. " << menuPrices[item.first] << "\n";
        std::cout << "--------------------\n";
    }
}

// Function to edit the menu (add, remove, or update items)
void Owner::editMenu() {
    int choice;
    do {
        std::cout << "\n--- Menu Management ---\n";
        std::cout << "1. View Menu\n";
        std::cout << "2. Add Item to Menu\n";
        std::cout << "3. Remove Item from Menu\n";
        std::cout << "4. Go Back\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewMenu();
            break;
        case 2:
            {
                int itemNumber, price;
                std::string itemName;
                std::cout << "Enter item number: ";
                std::cin >> itemNumber;
                std::cin.ignore();  // To clear the input buffer
                std::cout << "Enter item name: ";
                std::getline(std::cin, itemName);
                std::cout << "Enter item price: ";
                std::cin >> price;
                addItemToMenu(itemNumber, itemName, price);
            }
            break;
        case 3:
            {
                int itemNumber;
                std::cout << "Enter item number to remove: ";
                std::cin >> itemNumber;
                removeItemFromMenu(itemNumber);
            }
            break;
        case 4:
            std::cout << "Going back to the previous menu...\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (choice != 4);
}

// Function to get mock orders
std::vector<std::string> Owner::getOrders() {
    std::vector<std::string> orders = {"Order1", "Order2", "Order3"}; // Mock orders
    return orders;
}

// Function to edit an order
void Owner::editOrderMenu() {
    int orderNumber, itemNumber, quantity;

    if (orderHistory.empty()) {
        std::cout << "No orders found to edit.\n";
        return;
    }

    std::cout << "\n--- Order History ---\n";
    int orderNumberIndex = 1;

    for (const auto& order : orderHistory) {
        std::cout << "Order #" << orderNumberIndex++ << "\n";
        for (const auto& item : order) {
            std::cout << menuItems[item.first] << "\tQuantity: " << item.second << "\tPrice: Rs. " 
                     << menuPrices[item.first] * item.second << "\n";
        }
        std::cout << "-------------------------------------\n";
    }

    std::cout << "\nEnter the order number you want to edit: ";
    std::cin >> orderNumber;

    if (orderNumber > 0 && orderNumber <= orderHistory.size()) {
        std::unordered_map<int, int>& selectedOrder = orderHistory[orderNumber - 1];

        while (true) {
            std::cout << "\nEnter item number to edit (or 0 to finish): ";
            std::cin >> itemNumber;

            if (itemNumber == 0) break;

            if (selectedOrder.find(itemNumber) != selectedOrder.end()) {
                std::cout << "Current quantity of " << menuItems[itemNumber] << ": " << selectedOrder[itemNumber] << "\n";
                std::cout << "Enter new quantity (0 to remove item): ";
                std::cin >> quantity;

                if (quantity == 0) {
                    selectedOrder.erase(itemNumber);
                    std::cout << "Item removed from order.\n";
                } else {
                    selectedOrder[itemNumber] = quantity;
                    std::cout << "Item quantity updated.\n";
                }
            } else {
                std::cout << "Item not found in the selected order. Try again.\n";
            }
        }
    } else {
        std::cout << "Invalid order number.\n";
    }
}

// Function to view previous orders
void Owner::viewPreviousOrders() {
    if (orderHistory.empty()) {
        std::cout << "No orders found.\n";
        return;
    }

    std::cout << "\n--- Order History ---\n";
    int orderNumber = 1;

    for (const auto& order : orderHistory) {
        std::cout << "Order #" << orderNumber++ << "\n";
        for (const auto& item : order) {
            std::cout << menuItems[item.first] << "\tQuantity: " << item.second << "\tPrice: Rs. " 
                     << menuPrices[item.first] * item.second << "\n";
        }
        std::cout << "-------------------------------------\n";
    }
}
