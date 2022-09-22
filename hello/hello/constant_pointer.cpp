#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	// 常量指针
	const int* p = &a;
	// p指向的值不能修改
	// *p = 20;
	int b = 20;
	// p的指向可以修改
	p = &b;

	return 0;
}