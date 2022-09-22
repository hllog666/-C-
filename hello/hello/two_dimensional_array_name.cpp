#include <iostream>
using namespace std;

int main()
{
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	cout << "二维数组占用的内存空间为：" << sizeof(arr) << endl;
	cout << "二维数组第一行占用的内存空间为：" << sizeof(arr[0]) << endl;
	cout << "二维数组中的元素占用的内存空间为：" << sizeof(arr[0][0]) << endl;
	cout << "二维数组的行数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组的列数为：" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
	cout << "二维数组的首地址为：" << arr << endl;
	cout << "二维数组的第一行的首地址为：" << arr[0] << endl;
	cout << "二维数组的第一个元素的地址为：" << &arr[0][0] << endl;

	return 0;
}