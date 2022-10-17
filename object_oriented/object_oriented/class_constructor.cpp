#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "无参构造" << endl;
	}

	Person(int age)
	{
		this->age = age;
		cout << "有参构造" << endl;
	}

	Person(const Person& p)
	{
		age = p.age;
		cout << "拷贝构造" << endl;
	}

	~Person()
	{
		cout << "析构函数" << endl;
	}

	int age;
};

void test01()
{
	// 括号法
	// 不能加括号，会被解析成函数声明
	Person p;
	Person p2(18);
	Person p3(p2);
}

void test02()
{
	// 显式法
	Person p = Person();
	Person p2 = Person(10);
	Person p3 = Person(p2);

	// 匿名对象，执行完立即释放
	// 不要使用拷贝构造来初始化匿名对象，会被解析成变量声明
	Person(20);
}

void test03()
{
	// 隐式转换
	Person p = 10;
}

int main()
{
	test01();
	test02();
	test03();

	return 0;
}