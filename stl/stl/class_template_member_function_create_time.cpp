#include <iostream>
using namespace std;

// 类模板的成员函数创建时机：调用时创建

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2" << endl;
	}
};

template<class T>
class MyClass
{
public:
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}

	T obj;
};

void test01()
{
	MyClass<Person1> m;
	m.func1();
	// m.func2();
}

void test02()
{
	MyClass<Person2> m;
	// m.func1();
	m.func2();
}

int main()
{
	test01();
	test02();

	return 0;
}