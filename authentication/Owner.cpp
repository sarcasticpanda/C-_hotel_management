#include "Owner.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// Include the Menu header for accessing Menu-related functionality
extern std::unordered_map<int, int> menuPrices;
extern std::unordered_map<int, std::string> menuItems;
extern std::vector<std::unordered_map<int, int>> orderHistory; // To access order history

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

// Function to get mock orders (could be modified to fetch real orders)
std::vector<std::string> Owner::getOrders() {
    std::vector<std::string> orders = {"Order1", "Order2", "Order3"}; // Mock orders
    return orders;
}

// Function to edit an order (Owner can edit an existing order)
void Owner::editOrderMenu() {
    int orderNumber, itemNumber, quantity;

    // Display order history for the owner
    if (orderHistory.empty()) {
        std::cout << "No orders found to edit.\n";
        return;
    }

    std::cout << "\n--- Order History ---\n";
    int orderNumberIndex = 1;

    // Displaying all orders in orderHistory
    for (const auto& order : orderHistory) {
        std::cout << "Order #" << orderNumberIndex++ << "\n";
        for (const auto& item : order) {
            std::cout << menuItems[item.first] << "\tQuantity: " << item.second << "\tPrice: Rs. " 
                     << menuPrices[item.first] * item.second << "\n";
        }
        std::cout << "-------------------------------------\n";
    }

    // Ask for the order number to edit
    std::cout << "\nEnter the order number you want to edit: ";
    std::cin >> orderNumber;

    if (orderNumber > 0 && orderNumber <= orderHistory.size()) {
        std::unordered_map<int, int>& selectedOrder = orderHistory[orderNumber - 1];

        // Allow the owner to edit the items in the order
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
