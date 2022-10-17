#include <iostream>
using namespace std;

class MyInteger
{
public:
	MyInteger()
	{
		num = 0;
	}

	// 前置递增
	MyInteger& operator++()
	{
		num++;
		return *this;
	}

	// 后置递增
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		num++;
		return temp;
	}

	int num;
};

ostream& operator<<(ostream& cout, MyInteger& myint)
{
	cout << myint.num << endl;
	return cout;
}

void test01()
{
	MyInteger myint;
	++myint;
	++myint;
	cout << myint << endl;
}

void test02()
{
	MyInteger myint;
	myint++;
	myint++;
	cout << myint << endl;
}

int main()
{
	test01();
	test02();

	return 0;
}