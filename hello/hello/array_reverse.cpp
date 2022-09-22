#include <iostream>
using namespace std;

int main()
{
	int arr[5] = { 1,3,2,5,4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << "数组元素逆置前：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	for (int start = 0, end = len - 1; start < end; start++, end--)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
	}

	cout << "数组元素逆置后：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "\t";
	}

	return 0;
}