#include <iostream>
using namespace std;

int* func();

int main()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;

	return 0;
}

int* func()
{
	int a = 10;
	// ��Ҫ���ؾֲ������ĵ�ַ
	return &a;
}