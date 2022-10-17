#include <iostream>
using namespace std;
#include <string>

class MyPrint
{
public:
	void operator()(string test)
	{
		cout << test << endl;
	}
};

class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test01()
{
	MyPrint myPrint;
	myPrint("hello world");
}

void test02()
{
	MyAdd myAdd;
	cout<< myAdd(10, 20) << endl;
}

int main()
{
	test01();
	test02();

	return 0;
}