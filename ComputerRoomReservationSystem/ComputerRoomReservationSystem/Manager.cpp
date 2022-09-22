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
	cout << "��ǰ��������Ϊ��" << computerRoom.size() << endl;
	ifs.close();
}

void Manager::operatorMenu()
{
	cout << "��ӭ����Ա��" << this->name << "��¼" << endl;
	cout << "\t\t------------------------------\n" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         1.����˺�           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         2.�鿴�˺�           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         3.�鿴����           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         4.���ԤԼ           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         0.ע����¼           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t��������������������������������" << endl;
	cout << "��ѡ����Ĳ�����" << endl;
}

void Manager::addPerson()
{
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ������ظ�������������";
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

	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> password;
	ofs << id << " " << name << " " << password << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();

	this->initVector();
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.id << "������" << s.name << "���룺" << s.password << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.id << "������" << t.name << "���룺" << t.password << endl;
}

void Manager::showPerson()
{
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(student.begin(), student.end(), printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(teacher.begin(), teacher.end(), printTeacher);
	}

	system("pause");
	system("cls");
}



void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = computerRoom.begin(); it != computerRoom.end(); it++)
	{
		cout << "������ţ�" << it->id << "�������������" << it->maxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
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
		cout << "�ļ���ȡʧ��" << endl;
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
		cout << "�ļ���ȡʧ��" << endl;
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