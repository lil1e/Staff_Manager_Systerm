#include<iostream>
#include<stdlib.h>
using namespace std;
#include "workermanager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "workerbase.h"
#include "login.h"

int main() {
	//ʵ���������߶���
	WokerManager wm;
	//ʵ������¼����
	Login login("uses.txt");
	cout << "��ѡ�����" << endl;
	cout << "1.��¼" << endl;
	cout << "2.ע��" << endl;

	int chioce;
	cin >> chioce;
	if (chioce == 2)
	{
		login.register_();
	}
	else if (chioce == 1)
	{
		string name, pwd;
		cout << "Please enter username: ";
		cin >> name;
		cout << "Please enter password: ";
		cin >> pwd;
		if (login.Islogin(name, pwd) == 1)
		{
			cout << "��½�ɹ�!��ӭ��," << login.get_username() << endl;
			int choice = 0;
			while (true) {
				//չʾ�˵�
				//����չʾ�˵���Ա����
				wm.Show_Menu();
				cout << "��ѡ�����Ĳ�����" << endl;
				cin >> choice;

				switch (choice)
				{
				case 0://�˳�ϵͳ
					wm.exitSystem();
					break;
				case 1://���ְ��
					wm.Add_Emp();
					break;
				case 2://��ʾְ��
					wm.Show_Emp();
					break;
				case 3://ɾ��ְ��
					wm.Del_Emp();
					break;
				case 4://�޸�ְ��
					wm.Mod_Emp();
					break;
				case 5://����ְ��
					wm.Find_Emp();
					break;
				case 6://����ְ��
					wm.Sort_Emp();
					break;
				case 7://����ļ�
					wm.Clean_File();
					break;
				default:
					system("cls");
					break;
				}
			}
		}
		else
		{
			cout << "��¼ʧ��!" << endl;
		}
	}
	else
	{
		cout << "�����ʽ����" << endl;
	}




	//int choice = 0;
	//while (true) {
	//	//չʾ�˵�
	//	//����չʾ�˵���Ա����
	//	wm.Show_Menu();
	//	cout << "��ѡ�����Ĳ�����" << endl;
	//	cin >> choice;

	//	switch (choice)
	//	{
	//	case 0://�˳�ϵͳ
	//		wm.exitSystem();
	//		break;
	//	case 1://���ְ��
	//		wm.Add_Emp();
	//		break;
	//	case 2://��ʾְ��
	//		wm.Show_Emp();
	//		break;
	//	case 3://ɾ��ְ��
	//		wm.Del_Emp();
	//		break;
	//	case 4://�޸�ְ��
	//		wm.Mod_Emp();
	//		break;
	//	case 5://����ְ��
	//		wm.Find_Emp();
	//		break;
	//	case 6://����ְ��
	//		wm.Sort_Emp();
	//		break;
	//	case 7://����ļ�
	//		wm.Clean_File();
	//		break;
	//	default:
	//		system("cls");
	//		break;
	//	}
	//}
	system("pause");

	return 0;
}
//�������ͨ��
//���ְ������ͨ��




//int main() {
//	//���Դ���
//	WorkerBase* workerbase = NULL;
//	WorkerBase* workerbase1 = NULL;
//	workerbase = new Employee(1, "����", 0001);
//	workerbase->showInfo();
//	workerbase1 = new Boss(2, "BOSS", 0000);
//	workerbase1->showInfo();
//
//	system("pause");
//	return 0;
//}
//��̬����ͨ��