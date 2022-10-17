#include <iostream>
using namespace std;

int g_a = 10;
int g_b = 20;
const int c_g_a = 10;

int main()
{
	int a = 10;
	int b = 20;

	static int s_a = 10;
	static int s_b = 20;

	const int c_l_a = 10;

	cout << "局部变量a的内存地址为：" << &a << endl;
	cout << "局部变量b的内存地址为：" << &a << endl;
	cout << "全局变量g_a的内存地址为：" << &g_a << endl;
	cout << "全局变量g_b的内存地址为：" << &g_b << endl;
	cout << "静态变量s_a的内存地址为：" << &s_a << endl;
	cout << "静态变量s_b的内存地址为：" << &s_b << endl;
	cout << "字符串常量的内存地址为：" << &("hello") << endl;
	cout << "全局常量c_g_a的内存地址为：" << &c_g_a << endl;
	cout << "局部常量c_l_a的内存地址为：" << &c_l_a << endl;

	return 0;
}