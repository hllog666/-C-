#include <iostream>
using namespace std;

class Person
{
public:
	// 成员函数不属于类对象
	void func()
	{

	}

	// 静态成员函数不属于类对象
	static void func2()
	{

	}

	// 类的成员变量属于类的对象
	int a;

	// 静态成员变量不属于类对象
	static int b;
};

void test01()
{
	Person p;
	// 空对象分配一个字节，区分不同的空对象
	cout << "sizeof(p) = " << sizeof(p) << endl;
}

void test02()
{
	Person p;
	cout << "sizeof(p) = " << sizeof(p) << endl;
}

int main()
{
	test01();

	return 0;
}