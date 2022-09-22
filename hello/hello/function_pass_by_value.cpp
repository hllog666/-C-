#include <iostream>
using namespace std;

void swap(int num1, int num2);

int main()
{
	int a = 10;
	int b = 20;
	swap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}

void swap(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}