#include <iostream>
using namespace std;

class Person
{
public:
	// this指针的本质：指针常量
	void showPerson() const
	{
		// a = 10;
		// this = nullptr;
		b = 10;
	}

	int a;
	mutable int b;
};

void test01()
{
	Person p;
	p.showPerson();
}

void test02()
{
	const Person p;
	// p.a = 100;
	p.b = 100;
}

int main()
{
	test01();

	return 0;
}