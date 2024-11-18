#ifndef OWNER_H
#define OWNER_H

#include <unordered_map>
#include <string>
#include <vector>

// Forward declarations
class Owner {
public:
    // Function to add, remove, view, and edit menu items
    void addItemToMenu(int itemNumber, const std::string& itemName, int price);
    void removeItemFromMenu(int itemNumber);
    void viewMenu();
    void editMenu();
    void viewPreviousOrders();
    // Function to view order history
    std::vector<std::string> getOrders();
    void viewOrderHistory();
    void editOrderMenu();
};

#endif // OWNER_H
