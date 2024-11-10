#ifndef MENU_H
#define MENU_H

#include <unordered_map>

class Menu {
public:
    void displayMenu();
    void calculateBill(const std::unordered_map<int, int>& order);
    void displayStarterMenu();
    void displayMainCourseMenu();
    void displayDessertMenu();
    void customerMenu();
    bool isValidItem(char category, int item);  // Accepts category and item as arguments
};

#endif // MENU_H
