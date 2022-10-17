#include <iostream>
using namespace std;

void func(int, int, int);

int main()
{
	func(10, 20, 0);

	return 0;
}

void func(int a, int b, int)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}