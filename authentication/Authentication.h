// Authentication.h
#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>

class Authentication {
public:
    void signIn(const std::string& username, const std::string& password);
    void registerUser(const std::string& username, const std::string& password);
};

#endif
