#include <iostream>
using namespace std;
#include <string>

class Phone
{
public:
	Phone(string name) :name(name)
	{
		cout << "Phone构造函数" << endl;
	}

	~Phone()
	{
		cout << "Phone析构函数" << endl;
	}

	string name;
};

class Person
{
public:
	Person(string name, Phone phone) :name(name), phone(phone)
	{
		cout << "Person构造函数" << endl;
	}

	~Person()
	{
		cout << "Person析构函数" << endl;
	}

	string name;
	Phone phone;
};

void test01()
{
	Person p("张三", Phone("三星"));
	cout << p.name << p.phone.name << endl;
}

int main()
{
	test01();

	return 0;
}