// User.h
#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
protected:
    string name;
    int id;

public:
    User(const string &name, int id) : name(name), id(id) {}
    virtual ~User() = default;

    string getName() const { return name; }
    int getId() const { return id; }

    virtual string getRole() const = 0; // Pure virtual function for role
};

#endif
