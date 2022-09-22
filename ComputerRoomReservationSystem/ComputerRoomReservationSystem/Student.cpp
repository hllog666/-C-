#include "Student.h"

Student::Student()
{
	
}

Student::Student(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom cr;
	while (ifs >> cr.id && ifs >> cr.maxNum)
	{
		computerRoom.push_back(cr);
	}
	ifs.close();
}

void Student::operatorMenu()
{
	cout << "��ӭѧ����" << this->name << "��¼" << endl;
	cout << "\t\t------------------------------\n" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         1.����ԤԼ           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         2.�鿴�ҵ�ԤԼ       |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         3.�鿴����ԤԼ       |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         4.ȡ��ԤԼ           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         0.ע����¼           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t��������������������������������" << endl;
	cout << "��ѡ����Ĳ�����" << endl;
}

void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "������ԤԼ�����ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date = 0;
	int interval = 0;
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "����������ԤԼʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	for (int i = 0; i < computerRoom.size(); i++)
	{
		cout << computerRoom[i].id << "�Ż�������Ϊ��" << computerRoom[i].maxNum << endl;
	}
	
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->id << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();

	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		if (atoi(of.orderData[i]["stuId"].c_str()) == this->id)
		{
			cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
			cout << "ʱ�Σ�" << ((of.orderData[i]["interval"] == "1") ? "����" : "����");
			cout << "ѧ�ţ�" << of.orderData[i]["stuId"];
			cout << "������" << of.orderData[i]["stuName"];
			cout << "������" << of.orderData[i]["roomId"];
			string status = "״̬��";
			if (of.orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ȡ��ԤԼ";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
		cout << "ʱ�Σ�" << ((of.orderData[i]["interval"] == "1") ? "����" : "����");
		cout << "ѧ�ţ�" << of.orderData[i]["stuId"];
		cout << "������" << of.orderData[i]["stuName"];
		cout << "������" << of.orderData[i]["roomId"];
		string status = "״̬��";
		if (of.orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ȡ��ԤԼ";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Student::cancelOrder()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.size; i++)
	{
		if (atoi(of.orderData[i]["stuId"].c_str()) == this->id)
		{
			if (of.orderData[i]["status"] == "1" || of.orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
				cout << "ʱ�Σ�" << ((of.orderData[i]["interval"] == "1") ? "����" : "����");
				cout << "������" << of.orderData[i]["roomId"];
				string status = "״̬��";
				if (of.orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				else if (of.orderData[i]["status"] == "-1")
				{
					status += "ԤԼʧ��";
				}
				else
				{
					status += "ȡ��ԤԼ";
				}
				cout << status << endl;
			}
		}
	}

	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}