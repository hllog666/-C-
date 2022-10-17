#include <iostream>
using namespace std;

class Base
{
public:
	virtual void func() = 0;
};

class Son :public Base
{
public:
	void func()
	{
		cout << "Son" << endl;
	}
};

void test01()
{
	Base* b = new Son;
	b->func();
}

int main()
{
	test01();

	return 0;
}