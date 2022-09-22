#include <iostream>
using namespace std;
#include <string>

template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void showPerson()
	{
		cout << name << age << endl;
	}

	NameType name;
	AgeType age;
};

void test01()
{
	Person<string, int> p1("Tom", 10);
	p1.showPerson();
}

int main()
{
	test01();

	return 0;
}