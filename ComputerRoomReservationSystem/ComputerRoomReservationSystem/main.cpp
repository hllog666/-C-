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
		cout << "================机房预约管理系统====================" << endl;
		cout << "请输入你的身份" << endl;
		cout << "\t\t-----------------------\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      1.学生代表      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      2.老  师        |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      3.管理员        |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      0.退出          |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t-----------------------\n";
		cout << "请输入你的选择" << endl;

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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误" << endl;
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
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string password;

	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
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
				cout << "学生登录成功" << endl;
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
				cout << "老师登录成功" << endl;
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
				cout << "管理员登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "登陆失败" << endl;
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
			//添加账号
			man->addPerson();
		}
		else if (select == 2)
		{
			//查看账号
			man->showPerson();
		}
		else if (select == 3)
		{
			//查看机房
			man->showComputer();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
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
			cout << "注销成功" << endl;
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
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}