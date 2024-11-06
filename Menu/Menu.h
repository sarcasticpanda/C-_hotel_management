// Menu.h
#ifndef MENU_H
#define MENU_H

#include <unordered_map>

class Menu {
public:
    void displayMenu();
    void calculateBill(const std::unordered_map<int, int>& order);
};

#endif
