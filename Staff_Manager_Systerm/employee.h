#pragma once
#include<iostream>
using namespace std;
#include "workerbase.h"

//员工类
class Employee :public WorkerBase
{
public:

	//构造函数
	Employee(int id, string name, int did);
	Employee(int id, string name, int did, int salary);
	Employee(int id, string name, int did, int salary, int performance, int a[], int n);

	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
