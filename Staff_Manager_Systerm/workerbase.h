#pragma once
#include<iostream>
#include<string>
using namespace std;
//����ְ����
class WorkerBase
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;
	int get_m_Id();
	string get_m_Name();
	int get_m_DeptId();
	int get_m_Check_Attendance(int day);
	int get_m_Performance();
	int get_m_Salary();
	int get_m_day();
protected:
	//Ա��������Ϣ
	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ڲ������Ʊ��
	//Ա��ȱ������
	int m_day;
	//Ա��������Ϣ
	int m_Check_Attendance[31];
	//Ա����Ч��Ϣ
	int m_Performance;
	//Ա��н����Ϣ
	int m_Salary;
};
