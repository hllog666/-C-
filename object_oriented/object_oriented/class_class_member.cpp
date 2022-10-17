#include <iostream>
using namespace std;
#include <string>

class Phone
{
public:
	Phone(string name) :name(name)
	{
		cout << "Phone���캯��" << endl;
	}

	~Phone()
	{
		cout << "Phone��������" << endl;
	}

	string name;
};

class Person
{
public:
	Person(string name, Phone phone) :name(name), phone(phone)
	{
		cout << "Person���캯��" << endl;
	}

	~Person()
	{
		cout << "Person��������" << endl;
	}

	string name;
	Phone phone;
};

void test01()
{
	Person p("����", Phone("����"));
	cout << p.name << p.phone.name << endl;
}

int main()
{
	test01();

	return 0;
}