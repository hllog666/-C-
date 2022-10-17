#include <iostream>
using namespace std;

class Java
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图" << endl;
	}

	void left()
	{
		cout << "Java、Python、C++" << endl;
	}

	void content()
	{
		cout << "Java学科视频" << endl;
	}
};

class Python
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图" << endl;
	}

	void left()
	{
		cout << "Java、Python、C++" << endl;
	}

	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

class Cpp
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图" << endl;
	}

	void left()
	{
		cout << "Java、Python、C++" << endl;
	}

	void content()
	{
		cout << "C++学科视频" << endl;
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