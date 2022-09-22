#include <iostream>
using namespace std;
#include <string>

#define MAX 1000

struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};

struct AddressBook
{
	struct Person personArray[MAX];
	int size;
};

void showMenu();
void addPerson(AddressBook* abs);
void showPerson(AddressBook* abs);
int isExist(AddressBook* abs, string name);
void deletePerson(AddressBook* abs);
void findPerson(AddressBook* abs);
void modifyPerson(AddressBook* abs);
void cleanPerson(AddressBook* abs);

int main()
{
	AddressBook abs;
	abs.size = 0;

	int select = 0;	

	while (1)
	{
		showMenu();
		cin >> select;

		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}	

	return 0;
}

void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;
}

void addPerson(AddressBook* abs)
{
	if (abs->size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}

	string name;
	cout << "请输入姓名：" << endl;
	cin >> name;
	abs->personArray[abs->size].name = name;

	cout << "请输入性别：" << endl;
	cout << "1 -- 男" << endl;
	cout << "2 -- 女" << endl;
	int sex = 0;
	while (1)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->size].sex = sex;
			break;
		}
		cout << "请重新输入" << endl;
	}
	
	cout << "请输入年龄：" << endl;
	int age = 0;
	while (1)
	{
		cin >> age;
		if (age > 0 && age <= 150)
		{
			abs->personArray[abs->size].age = age;
			break;
		}
		cout << "请重新输入" << endl;
	}

	cout << "请输入联系电话：" << endl;
	string phone;
	cin >> phone;
	abs->personArray[abs->size].phone = phone;

	cout << "请输入家庭住址：" << endl;
	string addr;
	cin >> addr;
	abs->personArray[abs->size].addr = addr;

	abs->size++;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}

void showPerson(AddressBook* abs)
{
	if (abs->size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; ++i)
		{
			cout << "姓名：" << abs->personArray[i].name << "\t";
			cout << "性别：" << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "电话：" << abs->personArray[i].phone << "\t";
			cout << "住址：" << abs->personArray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(AddressBook* abs, string name)
{
	for (int i = 0; i < abs->size; ++i)
	{
		if (abs->personArray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(AddressBook* abs)
{
	cout << "请输入要删除联系人姓名：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->size; ++i)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBook* abs)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].name << "\t";
		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].age << "\t";
		cout << "电话：" << abs->personArray[ret].phone << "\t";
		cout << "住址：" << abs->personArray[ret].addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].sex = sex;
				break;
			}
			cout << "请重新输入" << endl;
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		while (1)
		{
			cin >> age;
			if (age > 0 || age <= 150)
			{
				abs->personArray[ret].age = age;
				break;
			}
			cout << "请重新输入" << endl;
		}

		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].phone = phone;

		cout << "请输入家庭住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].addr = addr;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(AddressBook* abs)
{
	cout << "确定要清空通讯录吗？" << endl;
	cout << "1 -- 确定要清空" << endl;
	cout << "2 -- 只是误触" << endl;

	while (1)
	{
		int ret = 0;
		cin >> ret;
		if (ret == 1)
		{
			abs->size = 0;
			cout << "通讯录已清空" << endl;
			break;
		}
		else if (ret == 2)
		{
			break;
		}
		else
		{
			cout << "请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}