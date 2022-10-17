#include <iostream>
using namespace std;

int* func();

int main()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;

	return 0;
}

int* func()
{
	int a = 10;
	// 不要返回局部变量的地址
	return &a;
}