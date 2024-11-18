// Owner.h
#ifndef OWNER_H
#define OWNER_H

#include <unordered_map>
#include <string>
#include <vector>

class Owner {
public:
    void addItemToMenu(int itemNumber, const std::string &itemName, int price);
    void removeItemFromMenu(int itemNumber);
    void editOrderMenu();  // Make sure this is declared here
    void viewPreviousOrders();  // And this too
    std::vector<std::string> getOrders();
};

#endif // OWNER_H
