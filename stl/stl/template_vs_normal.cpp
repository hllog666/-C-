#include <iostream>
using namespace std;

// ��ͨ�������ÿ��Է�������ת��
// ����ģ�����Զ������Ƶ��������Է�����ʽ����ת��
// ����ģ������ʽָ�����ͣ����Է�����ʽ����ת��

int myAdd(int a, int b)
{
	return a + b;
}

template<class T>
T myAddT(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd(a, c) << endl;

	// cout << myAddT(a, c) << endl;
	cout << myAddT<int>(a, c) << endl;
}

int main()
{
	test01();

	return 0;
}