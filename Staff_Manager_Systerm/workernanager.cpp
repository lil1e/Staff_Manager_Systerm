#include "workermanager.h"

WokerManager::WokerManager() {
	//1.�ļ�������
	ifstream ifs, ifs1;
	ifs.open("empFile.txt", ios::in);//���ļ�
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		//��ʼ������
		//��ʼ����¼��
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FilesIsEmpty = true;
		ifs.close();
		return;

	}
	// 2.�ļ����ڣ���������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ������
		//��ʼ����¼��
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FilesIsEmpty = true;
		ifs.close();
		return;
	}
	ifs1.open("empFile.txt", ios::in);//���ļ�
	WorkerBase* p = NULL;
	int i = 0;
	int Id;//ְ�����
	string Name;//ְ������
	int DeptId;//ְ�����ڲ������Ʊ��
	int salary; //ְ��н��
	int performance;     //���¼�Ч
	int days_absent;       //����ȱϯ����
	int date_absent[31];   //����ȱϯ����
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
	cout << "***********  ��ӭʹ��ְ������ϵͳ  ***********" << endl;
	cout << "**************  0.�˳��������  **************" << endl;
	cout << "**************  1.����ְ����Ϣ  **************" << endl;
	cout << "**************  2.��ʾְ����Ϣ  **************" << endl;
	cout << "**************  3.ɾ����ְԱ��  **************" << endl;
	cout << "**************  4.�޸�ְ����Ϣ  **************" << endl;
	cout << "**************  5.����ְ����Ϣ  **************" << endl;
	cout << "**************  6.���ձ������  **************" << endl;
	cout << "**************  7.��������ĵ�  **************" << endl;
	cout << "**********************************************" << endl;
}

void WokerManager::exitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//���ְ��----�����޸ģ�---�����޸ģ�---�������ƣ�
void WokerManager::Add_Emp() {
	cout << "���������ְ������:" << endl;
	int addNum = 0;//�����û���������
	cin >> addNum;

	if (addNum > 0) {
		//���
		int newSize = this->m_EmpNum + addNum; //�¿ռ��С = ԭ����¼���� + ����������

		//�����¿ռ�
		WorkerBase** newSpace = new WorkerBase * [newSize];
		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			int salary; //ְ��н��
			int m_performance;     //���¼�Ч
			int days_absent;       //����ȱϯ����
			int date_absent[31];   //����ȱϯ����
			int flag;//�����жϱ���Ƿ��ظ�
			while (1)
			{
				flag = 1;
				cout << "�������" << i + 1 << "������ӵ�ְ����ţ�" << endl;
				cin >> id;
				for (int j = 0; j < this->m_EmpNum; j++)
					if (id == this->m_EmpArray[j]->get_m_Id())
					{
						cout << "ϵͳ���иñ�ţ�" << endl;
						flag = 0;
						break;
					}
				if (flag) break;
			}
			cout << "�������" << i + 1 << "������ӵ�ְ��������" << endl;
			cin >> name;

			cout << "�������" << i + 1 << "������ӵ�ְ��н�ʣ�" << endl;
			cin >> salary;

			cout << "�������" << i + 1 << "������ӵ�ְ�����¼�Ч��" << endl;
			cin >> m_performance;

			cout << "��ѡ��ְ����λ��" << endl;
			cout << "1����ͨԱ����" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ壺" << endl;
			cin >> dSelect;

			cout << "�������" << i + 1 << "������ӵ�ְ������ȱ��������" << endl;
			cin >> days_absent;
			if (!days_absent)
				date_absent[0] = 0;
			else
			{
				cout << "�����������" << i + 1 << "����ְ����ȱ�����ڣ��籾��2�ź�5��ȱ�ڣ���������2��5��2��5�м��ûس��ָ�����" << endl;
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

			//��������ְ����Ϣ���浽������
			newSpace[this->m_EmpNum + i] = workerbase;

		}

		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//�ɹ���Ӻ󱣴浽�ļ���
		this->save();

		//��ʾ�ɹ�
		cout << "�ɹ����" << addNum << "����Ա����" << endl;
		this->m_FilesIsEmpty = 0;
		cout << "�ļ���Ϣ������ϣ�";

	}
	else {
		cout << "������������" << endl;
	}

	//����������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�����ʵ��
void WokerManager::save() {
	ofstream ofs;
	ofs.open("empFile.txt", ios::out);//д�ķ�ʽ���ļ�

	//forѭ���а����Ǽ�¼�����ݽ���д��
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
	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ��е�����
int WokerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open("empFile.txt", ios::in);//���ļ�

	string name;
	string line;
	int num = 0;
	while (getline(ifs, line)) {
		//ͳ������
		num++;
	}
	return num;

}

//��ʼ��ְ��
void WokerManager::init_Emp() {
	ifstream ifs;
	ifs.open("empFile.txt", ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		WorkerBase* workerbase = NULL;
		if (dId == 1) {//��ְͨ��
			workerbase = new Employee(id, name, dId);
		}
		else if (dId == 2) {//����
			workerbase = new Manager(id, name, dId);
		}
		else {//�ϰ�
			workerbase = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = workerbase;
		index++;

	}
	cout << "�����ļ��г�ʼ��[" << index << "]������" << endl;

	//�ر��ļ�
	ifs.close();


}

//��ʾְ����Ϣ----�����޸ģ�----�����޸ģ�----�������ƣ�
void WokerManager::Show_Emp() {
	//�ж��ļ��Ƿ�Ϊ�ջ��߲�����
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			//���ö�̬������ʾ�Ľӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	//�������������
	system("pause");
	system("cls");
}

// �ж�ְ���Ƿ����,�����򷵻�ְ���������е�λ�ã������ڷ���-1
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
//ɾ��ְ��
void WokerManager::Del_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		//����ְ����Ž���ɾ��
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExit(id);
		if (index != -1) {//˵��ְ�����ڣ���Ҫɾ��indexλ���ϵ�ְ��
			//����Ǩ��
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//���������м�¼����Ա����
			this->m_EmpNum--;
			//ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
			if (!this->m_EmpNum)
				this->m_FilesIsEmpty = 1;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//�޸�ְ��----�����޸ģ�----(���޸�)---�������ƣ�
void WokerManager::Mod_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������Ҫ���޸ġ���ְ�����" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1) {
			//���ҵ�ְ��
			int newId = 0;
			int newSalary;
			string newName = "";
			int dSelect = 0;
			int newperform;
			int day;//�޸�ȱ����������һ���µ������
			int day_abset[31];//�޸�ȱ�ڵľ������ڣ���һ���µ������
			cout << "���ҵ�ְ�����Ϊ[" << id << "]��ְ������������ְ����:" << endl;
			cin >> newId;
			cout << "������������:" << endl;
			cin >> newName;
			cout << "��������н��:" << endl;
			cin >> newSalary;
			cout << "�������¸�λ:" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			cout << "�������ְ�����¼�Ч��" << endl;
			cin >> newperform;
			cout << "�������ְ����ȱ��������" << endl;
			cin >> day;
			if (!day)
				day_abset[0] = 0;
			else
			{
				cout << "�����������ְ����ȱ�����ڣ��籾��2�ź�5��ȱ�ڣ���������2��5��2��5�м��ûس��ָ�������" << endl;
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
			//���ݸ��µ�������
			this->m_EmpArray[ret] = wokerbase;
			cout << "ְ����Ϣ�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//����ְ��
void WokerManager::Find_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "���������ְ���ķ�ʽ:" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//���ձ�Ų���
			int id;
			cout << "��������ҵ�ְ���ı��" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1) {
				//�ҵ���ְ��
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2) {
			//������������
			string name;
			cout << "���������ְ������:" << endl;
			cin >> name;
			//�����Ƿ�鵽�ı�־
			bool select_flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->get_m_Name() == name) {
					cout << "���ҳɹ���ְ������Ϊ["
						<< this->m_EmpArray[i]->get_m_Name()
						<< "]��ְ����Ϣ���£�" << endl;

					select_flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (select_flag == false) {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else {
			cout << "����ѡ������" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//ְ������
void WokerManager::Sort_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��ѡ������ʽ:" << endl;
		cout << "1������ְ���Ž�����������" << endl;
		cout << "2������ְ���Ž��н�������" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) {
			int minOrMax = i;//������Сֵ�������ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {//����
					if (this->m_EmpArray[minOrMax]->get_m_Id() > this->m_EmpArray[j]->get_m_Id()) {
						minOrMax = j;
					}

				}
				else {//����
					if (this->m_EmpArray[minOrMax]->get_m_Id() < this->m_EmpArray[j]->get_m_Id()) {
						minOrMax = j;
					}
				}
			}

			//�ж�һ��ʼ�϶�����Сֵ�������ֵ �ǲ��Ǽ������Сֵ�������ֵ�����������ͽ�������
			if (i != minOrMax) {
				WorkerBase* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		}
	}
	cout << "����ɹ����������Ϊ:" << endl;
	this->save();//�����Ľ�����浽�ļ���
	this->Show_Emp();
}

// ����ļ�
void WokerManager::Clean_File() {
	cout << "ȷ������ļ���" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int selcet = 0;
	cin >> selcet;
	if (selcet == 1) {
		//����ļ�
		ofstream ofs("empFile.txt", ios::trunc);//ɾ���ļ������´���
		if (this->m_EmpArray != NULL) {
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;

			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FilesIsEmpty = true;
		}

		cout << "��ճɹ���" << endl;
	}

	//�����������
	system("pause");
	system("cls");

}


