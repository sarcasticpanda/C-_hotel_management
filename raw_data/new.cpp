class Restaurant {
private:
    std::string restaurantName;  // Name of the restaurant
    std::string address;         // Restaurant address
    std::string contactNumber;   // Contact number for inquiries or orders
    std::vector<MenuItem> menu;  // A list of all menu items

public:
    // Constructor
    Restaurant(std::string name, std::string address, std::string contactNumber)
        : restaurantName(name), address(address), contactNumber(contactNumber) {}

    // Getters
    std::string getRestaurantName() const { return restaurantName; }
    std::string getAddress() const { return address; }
    std::string getContactNumber() const { return contactNumber; }

    // Setters (if you want to allow updating these details)
    void setRestaurantName(std::string newName) { restaurantName = newName; }
    void setAddress(std::string newAddress) { address = newAddress; }
    void setContactNumber(std::string newContactNumber) { contactNumber = newContactNumber; }

    // Add a new menu item to the menu
    void addMenuItem(const MenuItem& item) {
        menu.push_back(item);
    }

    // Display all menu items
    void displayMenu() const {
        std::cout << "Menu for " << restaurantName << ":\n";
        for (const auto& item : menu) {
            item.displayItem();
            std::cout << "--------------------------" << std::endl;
        }
    }
    
    // Find menu item by ID
    MenuItem* findMenuItemById(int id) {
        for (auto& item : menu) {
            if (item.getId() == id) {
                return &item;
            }
        }
        return nullptr;  // Return null if not found
    }

    // Display restaurant details
    void displayRestaurantDetails() const {
        std::cout << "Restaurant Name: " << restaurantName
                  << "\nAddress: " << address
                  << "\nContact Number: " << contactNumber << std::endl;
    }
};
