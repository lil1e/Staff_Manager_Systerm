#pragma once //防止头文件重复包含
#include<iostream> //包含输入输出流的头文件
using namespace std; //使用标准的命名空间

#include "workermanager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "workerbase.h"

#include<fstream>
//设定文件路径
#include <fstream>//文件操作



class WokerManager
{
public:
	//原来记录人数
	int m_EmpNum;

	//职工数组
	WorkerBase** m_EmpArray; //原来定义成常量指针了WorkerBase* m_EmpArray[];不可修改

	//判断文件是否为空的标志
	bool m_FilesIsEmpty;

	//构造函数
	WokerManager();

	//展示菜单
	void Show_Menu();

	//退出功能
	void exitSystem();

	//添加职工----（待修改）----（已修改）
	void Add_Emp();

	//保存文件
	void save();

	//统计文件中的人数
	int get_EmpNum();

	//初始化职工----（待修改）----（）
	void init_Emp();

	//显示职工信息----（待修改）----（已修改）
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在,存在则返回职工在数组中的位置，不存在返回-1
	int IsExit(int id);

	//修改职工----（待修改）
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按照编号排序
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WokerManager();
};