#include <iostream>
using namespace std;

// 如果普通函数和函数模板都可以调用，优先调用普通函数
// 可以通过空模板参数列表强制调用函数模板
// 函数模板可以发生函数重载
// 如果函数模板可以发生更好的匹配，优先调用函数模板

void myPrint(int a, int b)
{
	cout << "普通函数" << endl;
}

void myPrint(int a)
{
	cout << "普通函数2" << endl;
}

template<class T>
void myPrint(T a, T b)
{
	cout << "函数模板" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "函数模板2" << endl;
}

template<class T>
void myPrint(T a)
{
	cout << "函数模板3" << endl;
}

void test01()
{
	myPrint(10, 20);
	myPrint<>(10, 20);
	myPrint<>(10, 20, 30);
	char c = 10;
	myPrint(c);
}

int main()
{
	test01();

	return 0;
}