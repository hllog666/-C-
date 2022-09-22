#include <iostream>
using namespace std;

int main()
{
	cout << "请输入副本难度：" << endl;
	cout << "1、普通" << endl;
	cout << "2、中等" << endl;
	cout << "3、困难" << endl;

	int select = 0;
	cin >> select;

	// 用在switch中
	switch (select)
	{
	case 1:
		cout << "普通" << endl;
		break;
	case 2:
		cout << "中等" << endl;
		break;
	case 3:
		cout << "困难" << endl;
		break;
	}

	// 用在循环中
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			break;
		}
	}

	// 用在嵌套循环中
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
			{
				break;
			}
			cout << "* ";
		}
		cout << endl;
	}

	return 0;
}