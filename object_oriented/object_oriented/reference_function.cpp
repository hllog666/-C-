#include <iostream>
using namespace std;

int& test01();
int& test02();

int main()
{
	int& ref = test01();
	cout << "ref = " << ref << endl;

	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;

	// �������ÿ�����Ϊ��ֵ
	test02() = 1000;
	cout << "ref2 = " << ref2 << endl;

	return 0;
}

int& test01()
{
	int a = 10;
	// ��Ҫ���ؾֲ�����������
	return a;
}

int& test02()
{
	// ��̬��������main�������ͷ�
	static int a = 10;
	return a;
}