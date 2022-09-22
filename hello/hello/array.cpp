#include <iostream>
using namespace std;

int main()
{
	int arr[5];
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 10;
	arr[4] = 10;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}

	cout << "---------" << endl;

	int arr2[5] = {10,20,30,40,50};
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << endl;
	}

	cout << "---------" << endl;

	int arr3[] = { 10,20,30,40,50 };
	for (int i = 0; i < 5; i++)
	{
		cout << arr3[i] << endl;
	}

	return 0;
}