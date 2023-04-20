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
	int i;                          //j是状态变量，用于判断是否全勤
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t薪资：" << this->get_m_Salary()
		<< "\t岗位职责：完成经历交付的各项任务" << endl;
	cout << "本月出勤情况：" << endl;
	if (!this->m_Check_Attendance[0])
		cout << "本月" << m_Name << "全勤" << endl;
	else
		for (i = 0; i < 31 && m_Check_Attendance[i]; i++)
			cout << "在" << m_Check_Attendance[i] << "日，缺勤" << endl;


	cout << "本月绩效：" << this->m_Performance << endl;
}


string Manager::getDeptName() {
	return string("经理");
}
