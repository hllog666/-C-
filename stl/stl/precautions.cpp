#include <iostream>
using namespace std;

template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 必须指定T的数据类型，才可以使用
template<class T>
void func()
{
	cout << "func" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	char c = 'c';
	// 自动推导类型必须一致
	// mySwap(a, c);
}

void test02()
{
	func<int>();
}

int main()
{
	test01();
	test02();

	return 0;
}