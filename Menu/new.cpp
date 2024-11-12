// Customer.h


#include<stdio.h>
using namespace std:

class Customer : public User {
public:
    Customer(const string &name, int id) : User(name, id) {}
    string getRole() const override { return "Customer"; }
};

#endif
