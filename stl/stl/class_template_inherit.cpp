#include <iostream>
using namespace std;

template<class T>
class Base
{
public:
	T m;
};

class Son :public Base<int>
{

};

template<class T>
class Son2 :public Base<T>
{

};

void test01()
{
	Son son;

	Son2<int> son2;
}

int main()
{
	test01();

	return 0;
}