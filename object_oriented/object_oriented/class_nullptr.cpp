#include <iostream>
using namespace std;

class Person
{
public:
	void showClassName()
	{
		cout << "Person" << endl;
	}

	void showPersonAge()
	{
		cout << "age = " << age << endl;
	}

	int age;
};

void test01()
{
	Person* p = nullptr;
	
	p->showClassName();
}

void test02()
{
	Person* p = nullptr;

	p->showPersonAge();
}

int main()
{
	test01();
	test02();

	return 0;
}