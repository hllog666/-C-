#include <iostream>
using namespace std;

int main()
{
	int num1 = 10;
	int num2 = 3;

	cout << num1 + num2 << endl;
	cout << num1 - num2 << endl;
	cout << num1 * num2 << endl;
	cout << num1 / num2 << endl;
	cout << num1 % num2 << endl;

	// 前置递增
	int a = 10;
	++a;
	cout << a << endl;

	// 后置递增
	int b = 10;
	b++;
	cout << b << endl;

	// 前置和后置的区别
	int c = 10;
	int d = ++c * 10;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	int c2 = 10;
	int d2 = c2++ * 10;
	cout << "c2 = " << c2 << endl;
	cout << "d2 = " << d2 << endl;

	return 0;
}