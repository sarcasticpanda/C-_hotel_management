#include "Authentication.h"
#include <iostream>

// Registers a customer with username and password
bool Authentication::registerCustomer(const std::string& username, const std::string& password) {
    // Check if the username is already registered in the customerData map
    if (customerData.find(username) != customerData.end()) {
        std::cout << "Username already exists. Please try a different username.\n";
        return false;  // Username already exists in the customer database
    }
    
    // If not, add the new customer to the map with the username as the key and password as the value
    customerData[username] = password;
    std::cout << "Customer registration successful.\n";
    return true;
}

// Validates a customer's login by comparing the entered username and password
bool Authentication::validateCustomer(const std::string& username, const std::string& password) {
    // Check if the username exists in the customer database
    if (customerData.find(username) != customerData.end()) {
        // If username is found, compare the entered password with the stored password
        if (customerData[username] == password) {
            std::cout << "Customer login successful.\n";
            return true;  // Valid login
        } else {
            std::cout << "Incorrect password. Please try again.\n";
            return false;  // Password does not match
        }
    } else {
        std::cout << "Username not found. Please check your username.\n";
        return false;  // Username not found
    }
}

// Registers an owner with username and password
bool Authentication::registerOwner(const std::string& username, const std::string& password) {
    // Check if the username is already registered in the ownerData map
    if (ownerData.find(username) != ownerData.end()) {
        std::cout << "Username already exists. Please try a different username.\n";
        return false;  // Username already exists in the owner database
    }
    
    // If not, add the new owner to the map with the username as the key and password as the value
    ownerData[username] = password;
    std::cout << "Owner registration successful.\n";
    return true;
}

// Validates an owner's login by comparing the entered username and password
bool Authentication::validateOwner(const std::string& username, const std::string& password) {
    // Check if the username exists in the owner database
    if (ownerData.find(username) != ownerData.end()) {
        // If username is found, compare the entered password with the stored password
        if (ownerData[username] == password) {
            std::cout << "Owner login successful.\n";
            return true;  // Valid login
        } else {
            std::cout << "Incorrect password. Please try again.\n";
            return false;  // Password does not match
        }
    } else {
        std::cout << "Username not found. Please check your username.\n";
        return false;  // Username not found
    }
}
