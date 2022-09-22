#include <iostream>
using namespace std;
#include "Identity.h"
#include "Manager.h"
#include "Student.h"
#include "Teacher.h"
#include "GlobalFile.h"
#include <fstream>
#include <string>

void loginIn(string fileName, int type);
void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);

int main()
{
	int select = 0;

	while (true) 
	{
		cout << "================����ԤԼ����ϵͳ====================" << endl;
		cout << "������������" << endl;
		cout << "\t\t-----------------------\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      1.ѧ������      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      2.��  ʦ        |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      3.����Ա        |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      0.�˳�          |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t-----------------------\n";
		cout << "���������ѡ��" << endl;

		cin >> select;
		switch (select)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	return 0;
}

void loginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string password;

	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> password;

	if (type == 1)
	{
		int fId;
		string fName;
		string fPassword;
		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "ѧ����¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fId;
		string fName;
		string fPassword;
		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "��ʦ��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		string fName;
		string fPassword;
		while (ifs >> fName && ifs >> fPassword)
		{
			if (fName == name && fPassword == password)
			{
				cout << "����Ա��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��½ʧ��" << endl;
	system("pause");
	system("cls");

}

void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operatorMenu();

		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//����˺�
			man->addPerson();
		}
		else if (select == 2)
		{
			//�鿴�˺�
			man->showPerson();
		}
		else if (select == 3)
		{
			//�鿴����
			man->showComputer();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operatorMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operatorMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete tea;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}