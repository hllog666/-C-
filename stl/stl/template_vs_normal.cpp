#include <iostream>
using namespace std;

// 普通函数调用可以发生类型转换
// 函数模板用自动类型推导，不可以发生隐式类型转换
// 函数模板用显式指定类型，可以发生隐式类型转换

int myAdd(int a, int b)
{
	return a + b;
}

template<class T>
T myAddT(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd(a, c) << endl;

	// cout << myAddT(a, c) << endl;
	cout << myAddT<int>(a, c) << endl;
}

int main()
{
	test01();

	return 0;
}