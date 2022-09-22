#include <iostream>
using namespace std;

template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// ����ָ��T���������ͣ��ſ���ʹ��
template<class T>
void func()
{
	cout << "func" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	char c = 'c';
	// �Զ��Ƶ����ͱ���һ��
	// mySwap(a, c);
}

void test02()
{
	func<int>();
}

int main()
{
	test01();
	test02();

	return 0;
}