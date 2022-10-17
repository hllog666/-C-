#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}

	Person(int age)
	{
		this->age = age;
		cout << "有参构造函数" << endl;
	}

	Person(const Person& p)
	{
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}

	~Person()
	{
		cout << "析构函数" << endl;
	}

	int age;
};

void test01()
{
	Person p;
	p.age = 19;

	Person p2(p);

	cout << "p2的age = " << p2.age << endl;
}

int main()
{
	test01();

	return 0;
}