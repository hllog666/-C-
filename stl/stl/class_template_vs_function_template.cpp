#include <iostream>
using namespace std;
#include <string>

// ��ģ��û���Զ������Ƶ���ʽ
// ��ģ����ģ������б��п�����Ĭ�ϲ���

template<class NameType, class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void showPerson()
	{
		cout << name << age << endl;
	}

	NameType name;
	AgeType age;
};

void test01()
{
	// Person p("Tom", 10);
	Person<string, int> p("Tom", 10);
	p.showPerson();
}

void test02()
{
	Person<string> p("Tom", 10);
	p.showPerson();
}

int main()
{
	test01();
	test02();

	return 0;
}