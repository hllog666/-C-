#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << p.name << p.age << endl;
}

template<class T1, class T2>
class Person
{
	friend void printPerson(Person<T1, T2> p)
	{
		cout << p.name << p.age << endl;
	}

	friend void printPerson2<>(Person<T1, T2> p);

public:
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}

private:
	T1 name;
	T2 age;
};

void test01()
{
	Person<string, int> p("Tom", 10);
	printPerson(p);
	printPerson2(p);
}

int main()
{
	test01();

	return 0;
}