#include <iostream>
using namespace std;

int main()
{
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	cout << "��ά����ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr) << endl;
	cout << "��ά�����һ��ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr[0]) << endl;
	cout << "��ά�����е�Ԫ��ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr[0][0]) << endl;
	cout << "��ά���������Ϊ��" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "��ά���������Ϊ��" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
	cout << "��ά������׵�ַΪ��" << arr << endl;
	cout << "��ά����ĵ�һ�е��׵�ַΪ��" << arr[0] << endl;
	cout << "��ά����ĵ�һ��Ԫ�صĵ�ַΪ��" << &arr[0][0] << endl;

	return 0;
}