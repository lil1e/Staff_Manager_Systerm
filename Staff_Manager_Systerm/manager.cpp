#include "manager.h"
Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
Manager::Manager(int id, string name, int did, int salary) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
	this->m_Salary = salary;
	int j;
	this->m_Performance = 0;
	for (j = 0; j < 31; j++)
	{
		this->m_Check_Attendance[j] = 1;
	}
}




Manager::Manager(int id, string name, int did, int salary, int performance, int a[], int n) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
	this->m_Salary = salary;
	this->m_day = n;
	int j;
	this->m_Performance = performance;
	for (j = 0; j < 31; j++)
	{
		this->m_Check_Attendance[j] = 0;
	}
	for (j = 0; j < n; j++)
	{
		this->m_Check_Attendance[j] = a[j];
	}
}


void Manager::showInfo() {
	int i;                          //j��״̬�����������ж��Ƿ�ȫ��
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\tн�ʣ�" << this->get_m_Salary()
		<< "\t��λְ����ɾ��������ĸ�������" << endl;
	cout << "���³��������" << endl;
	if (!this->m_Check_Attendance[0])
		cout << "����" << m_Name << "ȫ��" << endl;
	else
		for (i = 0; i < 31 && m_Check_Attendance[i]; i++)
			cout << "��" << m_Check_Attendance[i] << "�գ�ȱ��" << endl;


	cout << "���¼�Ч��" << this->m_Performance << endl;
}


string Manager::getDeptName() {
	return string("����");
}
