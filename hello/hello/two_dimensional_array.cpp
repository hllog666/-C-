#include <iostream>
using namespace std;

int main()
{
	int arr[2][3];
	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------------" << endl;

	int arr2[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	int row2 = sizeof(arr2) / sizeof(arr2[0]);
	int col2 = sizeof(arr2[0]) / sizeof(arr2[0][0]);
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			cout << arr2[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------------" << endl;

	int arr3[2][3] = { 1,2,3,4,5,6 };
	int row3 = sizeof(arr3) / sizeof(arr3[0]);
	int col3 = sizeof(arr3[0]) / sizeof(arr3[0][0]);
	for (int i = 0; i < row3; i++)
	{
		for (int j = 0; j < col3; j++)
		{
			cout << arr3[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------------" << endl;

	int arr4[][3] = { 1,2,3,4,5,6 };
	int row4 = sizeof(arr4) / sizeof(arr4[0]);
	int col4 = sizeof(arr4[0]) / sizeof(arr4[0][0]);
	for (int i = 0; i < row4; i++)
	{
		for (int j = 0; j < col4; j++)
		{
			cout << arr4[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------------" << endl;

	return 0;
}