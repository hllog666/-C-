#include <iostream>
using namespace std;

// this的作用
// 1、解决名称冲突
// 2、返回对象本身
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