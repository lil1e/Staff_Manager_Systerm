#include "login.h"

//登录类构造
Login::Login(const string& file_name) : users_file(file_name) {

}

//注册bool
bool Login::register_user(const string& name, const string& pwd) {
    // 在这里将新用户的用户名和密码保存到文件中
    // 如果注册成功，则返回 true，否则返回 false
    ofstream file(users_file, ios::app);
    if (file) {
        file << name << " " << pwd << endl;
        return true;
    }
    else {
        return false;
    }
}

//注册
void Login::register_()
{
    string name, pwd;
    cout << "Please enter username: ";
    cin >> name;
    cout << "Please enter password: ";
    cin >> pwd;

    if (this->register_user(name, pwd)) {
        cout << "Register success!" << endl;
    }
    else {
        cout << "Register failed!" << endl;
    }
}

//登录bool
bool Login::Islogin(const string& name, const string& pwd) {
    // 在这里读取文件，判断输入的账户与文件中的账户是否相同
    // 如果相同，则登录成功，返回 true，否则登录失败，返回 false
    ifstream file(users_file);
    string file_name, file_pwd;
    while (file >> file_name >> file_pwd) {
        if (name == file_name && pwd == file_pwd) {
            username = name;
            password = pwd;
            return true;
        }
    }
    return false;
}

//登录
void Login::login()
{
    string name, pwd;
    cout << "Please enter username: ";
    cin >> name;
    cout << "Please enter password: ";
    cin >> pwd;

    if (this->Islogin(name, pwd)) {
        cout << "Welcome, " << this->get_username() << "!" << endl;
    }
    else {
        cout << "Login failed!" << endl;
    }
}
//获得用户账户名
string Login::get_username() const {
    return username;
}

