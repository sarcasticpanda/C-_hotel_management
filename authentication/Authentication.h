#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <unordered_map>

class Authentication {
private:
    std::unordered_map<std::string, std::string> customerData;
    std::unordered_map<std::string, std::string> ownerData;

public:
    bool registerCustomer(const std::string& username, const std::string& password);
    bool validateCustomer(const std::string& username, const std::string& password);
    bool registerOwner(const std::string& username, const std::string& password);
    bool validateOwner(const std::string& username, const std::string& password);
};

#endif // AUTHENTICATION_H
