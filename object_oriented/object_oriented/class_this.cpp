#include <iostream>
using namespace std;

// this������
// 1��������Ƴ�ͻ
// 2�����ض�����
class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}

	Person& addAge(Person& p)
	{
		this->age += p.age;
		return *this;
	}

	int age;
};

void test01()
{
	Person p(10);
	cout << p.age << endl;
}

void test02()
{
	Person p(20);
	Person p2(10);

	p.addAge(p2).addAge(p2);

	cout << "p.age = " << p.age << endl;
}

int main()
{
	test01();
	test02();

	return 0;
}