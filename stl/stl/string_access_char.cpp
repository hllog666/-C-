#include <iostream>
using namespace std;
#include <string>

void test01()
{
	string str = "hello";
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	str[3] = 'f';
	cout << str << endl;
	str.at(1) = 'y';
	cout << str << endl;
}

int main()
{
	test01();

	return 0;
}