#include <iostream>
using namespace std;

int max(int num1, int num2);

int main()
{
	int num1 = 10;
	int num2 = 20;
	int maxNum = max(num1, num2);
	cout << "maxNum = " << maxNum << endl;

	return 0;
}

int max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}