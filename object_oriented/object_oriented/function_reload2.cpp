#include <iostream>
using namespace std;

// ������Ϊ���ز�����const��non-const�����𣬿��Է�������
void func(int& a);
void func(const int& a);

void func2(int a);
void func2(int a, int b = 20);

int main()
{
	func(10);

	int a = 20;
	func(a);

	// �����壬��������ʱ��Ҫʹ��Ĭ�ϲ���
	// func2(10);

	return 0;
}

void func(int& a)
{
	cout << "func(int& a)" << endl;
}

void func(const int& a)
{
	cout << "func(const int& a)" << endl;

}

void func2(int a)
{
	cout << "func2(int a)" << endl;
}

void func2(int a, int b = 20)
{
	cout << "func2(int a, int b = 20)" << endl;
}