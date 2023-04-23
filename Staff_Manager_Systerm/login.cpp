#include "login.h"

//��¼�๹��
Login::Login(const string& file_name) : users_file(file_name) {

}

//ע��bool
bool Login::register_user(const string& name, const string& pwd) {
    // �����ｫ���û����û��������뱣�浽�ļ���
    // ���ע��ɹ����򷵻� true�����򷵻� false
    ofstream file(users_file, ios::app);
    if (file) {
        file << name << " " << pwd << endl;
        return true;
    }
    else {
        return false;
    }
}

//ע��
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

//��¼bool
bool Login::Islogin(const string& name, const string& pwd) {
    // �������ȡ�ļ����ж�������˻����ļ��е��˻��Ƿ���ͬ
    // �����ͬ�����¼�ɹ������� true�������¼ʧ�ܣ����� false
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

//��¼
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
//����û��˻���
string Login::get_username() const {
    return username;
}

