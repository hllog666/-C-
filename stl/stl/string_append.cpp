#include <iostream>
using namespace std;
#include <string>

void test01()
{
	string str1 = "ÎÒ";
	str1 += "°®ÍæÓÎÏ·";
	cout << str1 << endl;

	str1 += 'h';
	cout << str1 << endl;

	string str2 = "LOL DNF";
	str1 += str2;
	cout << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	cout << str3 << endl;

	str3.append("game jfkadh", 4);
	cout << str3 << endl;

	string str4 = "I";
	str4.append(" love LOL DNF", 0, 9);
	cout << str4 << endl;
}

int main()
{
	test01();

	return 0;
}