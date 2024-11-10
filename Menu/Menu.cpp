    #include "Menu.h"
    #include <iostream>
    #include <unordered_map>
    using namespace std;

    // Display the full menu with sections
    void Menu::displayMenu() {
        cout << "\n--- Welcome to the Restaurant ---\n";
        cout << "|*------------------------MENU-------------------------*|\n";
        
        displayStarterMenu();
        displayMainCourseMenu();
        displayDessertMenu();
    }

    // Show starter menu
    void Menu::displayStarterMenu() {
        cout << "\nStarters:\n";
        cout << "(1) Vegetable Pakora - Rs. 50\n";
        cout << "(2) Samosa - Rs. 30\n";
        cout << "(3) Paneer Tikka - Rs. 120\n";
        cout << "(4) Dhokla - Rs. 40\n";
        cout << "(5) Aloo Tikki - Rs. 25\n";
        cout << "(6) Pav Bhaji - Rs. 60\n";
        cout << "(7) Chana Chaat - Rs. 35\n";
        cout << "(8) Pani Puri - Rs. 40\n";
    }
void Menu::customerMenu() {
    int choice;
    unordered_map<int, int> order; // Stores item numbers and quantities

    cout << "\n--- Customer Menu ---\n";
    cout << "1. View Starters\n";
    cout << "2. View Main Course\n";
    cout << "3. View Desserts\n";
    cout << "4. Calculate Bill\n";
    cout << "5. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                displayStarterMenu();
                int itemNumber, quantity;
                
                while (true) {
                    cout << "Enter item number to add to order (or 0 to stop): ";
                    cin >> itemNumber;
                    if (itemNumber == 0) break;  // Exit loop to move to the next menu type
                    
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    order[itemNumber] += quantity;  // Add to order
                    cout << "Item added to your order.\n";
                }
                break;
            }
            case 2: {
                displayMainCourseMenu();
                int itemNumber, quantity;
                
                while (true) {
                    cout << "Enter item number to add to order (or 0 to stop): ";
                    cin >> itemNumber;
                    if (itemNumber == 0) break;  // Exit loop to move to the next menu type
                    
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    order[itemNumber] += quantity;  // Add to order
                    cout << "Item added to your order.\n";
                }
                break;
            }
            case 3: {
                displayDessertMenu();
                int itemNumber, quantity;
                
                while (true) {
                    cout << "Enter item number to add to order (or 0 to stop): ";
                    cin >> itemNumber;
                    if (itemNumber == 0) break;  // Exit loop to move to the next menu type
                    
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    order[itemNumber] += quantity;  // Add to order
                    cout << "Item added to your order.\n";
                }
                break;
            }
            case 4:
                calculateBill(order);
                break;
            case 5:
                cout << "Exiting the Customer Menu.\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}


    // Show main course menu
    void Menu::displayMainCourseMenu() {
        cout << "\nMain Course:\n";
        cout << "(1) Chicken Biryani - Rs. 200\n";
        cout << "(2) Mutton Korma - Rs. 350\n";
        cout << "(3) Paneer Butter Masala - Rs. 180\n";
        cout << "(4) Dal Tadka - Rs. 120\n";
        cout << "(5) Tandoori Roti - Rs. 30\n";
        cout << "(6) Butter Chicken - Rs. 280\n";
        cout << "(7) Chole Bhature - Rs. 150\n";
        cout << "(8) Pulao - Rs. 100\n";
    }

    // Show dessert menu
    void Menu::displayDessertMenu() {
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
    bool isValidItem(char category, int item) {
        // Ensure item numbers are valid for the selected category
        if (category == 's' && item >= 1 && item <= 8) return true;  // Starters
        if (category == 'm' && item >= 1 && item <= 8) return true;  // Main Course
        if (category == 'd' && item >= 1 && item <= 8) return true;  // Desserts
        return false;  // Invalid item for the selected category
    }
    // Calculate the total bill based on the order
   void Menu::calculateBill(const std::unordered_map<int, int>& order) {
    int total = 0;

    // Calculate total price based on item number
    for (const auto& item : order) {
        int itemNumber = item.first;
        int quantity = item.second;
        int price = 0;

        // Starters Prices
        if (itemNumber == 1) price = 50;  // Vegetable Pakora
        else if (itemNumber == 2) price = 30;  // Samosa
        else if (itemNumber == 3) price = 120;  // Paneer Tikka
        else if (itemNumber == 4) price = 40;  // Dhokla
        else if (itemNumber == 5) price = 25;  // Aloo Tikki
        else if (itemNumber == 6) price = 60;  // Pav Bhaji
        else if (itemNumber == 7) price = 35;  // Chana Chaat
        else if (itemNumber == 8) price = 40;  // Pani Puri

        // Main Course Prices
        else if (itemNumber == 9) price = 200;  // Chicken Biryani
        else if (itemNumber == 10) price = 350;  // Mutton Korma
        else if (itemNumber == 11) price = 180;  // Paneer Butter Masala
        else if (itemNumber == 12) price = 120;  // Dal Tadka
        else if (itemNumber == 13) price = 30;   // Tandoori Roti
        else if (itemNumber == 14) price = 280;  // Butter Chicken
        else if (itemNumber == 15) price = 150;  // Chole Bhature
        else if (itemNumber == 16) price = 100;  // Pulao

        // Desserts Prices
        else if (itemNumber == 17) price = 50;   // Gulab Jamun
        else if (itemNumber == 18) price = 70;   // Ras Malai
        else if (itemNumber == 19) price = 40;   // Jalebi
        else if (itemNumber == 20) price = 60;   // Kulfi
        else if (itemNumber == 21) price = 80;   // Gajar Halwa
        else if (itemNumber == 22) price = 50;   // Kheer
        else if (itemNumber == 23) price = 40;   // Ice Cream
        else if (itemNumber == 24) price = 90;   // Carrot Cake

        // If an invalid item is encountered, skip it
        if (price == 0) {
            cout << "Invalid item number detected. Skipping item " << itemNumber << ".\n";
            continue;
        }

        // Add the price of the item * quantity to the total
        total += price * quantity;
    }

    // Show the total bill
    cout << "\nYour total bill is: Rs. " << total << endl;
}

