#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数" << endl;
	}

	Person(int age)
	{
		this->age = age;
		cout << "Person有参构造函数" << endl;
	}
	
	Person(const Person& p)
	{
		age = p.age;
		cout << "Person拷贝构造函数" << endl;
	}

	~Person()
	{
		cout << "Person析构函数" << endl;
	}

	int age;

};

void test01()
{
	Person p1(10);
	Person p2(p1);
}

void work(Person p)
{

}

void test02()
{
	Person p;
	work(p);
}

Person work2()
{
	Person p;
	return p;
}

void test03()
{
	Person p = work2();
}

int main()
{
	test01();

	cout << "-------" << endl;

	test02();

	cout << "-------" << endl;

	test03();

	return 0;
}