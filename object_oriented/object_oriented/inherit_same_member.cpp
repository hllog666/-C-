#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		a = 10;
	}

	void func()
	{
		cout << "Base" << endl;
	}

	int a;
};

class Son :public Base
{
public:
	Son()
	{
		a = 20;
	}

	void func()
	{
		cout << "Son" << endl;
	}

	int a;
};

void test01()
{
	Son s;
	cout << s.a << endl;
	cout << s.Base::a << endl;
}

void test02()
{
	Son s;
	s.func();
	s.Base::func();
}

int main()
{
	test01();
	test02();

	return 0;
}