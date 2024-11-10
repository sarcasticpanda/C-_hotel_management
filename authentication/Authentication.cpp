#include "Authentication.h"
#include <iostream>
#include <unordered_map>

using namespace std;

// Example hardcoded customer credentials
unordered_map<string, string> customerCredentials = {
    {"customer1", "pass123"},
    {"customer2", "mypassword"}
};

// Example hardcoded owner credentials
unordered_map<string, string> ownerCredentials = {
    {"owner1", "admin123"},
    {"owner2", "ownerpassword"}
};

// Validate customer credentials
bool Authentication::validateCustomer(const string& username, const string& password) {
    if (customerCredentials.find(username) != customerCredentials.end()) {
        return customerCredentials[username] == password;
    }
    return false;
}

// Validate owner credentials
bool Authentication::validateOwner(const string& username, const string& password) {
    if (ownerCredentials.find(username) != ownerCredentials.end()) {
        return ownerCredentials[username] == password;
    }
    return false;
}

// Register customer
bool Authentication::registerCustomer(const string& username, const string& password) {
    if (customerCredentials.find(username) == customerCredentials.end()) {
        customerCredentials[username] = password;
        return true;  // Registration successful
    }
    return false;  // Username already exists
}

// Register owner
bool Authentication::registerOwner(const string& username, const string& password) {
    if (ownerCredentials.find(username) == ownerCredentials.end()) {
        ownerCredentials[username] = password;
        return true;  // Registration successful
    }
    return false;  // Username already exists
}
