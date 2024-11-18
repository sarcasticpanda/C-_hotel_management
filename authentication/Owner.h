#ifndef OWNER_H
#define OWNER_H

#include <unordered_map>
#include <string>
#include <vector>

class Owner {
public:
    // Function declarations
    void viewMenu();
    void addItemToMenu(int itemNumber, const std::string &itemName, int price);
    void removeItemFromMenu(int itemNumber);
    void editMenu();
    std::vector<std::string> getOrders();
    void editOrderMenu();
    void viewPreviousOrders();
};

#endif // OWNER_H
