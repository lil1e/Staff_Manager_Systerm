#include "workermanager.h"

WokerManager::WokerManager() {
	//1.文件不存在
	ifstream ifs, ifs1;
	ifs.open("empFile.txt", ios::in);//读文件
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		//初始化属性
		//初始化记录数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FilesIsEmpty = true;
		ifs.close();
		return;

	}
	// 2.文件存在，但是数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//文件为空
		cout << "文件为空！" << endl;
		//初始化属性
		//初始化记录数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FilesIsEmpty = true;
		ifs.close();
		return;
	}
	ifs1.open("empFile.txt", ios::in);//读文件
	WorkerBase* p = NULL;
	int i = 0;
	int Id;//职工编号
	string Name;//职工姓名
	int DeptId;//职工所在部门名称编号
	int salary; //职工薪资
	int performance;     //当月绩效
	int days_absent;       //当月缺席天数
	int date_absent[31];   //当月缺席日期
	string line;
	while (getline(ifs1, line))
		m_EmpNum++;
	ifs1.clear();
	ifs1.seekg(0);
	m_EmpArray = new WorkerBase * [m_EmpNum];
	while (getline(ifs1, line))
	{
		istringstream line1(line);
		line1 >> Id >> Name >> DeptId >> salary >> performance >> days_absent;
		for (int j = 0; j < days_absent; j++)
			line1 >> date_absent[j];
		if (DeptId == 1)
		{
			p = new Employee(Id, Name, DeptId, salary, performance, date_absent, days_absent);
		}
		if (DeptId == 2)
		{
			p = new Manager(Id, Name, DeptId, salary, performance, date_absent, days_absent);
		}if (DeptId == 3)
		{
			p = new Boss(Id, Name, DeptId, salary, performance, date_absent, days_absent);
		}
		m_EmpArray[i] = p;
		i++;
	}
	ifs1.close();
}

WokerManager::~WokerManager() {

}

void WokerManager::Show_Menu() {
	cout << "**********************************************" << endl;
	cout << "***********  欢迎使用职工管理系统  ***********" << endl;
	cout << "**************  0.退出管理程序  **************" << endl;
	cout << "**************  1.增加职工信息  **************" << endl;
	cout << "**************  2.显示职工信息  **************" << endl;
	cout << "**************  3.删除离职员工  **************" << endl;
	cout << "**************  4.修改职工信息  **************" << endl;
	cout << "**************  5.查找职工信息  **************" << endl;
	cout << "**************  6.按照编号排序  **************" << endl;
	cout << "**************  7.清空所有文档  **************" << endl;
	cout << "**********************************************" << endl;
}

void WokerManager::exitSystem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//添加职工----（待修改）---（已修改）---（已完善）
void WokerManager::Add_Emp() {
	cout << "请输入添加职工数量:" << endl;
	int addNum = 0;//保存用户输入数量
	cin >> addNum;

	if (addNum > 0) {
		//添加
		int newSize = this->m_EmpNum + addNum; //新空间大小 = 原来记录人数 + 新增的人数

		//开辟新空间
		WorkerBase** newSpace = new WorkerBase * [newSize];
		//将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			int salary; //职工薪资
			int m_performance;     //当月绩效
			int days_absent;       //当月缺席天数
			int date_absent[31];   //当月缺席日期
			int flag;//用于判断编号是否重复
			while (1)
			{
				flag = 1;
				cout << "请输入第" << i + 1 << "个新添加的职工编号：" << endl;
				cin >> id;
				for (int j = 0; j < this->m_EmpNum; j++)
					if (id == this->m_EmpArray[j]->get_m_Id())
					{
						cout << "系统已有该编号！" << endl;
						flag = 0;
						break;
					}
				if (flag) break;
			}
			cout << "请输入第" << i + 1 << "个新添加的职工姓名：" << endl;
			cin >> name;

			cout << "请输入第" << i + 1 << "个新添加的职工薪资：" << endl;
			cin >> salary;

			cout << "请输入第" << i + 1 << "个新添加的职工本月绩效：" << endl;
			cin >> m_performance;

			cout << "请选择职工岗位：" << endl;
			cout << "1、普通员工：" << endl;
			cout << "2、经理：" << endl;
			cout << "3、老板：" << endl;
			cin >> dSelect;

			cout << "请输入第" << i + 1 << "个新添加的职工本月缺勤天数：" << endl;
			cin >> days_absent;
			if (!days_absent)
				date_absent[0] = 0;
			else
			{
				cout << "请依次输入第" << i + 1 << "个新职工的缺勤日期（如本月2号和5号缺勤，依次输入2和5，2和5中间用回车分隔）：" << endl;
				for (int j = 0; j < days_absent; j++)
					cin >> date_absent[j];
			}
			WorkerBase* workerbase = NULL;
			switch (dSelect)
			{
			case 1:
				workerbase = new Employee(id, name, 1, salary, m_performance, date_absent, days_absent);
				break;
			case 2:
				workerbase = new Manager(id, name, 2, salary, m_performance, date_absent, days_absent);
				break;
			case 3:
				workerbase = new Boss(id, name, 3, salary, m_performance, date_absent, days_absent);
				break;
			default:
				break;
			}

			//将创建的职工信息保存到数组中
			newSpace[this->m_EmpNum + i] = workerbase;

		}

		//释放原有的空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//成功添加后保存到文件中
		this->save();

		//提示成功
		cout << "成功添加" << addNum << "名新员工！" << endl;
		this->m_FilesIsEmpty = 0;
		cout << "文件信息更新完毕！";

	}
	else {
		cout << "输入数据有误！" << endl;
	}

	//按任意键后清屏，回到上级目录
	system("pause");
	system("cls");
}

//保存文件功能实现
void WokerManager::save() {
	ofstream ofs;
	ofs.open("empFile.txt", ios::out);//写的方式打开文件

	//for循环中把我们记录的数据进行写入
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->get_m_Id() << " "
			<< this->m_EmpArray[i]->get_m_Name() << " "
			<< this->m_EmpArray[i]->get_m_DeptId() << " "
			<< this->m_EmpArray[i]->get_m_Salary() << " "
			<< this->m_EmpArray[i]->get_m_Performance() << " "
			<< this->m_EmpArray[i]->get_m_day() << " ";
		if (!this->m_EmpArray[i]->get_m_day())
			ofs << this->m_EmpArray[i]->get_m_Check_Attendance(0) << endl;
		else
		{
			int n = this->m_EmpArray[i]->get_m_day();
			for (int j = 0; j < n; j++)
			{
				if (j == n - 1)
					ofs << this->m_EmpArray[i]->get_m_Check_Attendance(j) << endl;
				else
					ofs << this->m_EmpArray[i]->get_m_Check_Attendance(j) << " ";

			}
		}
	}
	//关闭文件
	ofs.close();
}

//统计文件中的人数
int WokerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open("empFile.txt", ios::in);//打开文件

	string name;
	string line;
	int num = 0;
	while (getline(ifs, line)) {
		//统计人数
		num++;
	}
	return num;

}

//初始化职工
void WokerManager::init_Emp() {
	ifstream ifs;
	ifs.open("empFile.txt", ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		WorkerBase* workerbase = NULL;
		if (dId == 1) {//普通职工
			workerbase = new Employee(id, name, dId);
		}
		else if (dId == 2) {//经理
			workerbase = new Manager(id, name, dId);
		}
		else {//老板
			workerbase = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = workerbase;
		index++;

	}
	cout << "共从文件中初始化[" << index << "]条数据" << endl;

	//关闭文件
	ifs.close();


}

//显示职工信息----（待修改）----（已修改）----（已完善）
void WokerManager::Show_Emp() {
	//判断文件是否为空或者不存在
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			//利用多态调用显示的接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}

// 判断职工是否存在,存在则返回职工在数组中的位置，不存在返回-1
int WokerManager::IsExit(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->get_m_Id() == id) {
			index = i;
			break;
		}
	}
	return index;
}
//删除职工
void WokerManager::Del_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		//按照职工编号进行删除
		cout << "请输入需要删除的职工编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExit(id);
		if (index != -1) {//说明职工存在，需要删除index位置上的职工
			//数据迁移
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新数据中记录的人员个数
			this->m_EmpNum--;
			//同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
			if (!this->m_EmpNum)
				this->m_FilesIsEmpty = 1;
		}
		else {
			cout << "删除失败，未找到该职工！" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//修改职工----（待修改）----(已修改)---（待完善）
void WokerManager::Mod_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请输入需要【修改】的职工编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1) {
			//查找到职工
			int newId = 0;
			int newSalary;
			string newName = "";
			int dSelect = 0;
			int newperform;
			int day;//修改缺勤天数（新一个月的情况）
			int day_abset[31];//修改缺勤的具体日期（新一个月的情况）
			cout << "查找到职工编号为[" << id << "]的职工，请输入新职工号:" << endl;
			cin >> newId;
			cout << "请输入新姓名:" << endl;
			cin >> newName;
			cout << "请输入新薪资:" << endl;
			cin >> newSalary;
			cout << "请输入新岗位:" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			cout << "请输入该职工的新绩效：" << endl;
			cin >> newperform;
			cout << "请输入该职工的缺勤天数：" << endl;
			cin >> day;
			if (!day)
				day_abset[0] = 0;
			else
			{
				cout << "请依次输入该职工的缺勤日期（如本月2号和5号缺勤，依次输入2和5，2和5中间用回车分隔隔）：" << endl;
				for (int j = 0; j < day; j++)
					cin >> day_abset[j];
			}
			WorkerBase* wokerbase = NULL;
			switch (dSelect)
			{
			case 1:
				wokerbase = new Employee(newId, newName, 1, newSalary, newperform, day_abset, day);
				break;
			case 2:
				wokerbase = new Manager(newId, newName, 2, newSalary, newperform, day_abset, day);
				break;
			case 3:
				wokerbase = new Boss(newId, newName, 3, newSalary, newperform, day_abset, day);
				break;
			}
			//数据更新到数组中
			this->m_EmpArray[ret] = wokerbase;
			cout << "职工信息修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else {
			cout << "修改失败，查无此人！" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//查找职工
void WokerManager::Find_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请输入查找职工的方式:" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//按照编号查找
			int id;
			cout << "请输入查找的职工的编号" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1) {
				//找到该职工
				cout << "查找成功！该职工的信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2) {
			//按照姓名查找
			string name;
			cout << "请输入查找职工姓名:" << endl;
			cin >> name;
			//加入是否查到的标志
			bool select_flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->get_m_Name() == name) {
					cout << "查找成功！职工姓名为["
						<< this->m_EmpArray[i]->get_m_Name()
						<< "]的职工信息如下：" << endl;

					select_flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (select_flag == false) {
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else {
			cout << "输入选项有误！" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//职工排序
void WokerManager::Sort_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请选择排序方式:" << endl;
		cout << "1、按照职工号进行升序排序" << endl;
		cout << "2、按照职工号进行降序排序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) {
			int minOrMax = i;//申明最小值或者最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {//升序
					if (this->m_EmpArray[minOrMax]->get_m_Id() > this->m_EmpArray[j]->get_m_Id()) {
						minOrMax = j;
					}

				}
				else {//降序
					if (this->m_EmpArray[minOrMax]->get_m_Id() < this->m_EmpArray[j]->get_m_Id()) {
						minOrMax = j;
					}
				}
			}

			//判断一开始认定的最小值或者最大值 是不是计算的最小值或者最大值，如果不是则就交换数据
			if (i != minOrMax) {
				WorkerBase* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		}
	}
	cout << "排序成功，排序后结果为:" << endl;
	this->save();//排序后的结果保存到文件中
	this->Show_Emp();
}

// 清空文件
void WokerManager::Clean_File() {
	cout << "确定清空文件？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int selcet = 0;
	cin >> selcet;
	if (selcet == 1) {
		//清空文件
		ofstream ofs("empFile.txt", ios::trunc);//删除文件后重新创建
		if (this->m_EmpArray != NULL) {
			//删除堆区的每个职工对象
			for (int i = 0; i < m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;

			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FilesIsEmpty = true;
		}

		cout << "清空成功！" << endl;
	}

	//按任意键清屏
	system("pause");
	system("cls");

}


