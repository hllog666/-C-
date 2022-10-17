#include <iostream>
using namespace std;

class Base1
{
public:
	Base1()
	{
		a = 10;
	}

	int a;
};

class Base2
{
public:
	Base2()
	{
		a = 20;
	}

	int a;
};

class Son :public Base1, public Base2
{
public:
	Son()
	{
		c = 30;
		d = 40;
	}

	int c;
	int d;
};

void test01()
{
	Son s;
	cout << sizeof(s) << endl;
	cout << s.Base1::a << endl;
	cout << s.Base2::a << endl;
}

int main()
{
	test01();

	return 0;
}