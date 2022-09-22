#include <iostream>
using namespace std;

int add(int num1, int num2);

int main()
{
	int num1 = 3;
	int num2 = 4;
	int sum = add(num1, num2);
	cout << "sum = " << sum << endl;

	return 0;
}

int add(int num1, int num2)
{
	return num1 + num2;
}