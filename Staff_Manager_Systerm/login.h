#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Login {
public:

    Login(const string& file_name);

    //ע��
    void register_();

    //��¼
    void login();

    //ע��bool
    bool register_user(const string& name, const string& pwd);

    //��¼bool
    bool Islogin(const string& name, const string& pwd);

    //����û��˻���
    string get_username() const;

private:
    //�˻������˺ţ�
    string username;

    //����
    string password;

    //�ļ���
    string users_file;


};
