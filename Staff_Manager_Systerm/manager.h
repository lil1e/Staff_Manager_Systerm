#pragma once

#include <iostream>
#include<sstream>
using namespace std;
#include "workerbase.h"

//������
class Manager :public WorkerBase
{
public:
	Manager(int id, string name, int did);
	Manager(int id, string name, int did, int salary);
	Manager(int id, string name, int did, int salary, int performance, int a[], int n);

	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
