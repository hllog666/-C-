#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string password)
{
	this->name = name;
	this->password = password;

	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom cm;
	while (ifs >> cm.id && ifs >> cm.maxNum)
	{
		computerRoom.push_back(cm);
	}
	cout << "当前机房数量为：" << computerRoom.size() << endl;
	ifs.close();
}

void Manager::operatorMenu()
{
	cout << "欢迎管理员：" << this->name << "登录" << endl;
	cout << "\t\t------------------------------\n" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         1.添加账号           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         2.查看账号           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         3.查看机房           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         4.清空预约           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         0.注销登录           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t————————————————" << endl;
	cout << "请选择你的操作：" << endl;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型：" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工编号重复，请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string password;

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool flag = checkRepeat(id, select);
		if (flag)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> password;
	ofs << id << " " << name << " " << password << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();

	this->initVector();
}

void printStudent(Student& s)
{
	cout << "学号：" << s.id << "姓名：" << s.name << "密码：" << s.password << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.id << "姓名：" << t.name << "密码：" << t.password << endl;
}

void Manager::showPerson()
{
	cout << "请选择查看的内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(student.begin(), student.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下：" << endl;
		for_each(teacher.begin(), teacher.end(), printTeacher);
	}

	system("pause");
	system("cls");
}



void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = computerRoom.begin(); it != computerRoom.end(); it++)
	{
		cout << "机房编号：" << it->id << "机房最大容量：" << it->maxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	student.clear();
	teacher.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.password)
	{
		student.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.id && ifs >> t.name && ifs >> t.password)
	{
		teacher.push_back(t);
	}
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = student.begin(); it != student.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = teacher.begin(); it != teacher.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}
	}

	return false;
}