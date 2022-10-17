#include <iostream>
using namespace std;

void showValue(const int& val);

int main()
{
	int a = 10;
	const int& ref = 10;

	showValue(20);

	return 0;
}

void showValue(const int& val)
{
	cout << val << endl;
}