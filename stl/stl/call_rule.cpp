#include <iostream>
using namespace std;

// �����ͨ�����ͺ���ģ�嶼���Ե��ã����ȵ�����ͨ����
// ����ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
// ����ģ����Է�����������
// �������ģ����Է������õ�ƥ�䣬���ȵ��ú���ģ��

void myPrint(int a, int b)
{
	cout << "��ͨ����" << endl;
}

void myPrint(int a)
{
	cout << "��ͨ����2" << endl;
}

template<class T>
void myPrint(T a, T b)
{
	cout << "����ģ��" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "����ģ��2" << endl;
}

template<class T>
void myPrint(T a)
{
	cout << "����ģ��3" << endl;
}

void test01()
{
	myPrint(10, 20);
	myPrint<>(10, 20);
	myPrint<>(10, 20, 30);
	char c = 10;
	myPrint(c);
}

int main()
{
	test01();

	return 0;
}