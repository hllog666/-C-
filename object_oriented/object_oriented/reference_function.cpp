#include <iostream>
using namespace std;

int& test01();
int& test02();

int main()
{
	int& ref = test01();
	cout << "ref = " << ref << endl;

	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;

	// 函数调用可以作为左值
	test02() = 1000;
	cout << "ref2 = " << ref2 << endl;

	return 0;
}

int& test01()
{
	int a = 10;
	// 不要返回局部变量的引用
	return a;
}

int& test02()
{
	// 静态变量，在main结束才释放
	static int a = 10;
	return a;
}