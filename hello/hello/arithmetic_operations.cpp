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

	// ǰ�õ���
	int a = 10;
	++a;
	cout << a << endl;

	// ���õ���
	int b = 10;
	b++;
	cout << b << endl;

	// ǰ�úͺ��õ�����
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