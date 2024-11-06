// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

class Customer : public User {
public:
    Customer(const string &name, int id) : User(name, id) {}
    string getRole() const override { return "Customer"; }
};

#endif
