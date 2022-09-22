#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int* p;
	p = &a;

	cout << "a的地址为：" << &a << endl;
	cout << "指针p为：" << p << endl;
	cout << "a的值为：" << *p << endl;

	return 0;
}