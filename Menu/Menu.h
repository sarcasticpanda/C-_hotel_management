#ifndef MENU_H
#define MENU_H

#include <unordered_map>

class Menu {
public:
    void displayMenu();  // Displays the full menu with categories
    void calculateBill(const std::unordered_map<int, int>& order);  // Calculates the total bill based on items ordered
    void displayStarterMenu();  // Displays starter items
    void displayMainCourseMenu();  // Displays main course items
    void displayDessertMenu();  // Displays dessert items
    void customerMenu();  // Handles customer interaction with menu options
    bool isValidItem(char category, int item);  // Checks if an item is valid based on its category
};

#endif // MENU_H
