#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		this->age = new int(age);
	}

	Person& operator=(Person& p)
	{
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		}

		age = new int(*p.age);
		return *this;
	}

	~Person()
	{
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		}
	}

	int* age;
};

void test01()
{
	Person p1(18);
	Person p2(10);
	p2 = p1;
	cout << "p1.age = " << *p1.age << endl;
	cout << "p2.age = " << *p2.age << endl;
}

int main()
{
	test01();

	return 0;
}