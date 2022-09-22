#include <iostream>
using namespace std;
#include <list>
#include <string>

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}

	string name;
	int age;
	int height;
};

bool comparePerson(Person& p1, Person& p2)
{
	if (p1.age == p2.age)
	{
		return p1.height > p2.height;
	}
	return p1.age > p2.age;
}

void printList(const list<Person>& l)
{
	for (auto it = l.begin(); it != l.end(); it++)
	{
		cout << it->name << it->age << it->height << endl;
	}
}

void test01()
{
	list<Person> l;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 180);
	Person p5("关于", 35, 190);
	Person p6("张飞", 33, 178);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	l.sort(comparePerson);
	printList(l);
}

int main()
{
	test01();

	return 0;
}