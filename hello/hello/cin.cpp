#include <iostream>
using namespace std;
#include <string>

int main()
{
	int a = 0;
	cout << "请给整型变量a赋值：" << endl;
	cin >> a;
	cout << "a = " << a << endl;

	float f = 0;
	cout << "请给浮点型变量f赋值：" << endl;
	cin >> f;
	cout << "f = " << f << endl;

	char ch = 0;
	cout << "请给字符型变量ch赋值：" << endl;
	cin >> ch;
	cout << "ch = " << ch << endl;

	string str;
	cout << "请给字符串型变量str赋值：" << endl;
	cin >> str;
	cout << "str = " << str << endl;

	bool flag;
	cout << "请给布尔型变量flag赋值：" << endl;
	cin >> flag;
	cout << "flag = " << flag << endl;

	return 0;
}