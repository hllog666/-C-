#include <iostream>
using namespace std;
#include <string>
#include <set>

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

class ComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.age > p2.age;
	}
};

void test01()
{
	set<Person, ComparePerson> s;
	Person p1("Áõ±¸", 24);
	Person p2("¹ØÓğ", 28);
	Person p3("ÕÅ·É", 25);
	Person p4("ÕÔÔÆ", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (auto it = s.begin(); it != s.end(); it++)
	{
		cout << it->name << it->age << endl;
	}
}

int main()
{
	test01();

	return 0;
}