#include <iostream>
using namespace std;

class Person
{
public:
	/*Person operator+(Person p)
	{
		Person temp;
		temp.a = this->a + p.a;
		temp.b = this->b + p.b;
		return temp;
	}*/

	int a;
	int b;
};

Person operator+(Person p1, Person p2)
{
	Person temp;
	temp.a = p1.a + p2.a;
	temp.b = p1.b + p2.b;
	return temp;
}

void test01()
{
	Person p1;
	p1.a = 10;
	p1.b = 10;
	Person p2;
	p2.a = 10;
	p2.b = 10;
	Person p3 = p1 + p2;
	cout << p1.a << endl;
	cout << p1.b << endl;
	cout << p2.a << endl;
	cout << p2.b << endl;
	cout << p3.a << endl;
	cout << p3.b << endl;
}

int main()
{
	test01();

	return 0;
}