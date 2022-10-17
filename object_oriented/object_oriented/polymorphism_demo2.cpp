#include <iostream>
using namespace std;

class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int num1;
	int num2;
};

class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 + num2;
	}
};

class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 - num2;
	}
};

class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 * num2;
	}
};

class DivCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 / num2;
	}
};

void test01()
{
	AbstractCalculator* abs = new AddCalculator;
	abs->num1 = 10;
	abs->num2 = 2;
	cout << abs->num1 << " + " << abs->num2 << " = " << abs->getResult() << endl;
	delete abs;

	abs = new SubCalculator;
	abs->num1 = 10;
	abs->num2 = 2;
	cout << abs->num1 << " - " << abs->num2 << " = " << abs->getResult() << endl;
	delete abs;

	abs = new MulCalculator;
	abs->num1 = 10;
	abs->num2 = 2;
	cout << abs->num1 << " * " << abs->num2 << " = " << abs->getResult() << endl;
	delete abs;

	abs = new DivCalculator;
	abs->num1 = 10;
	abs->num2 = 2;
	cout << abs->num1 << " / " << abs->num2 << " = " << abs->getResult() << endl;
	delete abs;
}

int main()
{
	test01();

	return 0;
}