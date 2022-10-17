#include <iostream>
using namespace std;

int main()
{
	// 引用必须初始化，且一旦初始化后就不能更改
	int a = 10;
	int& b = a;

	int c = 20;
	// 赋值操作，不是改变引用
	b = c;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	return 0;
}