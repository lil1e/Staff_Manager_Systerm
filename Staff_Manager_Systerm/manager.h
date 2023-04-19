#pragma once

#include <iostream>
#include<sstream>
using namespace std;
#include "workerbase.h"

//经理类
class Manager :public WorkerBase
{
public:
	Manager(int id, string name, int did);
	Manager(int id, string name, int did, int salary);
	Manager(int id, string name, int did, int salary, int performance, int a[], int n);

	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
