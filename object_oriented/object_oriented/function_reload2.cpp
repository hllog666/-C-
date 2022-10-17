#include <iostream>
using namespace std;

// 引用作为重载参数，const和non-const有区别，可以发生重载
void func(int& a);
void func(const int& a);

void func2(int a);
void func2(int a, int b = 20);

int main()
{
	func(10);

	int a = 20;
	func(a);

	// 有歧义，函数重载时不要使用默认参数
	// func2(10);

	return 0;
}

void func(int& a)
{
	cout << "func(int& a)" << endl;
}

void func(const int& a)
{
	cout << "func(const int& a)" << endl;

}

void func2(int a)
{
	cout << "func2(int a)" << endl;
}

void func2(int a, int b = 20)
{
	cout << "func2(int a, int b = 20)" << endl;
}