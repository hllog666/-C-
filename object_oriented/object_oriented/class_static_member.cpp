#include <iostream>
using namespace std;

class Person
{
public:
	static void func()
	{
		cout << "static void func()" << endl;
	}

	// 所有对象共享一份数据
	// 编译阶段就分配内存
	// 类内声明，类外初始化
	static int a;
};

int Person::a = 100;

void test01()
{
	Person p;
	cout << p.a << endl;

	Person p2;
	cout << p2.a << endl;
}

void test02()
{
	Person p;
	p.func();

	Person::func();
}

int main()
{
	test01();
	test02();

	return 0;
}