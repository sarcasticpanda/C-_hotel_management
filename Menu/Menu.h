#ifndef MENU_H
#define MENU_H

#include <unordered_map>

class Menu {
public:
    // Display the full menu with sections
    void displayMenu();
    
    // Calculate the total bill based on the order
    void calculateBill(const std::unordered_map<int, int>& order);

private:
    // Display menu sections
    void displayStarterMenu();
    void displayMainCourseMenu();
    void displayDessertMenu();
};

#endif // MENU_H
