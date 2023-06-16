#pragma once
#ifndef BSMS_USER_H
#define BSMS_USER_H
#include <iostream>
using namespace std;

class User {
public:
    User();
    User(const string& name, const string& password);
    const string& getName() const;
    void setName(const string& name);
    const string& getPassword() const;
    void setPassword(const string& password);
    const string& getPermission() const;
    void setPermission(const string& permission);
    string name;     // 用户名（即销售员名）
    string password; // 密码
    string permission;
};

#endif // BSMS_USER_H