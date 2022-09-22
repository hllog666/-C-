#include <iostream>
using namespace std;

int main()
{
	// 指针常量
	int a = 10;
	int b = 20;
	int* const p = &a;
	// p指向的值可以修改
	*p = 30;
	// p的指向不能修改
	// p = &b;

	return 0;
}