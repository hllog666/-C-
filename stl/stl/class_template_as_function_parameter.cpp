#include <iostream>
using namespace std;
#include <string>

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}

	void showPerson()
	{
		cout << name << age << endl;
	}

	T1 name;
	T2 age;
};

void printPerson1(Person<string, int>& p)
{
	p.showPerson();
}

template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1的类型：" << typeid(T1).name() << endl;
	cout << "T2的类型：" << typeid(T2).name() << endl;
}

template<class T>
void printPerson3(T& p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int> p("Tom", 10);
	printPerson1(p);
}

void test02()
{
	Person<string, int> p("Tom", 10);
	printPerson2(p);
}

void test03()
{
	Person<string, int> p("Tom", 10);
	printPerson3(p);
}

int main()
{
	test01();
	test02();
	test03();

	return 0;
}