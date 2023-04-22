#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Login {
public:

    Login(const string& file_name);

    //注册
    void register_();

    //登录
    void login();

    //注册bool
    bool register_user(const string& name, const string& pwd);

    //登录bool
    bool Islogin(const string& name, const string& pwd);

    //获得用户账户名
    string get_username() const;

private:
    //账户名（账号）
    string username;

    //密码
    string password;

    //文件名
    string users_file;


};
