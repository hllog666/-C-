#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	// ����ָ��
	const int* p = &a;
	// pָ���ֵ�����޸�
	// *p = 20;
	int b = 20;
	// p��ָ������޸�
	p = &b;

	return 0;
}