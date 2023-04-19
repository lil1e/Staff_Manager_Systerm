#pragma once
#include<iostream>
#include<string>
using namespace std;
//抽象职工类
class WorkerBase
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;
	int get_m_Id();
	string get_m_Name();
	int get_m_DeptId();
	int get_m_Check_Attendance(int day);
	int get_m_Performance();
	int get_m_Salary();
	int get_m_day();
protected:
	//员工基本信息
	int m_Id;//职工编号
	string m_Name;//职工姓名
	int m_DeptId;//职工所在部门名称编号
	//员工缺勤天数
	int m_day;
	//员工考勤信息
	int m_Check_Attendance[31];
	//员工绩效信息
	int m_Performance;
	//员工薪资信息
	int m_Salary;
};
