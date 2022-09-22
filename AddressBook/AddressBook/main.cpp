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
			cout << "��ӭ�´�ʹ��" << endl;
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
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
}

void addPerson(AddressBook* abs)
{
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}

	string name;
	cout << "������������" << endl;
	cin >> name;
	abs->personArray[abs->size].name = name;

	cout << "�������Ա�" << endl;
	cout << "1 -- ��" << endl;
	cout << "2 -- Ů" << endl;
	int sex = 0;
	while (1)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->size].sex = sex;
			break;
		}
		cout << "����������" << endl;
	}
	
	cout << "���������䣺" << endl;
	int age = 0;
	while (1)
	{
		cin >> age;
		if (age > 0 && age <= 150)
		{
			abs->personArray[abs->size].age = age;
			break;
		}
		cout << "����������" << endl;
	}

	cout << "��������ϵ�绰��" << endl;
	string phone;
	cin >> phone;
	abs->personArray[abs->size].phone = phone;

	cout << "�������ͥסַ��" << endl;
	string addr;
	cin >> addr;
	abs->personArray[abs->size].addr = addr;

	abs->size++;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
}

void showPerson(AddressBook* abs)
{
	if (abs->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; ++i)
		{
			cout << "������" << abs->personArray[i].name << "\t";
			cout << "�Ա�" << (abs->personArray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].age << "\t";
			cout << "�绰��" << abs->personArray[i].phone << "\t";
			cout << "סַ��" << abs->personArray[i].addr << endl;
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
	cout << "������Ҫɾ����ϵ��������" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBook* abs)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].age << "\t";
		cout << "�绰��" << abs->personArray[ret].phone << "\t";
		cout << "סַ��" << abs->personArray[ret].addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].sex = sex;
				break;
			}
			cout << "����������" << endl;
		}

		cout << "���������䣺" << endl;
		int age = 0;
		while (1)
		{
			cin >> age;
			if (age > 0 || age <= 150)
			{
				abs->personArray[ret].age = age;
				break;
			}
			cout << "����������" << endl;
		}

		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].phone = phone;

		cout << "�������ͥסַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].addr = addr;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(AddressBook* abs)
{
	cout << "ȷ��Ҫ���ͨѶ¼��" << endl;
	cout << "1 -- ȷ��Ҫ���" << endl;
	cout << "2 -- ֻ����" << endl;

	while (1)
	{
		int ret = 0;
		cin >> ret;
		if (ret == 1)
		{
			abs->size = 0;
			cout << "ͨѶ¼�����" << endl;
			break;
		}
		else if (ret == 2)
		{
			break;
		}
		else
		{
			cout << "����������" << endl;
		}
	}
	system("pause");
	system("cls");
}