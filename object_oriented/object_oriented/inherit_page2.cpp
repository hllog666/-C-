#include <iostream>
using namespace std;

class Page
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��" << endl;
	}

	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ" << endl;
	}

	void left()
	{
		cout << "Java��Python��C++" << endl;
	}
};

class Java :public Page
{
public:
	void content()
	{
		cout << "Javaѧ����Ƶ" << endl;
	}
};

class Python :public Page
{
public:
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};

class Cpp :public Page
{
public:
	void content()
	{
		cout << "C++ѧ����Ƶ" << endl;
	}
};

void test01()
{
	cout << "Java" << endl;
	Java java;
	java.header();
	java.footer();
	java.left();
	java.content();

	cout << "---------" << endl;

	Python python;
	python.header();
	python.footer();
	python.left();
	python.content();

	cout << "---------" << endl;

	Cpp cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
}

int main()
{
	test01();

	return 0;
}