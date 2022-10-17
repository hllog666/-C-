#include <iostream>
using namespace std;
#include <fstream>
#include <string>

void test01()
{
	ifstream ifs;
	ifs.open("write.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	ifs.close();
}

void test02()
{
	ifstream ifs;
	ifs.open("write.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}
	ifs.close();
}

void test03()
{
	ifstream ifs;
	ifs.open("write.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
	ifs.close();
}

void test04()
{
	ifstream ifs;
	ifs.open("write.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	ifs.close();
}

int main()
{
	test01();
	test02();
	test03();
	test04();

	return 0;
}