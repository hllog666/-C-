#include <iostream>
using namespace std;

int g_a = 10;
int g_b = 20;
const int c_g_a = 10;

int main()
{
	int a = 10;
	int b = 20;

	static int s_a = 10;
	static int s_b = 20;

	const int c_l_a = 10;

	cout << "�ֲ�����a���ڴ��ַΪ��" << &a << endl;
	cout << "�ֲ�����b���ڴ��ַΪ��" << &a << endl;
	cout << "ȫ�ֱ���g_a���ڴ��ַΪ��" << &g_a << endl;
	cout << "ȫ�ֱ���g_b���ڴ��ַΪ��" << &g_b << endl;
	cout << "��̬����s_a���ڴ��ַΪ��" << &s_a << endl;
	cout << "��̬����s_b���ڴ��ַΪ��" << &s_b << endl;
	cout << "�ַ����������ڴ��ַΪ��" << &("hello") << endl;
	cout << "ȫ�ֳ���c_g_a���ڴ��ַΪ��" << &c_g_a << endl;
	cout << "�ֲ�����c_l_a���ڴ��ַΪ��" << &c_l_a << endl;

	return 0;
}