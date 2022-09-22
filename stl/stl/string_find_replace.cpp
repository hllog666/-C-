#include <iostream>
using namespace std;
#include <string>

void test01()
{
	string str1 = "abcdefgdefg";
	int pos = str1.find("ef");
	cout << pos << endl;
	pos = str1.rfind("ef");
	cout << pos << endl;
}

void test02()
{
	string str1 = "abcdefgdefg";
	str1.replace(1, 3, "1234");
	cout << str1 << endl;
}

int main()
{
	test01();
	test02();

	return 0;
}