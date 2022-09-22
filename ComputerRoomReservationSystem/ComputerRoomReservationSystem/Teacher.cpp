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
	cout << "欢迎老师：" << this->name << "登录" << endl;
	cout << "\t\t------------------------------\n" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         1.查看预约           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         2.审核预约           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|         0.注销登录           |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t————————————————" << endl;
	cout << "请选择你的操作：" << endl;
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.orderData[i]["date"];
		cout << "时段：" << ((of.orderData[i]["interval"] == "1") ? "上午" : "下午");
		cout << "学号：" << of.orderData[i]["stuId"];
		cout << "姓名：" << of.orderData[i]["stuName"];
		cout << "机房：" << of.orderData[i]["roomId"];
		string status = "状态：";
		if (of.orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "取消预约";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;

	vector<int> v;
	int index = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：周" << of.orderData[i]["date"];
			cout << "时段：" << ((of.orderData[i]["interval"] == "1") ? "上午" : "下午");
			cout << "机房：" << of.orderData[i]["roomId"];
			string status = "状态：";
			if (of.orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
	}

	cout << "请输入审核的预约记录，0代表返回" << endl;
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
				cout << "请输入审核结果：" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
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
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}