// Menu.cpp
#include "Menu.h"
#include <iostream>
#include <unordered_map>
using namespace std;

void Menu::displayMenu() {
    cout << "\n--- Welcome to the Restaurant ---\n";
    cout << "|*------------------------MENU-------------------------*|\n";
    
    cout << "\nStarters:\n";
    cout << "(1) Vegetable Pakora - Rs. 50\n";
    cout << "(2) Samosa - Rs. 30\n";
    cout << "(3) Paneer Tikka - Rs. 120\n";
    cout << "(4) Dhokla - Rs. 40\n";
    cout << "(5) Aloo Tikki - Rs. 25\n";
    cout << "(6) Pav Bhaji - Rs. 60\n";
    cout << "(7) Chana Chaat - Rs. 35\n";
    cout << "(8) Pani Puri - Rs. 40\n";

    cout << "\nMain Course:\n";
    cout << "(1) Chicken Biryani - Rs. 200\n";
    cout << "(2) Mutton Korma - Rs. 350\n";
    cout << "(3) Paneer Butter Masala - Rs. 180\n";
    cout << "(4) Dal Tadka - Rs. 120\n";
    cout << "(5) Tandoori Roti - Rs. 30\n";
    cout << "(6) Butter Chicken - Rs. 280\n";
    cout << "(7) Chole Bhature - Rs. 150\n";
    cout << "(8) Pulao - Rs. 100\n";

    cout << "\nDesserts:\n";
    cout << "(1) Gulab Jamun - Rs. 50\n";
    cout << "(2) Ras Malai - Rs. 70\n";
    cout << "(3) Jalebi - Rs. 40\n";
    cout << "(4) Kulfi - Rs. 60\n";
    cout << "(5) Gajar Halwa - Rs. 80\n";
    cout << "(6) Kheer - Rs. 50\n";
    cout << "(7) Ice Cream - Rs. 40\n";
    cout << "(8) Carrot Cake - Rs. 90\n";
}

void Menu::calculateBill(const unordered_map<int, int>& order) {
    int totalBill = 0;
    cout << "\n--- Your Bill ---\n";
    
    // Calculate total bill based on the order
    for (const auto& item : order) {
        int itemNumber = item.first;
        int quantity = item.second;
        
        // Example: Add prices for items (for simplicity, I assume fixed prices)
        switch (itemNumber) {
            case 1: totalBill += 50 * quantity; break; // Vegetable Pakora
            case 2: totalBill += 30 * quantity; break; // Samosa
            case 3: totalBill += 120 * quantity; break; // Paneer Tikka
            case 4: totalBill += 40 * quantity; break; // Dhokla
            case 5: totalBill += 25 * quantity; break; // Aloo Tikki
            case 6: totalBill += 60 * quantity; break; // Pav Bhaji
            case 7: totalBill += 35 * quantity; break; // Chana Chaat
            case 8: totalBill += 40 * quantity; break; // Pani Puri
            case 9: totalBill += 200 * quantity; break; // Chicken Biryani
            case 10: totalBill += 350 * quantity; break; // Mutton Korma
            case 11: totalBill += 180 * quantity; break; // Paneer Butter Masala
            case 12: totalBill += 120 * quantity; break; // Dal Tadka
            case 13: totalBill += 30 * quantity; break; // Tandoori Roti
            case 14: totalBill += 280 * quantity; break; // Butter Chicken
            case 15: totalBill += 150 * quantity; break; // Chole Bhature
            case 16: totalBill += 100 * quantity; break; // Pulao
            case 17: totalBill += 50 * quantity; break; // Gulab Jamun
            case 18: totalBill += 70 * quantity; break; // Ras Malai
            case 19: totalBill += 40 * quantity; break; // Jalebi
            case 20: totalBill += 60 * quantity; break; // Kulfi
            case 21: totalBill += 80 * quantity; break; // Gajar Halwa
            case 22: totalBill += 50 * quantity; break; // Kheer
            case 23: totalBill += 40 * quantity; break; // Ice Cream
            case 24: totalBill += 90 * quantity; break; // Carrot Cake
        }
    }

    cout << "Total Bill: Rs. " << totalBill << endl;
}
