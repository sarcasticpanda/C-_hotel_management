#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <string>

class Authentication {
public:
    bool validateCustomer(const std::string& username, const std::string& password);
    bool validateOwner(const std::string& username, const std::string& password);
    bool registerCustomer(const std::string& username, const std::string& password);
    bool registerOwner(const std::string& username, const std::string& password);
};

#endif
