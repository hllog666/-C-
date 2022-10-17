#include <iostream>
using namespace std;

class Base1
{
public:
	int a;
protected:
	int b;
private:
	int c;
};

class Son1 :public Base1
{
public:
	void func()
	{
		a = 10;
		b = 10;
		// c = 10;
	}
};

class Son2 :protected Base1
{
public:
	void func()
	{
		a = 10;
		b = 10;
		// c = 10;
	}
};

class Son3 :private Base1
{
public:
	void func()
	{
		a = 10;
		b = 10;
		// c = 10;
	}
};

class GrandSon3 :public Son3
{
public:
	void func()
	{
		// a = 10;
		// b = 10;
	}
};

void test01()
{
	Son1 s1;
	s1.a = 20;
	// s1.b = 20;

	Son2 s2;
	// s2.a = 20;
	// s2.b = 20;

	Son3 s3;
	// s3.a = 20;
	// s3.b = 20;
}

int main()
{
	test01();

	return 0;
}