#include <iostream>
using namespace std;

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "����������ռ���ڴ�ռ�Ϊ��" << sizeof(arr) << endl;
	cout << "ÿ��Ԫ����ռ���ڴ�ռ�Ϊ��" << sizeof(arr[0]) << endl;
	cout << "�����е�Ԫ�ظ���Ϊ��" << sizeof(arr) / sizeof(arr[0]) << endl;

	cout << "������׵�ַΪ��" << arr << endl;
	cout << "�����е�һ��Ԫ�صĵ�ַΪ��" << &arr[0] << endl;

	return 0;
}