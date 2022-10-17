#include <iostream>
using namespace std;
#include <string>

// public：类内可以访问，类外可以访问
// protected：类内可以访问，类外不能访问，子类可以访问
// private：类内可以访问，类外不能访问，子类不能访问
class Person
{
public:
	string name;

protected:
	string car;

private:
	int password;

public:
	void func()
	{
		name = "张三";
		car = "自行车";
		password = 123;
	}
};

int main()
{
	Person p;
	p.name = "李四";
	// p.car = "奔驰";
	// p.password = 243;

	return 0;
}