#include <iostream>
using namespace std;

class Person
{
public:
	// ��Ա���������������
	void func()
	{

	}

	// ��̬��Ա���������������
	static void func2()
	{

	}

	// ��ĳ�Ա����������Ķ���
	int a;

	// ��̬��Ա���������������
	static int b;
};

void test01()
{
	Person p;
	// �ն������һ���ֽڣ����ֲ�ͬ�Ŀն���
	cout << "sizeof(p) = " << sizeof(p) << endl;
}

void test02()
{
	Person p;
	cout << "sizeof(p) = " << sizeof(p) << endl;
}

int main()
{
	test01();

	return 0;
}