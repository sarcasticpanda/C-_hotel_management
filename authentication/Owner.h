// Owner.h
#ifndef OWNER_H
#define OWNER_H

#include "User.h"

class Owner : public User {
public:
    Owner(const string &name, int id) : User(name, id) {}
    string getRole() const override { return "Owner"; }
};

#endif
