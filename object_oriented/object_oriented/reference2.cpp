#include <iostream>
using namespace std;

int main()
{
	// ���ñ����ʼ������һ����ʼ����Ͳ��ܸ���
	int a = 10;
	int& b = a;

	int c = 20;
	// ��ֵ���������Ǹı�����
	b = c;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	return 0;
}