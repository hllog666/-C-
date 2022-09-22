#include <iostream>
using namespace std;

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}

	void operator()(string s)
	{
		cout << s << endl;
		count++;
	}

	int count;
};

void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}

void test02()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint的调用次数为" << myPrint.count << endl;
}

void print(MyPrint& mp, string s)
{
	mp(s);
}

void test03()
{
	MyPrint myPrint;
	print(myPrint, "hello c++");
}

int main()
{
	test01();
	test02();
	test03();

	return 0;
}