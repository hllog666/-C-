#include <iostream>
using namespace std;

template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			mySwap(arr[i], arr[max]);
		}
	}
}

template<class T>
void printArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	char charArr[] = "badcfe";
	int len = sizeof(charArr) / sizeof(char);
	mySort(charArr, len);
	printArr(charArr, len);
}

void test02()
{
	int intArr[] = { 7,5,1,3,9,2,4,6,8 };
	int len = sizeof(intArr) / sizeof(int);
	mySort(intArr, len);
	printArr(intArr, len);
}

int main()
{
	test01();
	test02();

	return 0;
}