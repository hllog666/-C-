#include "Teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;
}

void Teacher::operatorMenu()
{
	cout << "��ӭ��ʦ��" << this->name << "��¼" << endl;
	cout << "\t\t------------------------------\n" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         1.�鿴ԤԼ           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         2.���ԤԼ           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         0.ע����¼           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t��������������������������������" << endl;
	cout << "��ѡ����Ĳ�����" << endl;
}

void Teacher::showAllOrder()
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

void Teacher::validOrder()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int> v;
	int index = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
			cout << "ʱ�Σ�" << ((of.orderData[i]["interval"] == "1") ? "����" : "����");
			cout << "������" << of.orderData[i]["roomId"];
			string status = "״̬��";
			if (of.orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
	}

	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "��������˽����" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.orderData[select - 1]["status"] = "2";
				}
				else
				{
					of.orderData[select - 1]["status"] = "-1";
				}
				of.updateOrder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}