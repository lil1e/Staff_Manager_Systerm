#pragma once
#include<iostream>
using namespace std;
#include "workerbase.h"

//Ա����
class Employee :public WorkerBase
{
public:

	//���캯��
	Employee(int id, string name, int did);
	Employee(int id, string name, int did, int salary);
	Employee(int id, string name, int did, int salary, int performance, int a[], int n);

	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
