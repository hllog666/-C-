#include <iostream>
using namespace std;
#include <string>

class Calculate
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return num1 + num2;
		}
		else if (oper == "-")
		{
			return num1 - num2;
		}
		else if (oper == "*")
		{
			return num1 * num2;
		}
		else if (oper == "/")
		{
			return num1 / num2;
		}
	}

	int num1;
	int num2;
};

void test01()
{
	Calculate c;
	c.num1 = 10;
	c.num2 = 2;

	cout << c.num1 << " + " << c.num2 << " = " << c.getResult("+") << endl;
	cout << c.num1 << " - " << c.num2 << " = " << c.getResult("-") << endl;
	cout << c.num1 << " * " << c.num2 << " = " << c.getResult("*") << endl;
	cout << c.num1 << " / " << c.num2 << " = " << c.getResult("/") << endl;
}

int main()
{
	test01();

	return 0;
}