#include "WorkerBase.h"
#include <iostream>
using namespace std;
int WorkerBase::get_m_Id()
{
	return m_Id;
};
string WorkerBase::get_m_Name()
{
	return m_Name;
};
int WorkerBase::get_m_DeptId()
{
	return m_DeptId;
};
int WorkerBase::get_m_day()
{
	return m_day;
}
int WorkerBase::get_m_Check_Attendance(int day)
{
	return m_Check_Attendance[day];
};
int WorkerBase::get_m_Performance()
{
	return m_Performance;
};
int WorkerBase::get_m_Salary()
{
	return m_Salary;
};
