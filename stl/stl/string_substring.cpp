#include <iostream>
using namespace std;
#include <string>

void test01()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3);
	cout << subStr << endl;
}

void test02()
{
	string email = "zhangsan@qq.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << username;
}

int main()
{
	test01();
	test02();

	return 0;
}