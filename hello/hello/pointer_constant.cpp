#include <iostream>
using namespace std;

int main()
{
	// ָ�볣��
	int a = 10;
	int b = 20;
	int* const p = &a;
	// pָ���ֵ�����޸�
	*p = 30;
	// p��ָ�����޸�
	// p = &b;

	return 0;
}