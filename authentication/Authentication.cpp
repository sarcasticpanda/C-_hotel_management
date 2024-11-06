// Authentication.cpp
#include "Authentication.h"
#include <iostream>
#include <unordered_map>
using namespace std;

void Authentication::signIn(const string& username, const string& password) {
    // Implement sign-in logic here (example: simple validation)
    cout << "Signing in with Username: " << username << " and Password: " << password << endl;
    // Add your sign-in logic (e.g., validate against a stored database)
}

void Authentication::registerUser(const string& username, const string& password) {
    // Implement register logic here
    cout << "Registering with Username: " << username << " and Password: " << password << endl;
    // Add your registration logic (e.g., save credentials to a file)
}
