#include <iostream>
using namespace std;

class Java
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

	void content()
	{
		cout << "Javaѧ����Ƶ" << endl;
	}
};

class Python
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

	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};

class Cpp
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