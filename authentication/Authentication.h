#pragma once
#include <string>
using namespace std;

class Authentication {
public:
    bool registerOrSignIn(const string& role);
};
