#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "�޲ι���" << endl;
	}

	Person(int age)
	{
		this->age = age;
		cout << "�вι���" << endl;
	}

	Person(const Person& p)
	{
		age = p.age;
		cout << "��������" << endl;
	}

	~Person()
	{
		cout << "��������" << endl;
	}

	int age;
};

void test01()
{
	// ���ŷ�
	// ���ܼ����ţ��ᱻ�����ɺ�������
	Person p;
	Person p2(18);
	Person p3(p2);
}

void test02()
{
	// ��ʽ��
	Person p = Person();
	Person p2 = Person(10);
	Person p3 = Person(p2);

	// ��������ִ���������ͷ�
	// ��Ҫʹ�ÿ�����������ʼ���������󣬻ᱻ�����ɱ�������
	Person(20);
}

void test03()
{
	// ��ʽת��
	Person p = 10;
}

int main()
{
	test01();
	test02();
	test03();

	return 0;
}