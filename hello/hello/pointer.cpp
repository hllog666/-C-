#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int* p;
	p = &a;

	cout << "a�ĵ�ַΪ��" << &a << endl;
	cout << "ָ��pΪ��" << p << endl;
	cout << "a��ֵΪ��" << *p << endl;

	return 0;
}