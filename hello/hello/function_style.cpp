#include <iostream>
using namespace std;

void test01();
void test02(int a);
int test03();
int test04(int a);

int main()
{
	test01();
	test02(10);
	test03();
	test04(20);

	return 0;
}

void test01()
{
	cout << "test01" << endl;
}

void test02(int a)
{
	cout << "test02 a = " << a << endl;
}

int test03()
{
	cout << "test03" << endl;
	return 1;
}

int test04(int a)
{
	cout << "test04 a = " << a << endl;
	return a;
}