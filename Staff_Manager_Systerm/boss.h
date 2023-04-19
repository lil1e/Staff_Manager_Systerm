#pragma once
#include <iostream>
using namespace std;
#include "workerbase.h"

//老板类
class Boss :public WorkerBase
{
public:
	Boss(int id, string name, int did);
	Boss(int id, string name, int did, int salary);
	Boss(int id, string name, int did, int salary, int performance, int a[], int n);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};


