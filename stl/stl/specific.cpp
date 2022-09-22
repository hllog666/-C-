#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};

template<class T>
bool myCompare(T& a, T& b)
{
	return a == b;
}

template<> bool myCompare(Person& p1, Person& p2)
{
	return p1.name == p2.name && p1.age == p2.age;
}

void test01()
{
	int a = 10;
	int b = 20;
	cout << myCompare(a, b) << endl;
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	cout << myCompare(p1, p2) << endl;
}

int main()
{
	test01();
	test02();

	return 0;
}