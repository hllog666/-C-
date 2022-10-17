#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->age = age;
		this->name = name;
	}

	bool operator==(Person& p)
	{
		if (this->name == p.name && this->age == p.age)
		{
			return true;
		}
		return false;
	}

	bool operator!=(Person& p)
	{
		if (this->name == p.name && this->age == p.age)
		{
			return false;
		}
		return true;
	}

	string name;
	int age;
};

void test01()
{
	Person p1("Tom", 19);
	Person p2("Tom", 19);
	cout << (p1 == p2) << endl;
	cout << (p1 != p2) << endl;
}

int main()
{
	test01();

	return 0;
}