#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}

	Person(int age)
	{
		this->age = age;
		cout << "�вι��캯��" << endl;
	}

	Person(const Person& p)
	{
		age = p.age;
		cout << "�������캯��" << endl;
	}

	~Person()
	{
		cout << "��������" << endl;
	}

	int age;
};

void test01()
{
	Person p;
	p.age = 19;

	Person p2(p);

	cout << "p2��age = " << p2.age << endl;
}

int main()
{
	test01();

	return 0;
}