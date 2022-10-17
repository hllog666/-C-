#include <iostream>
using namespace std;

class Person
{
public:
	int a;
	int b;
};

ostream& operator<<(ostream& cout, Person& p)
{
	cout << p.a << p.b << endl;
	return cout;
}

void test01()
{
	Person p;
	p.a = 10;
	p.b = 10;
	cout << p << endl;
}

int main()
{
	test01();

	return 0;
}