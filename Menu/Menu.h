#ifndef MENU_H
#define MENU_H

#include <unordered_map>
#include <string>

class Menu {
public:
    void displayMenu();
    void displayStarterMenu();
    void displayMainCourseMenu();
    void displayDessertMenu();
    void customerMenu();
    void addItemToOrder(std::unordered_map<int, int>& order);
    void calculateBill(const std::unordered_map<int, int>& order);
    void saveOrderHistory(const std::unordered_map<int, int>& order);
    void displayOrderHistory();
    void editOrder(std::unordered_map<int, int>& order);
    void addItem(int itemNumber, const std::string& itemName, int itemPrice);
    void updateItem(int itemNumber, const std::string& newItemName, int newItemPrice);
    void removeItem(int itemNumber);
};

#endif // MENU_H
