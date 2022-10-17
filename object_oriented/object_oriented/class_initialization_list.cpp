#include <iostream>
using namespace std;

class Person
{
public:
	Person(int a, int b, int c) : a(a), b(b), c(c)
	{

	}

	int a;
	int b;
	int c;
};

void test01()
{
	Person p(10, 20, 30);
	cout << p.a << endl;
	cout << p.b << endl;
	cout << p.c << endl;
}

int main()
{
	test01();

	return 0;
}