#include "Authentication.h"
#include <iostream>
using namespace std;

bool Authentication::registerOrSignIn(const string& role) {
    string userID, password;
    
    cout << "Enter User ID: ";
    cin >> userID;
    cout << "Enter Password: ";
    cin >> password;
    
    // Check for test credentials here
    if (userID == "sampleID" && password == "samplePass") {
        cout << "Sign-in successful as " << role << "!\n";
        return true;
    } else {
        cout << "Invalid credentials. Please try again.\n";
        return false;
    }
}
