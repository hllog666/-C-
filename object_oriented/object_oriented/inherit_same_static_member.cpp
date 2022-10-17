#include <iostream>
using namespace std;

class Base
{
public:
	static int a;

	static void func()
	{
		cout << "Base" << endl;
	}
};

int Base::a = 10;

class Son :public Base
{
public:
	static int a;

	static void func()
	{
		cout << "Son" << endl;
	}
};

int Son::a = 20;

void test01()
{
	Son s;
	cout << s.a << endl;
	cout << s.Base::a << endl;
	cout << Son::a << endl;
	cout << Son::Base::a << endl;
}

void test02()
{
	Son s;
	s.func();
	s.Base::func();
	Son::func();
	Son::Base::func();
}

int main()
{
	test01();
	test02();

	return 0;
}