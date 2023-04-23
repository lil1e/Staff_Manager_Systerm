#pragma once //��ֹͷ�ļ��ظ�����
#include<iostream> //���������������ͷ�ļ�
using namespace std; //ʹ�ñ�׼�������ռ�

#include "workermanager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "workerbase.h"

#include<fstream>
//�趨�ļ�·��
#include <fstream>//�ļ�����



class WokerManager
{
public:
	//ԭ����¼����
	int m_EmpNum;

	//ְ������
	WorkerBase** m_EmpArray; //ԭ������ɳ���ָ����WorkerBase* m_EmpArray[];�����޸�

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FilesIsEmpty;

	//���캯��
	WokerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�����
	void exitSystem();

	//���ְ��----�����޸ģ�----�����޸ģ�
	void Add_Emp();

	//�����ļ�
	void save();

	//ͳ���ļ��е�����
	int get_EmpNum();

	//��ʼ��ְ��----�����޸ģ�----����
	void init_Emp();

	//��ʾְ����Ϣ----�����޸ģ�----�����޸ģ�
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ����,�����򷵻�ְ���������е�λ�ã������ڷ���-1
	int IsExit(int id);

	//�޸�ְ��----�����޸ģ�
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WokerManager();
};