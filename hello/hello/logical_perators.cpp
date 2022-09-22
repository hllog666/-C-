#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	cout << !a << endl;

	int b = 10;
	int c = 10;
	cout << (b && c) << endl;
	cout << (b || c) << endl;

	b = 0;
	c = 10;
	cout << (b && c) << endl;
	cout << (b || c) << endl;

	b = 0;
	c = 0;
	cout << (b && c) << endl;
	cout << (b || c) << endl;

	return 0;
}