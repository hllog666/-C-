#include <iostream>
using namespace std;

void swap01(int a, int b);
void swap02(int* a, int* b);
void swap03(int& a, int& b);
void test01();
void test02();
void test03();

int main()
{
	test01();
	test02();
	test03();

	return 0;
}

void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	swap01(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	swap02(&a, &b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

void test03()
{
	int a = 10;
	int b = 20;
	swap03(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}