#include <iostream>
using namespace std;

int main()
{
	cout << "�����븱���Ѷȣ�" << endl;
	cout << "1����ͨ" << endl;
	cout << "2���е�" << endl;
	cout << "3������" << endl;

	int select = 0;
	cin >> select;

	// ����switch��
	switch (select)
	{
	case 1:
		cout << "��ͨ" << endl;
		break;
	case 2:
		cout << "�е�" << endl;
		break;
	case 3:
		cout << "����" << endl;
		break;
	}

	// ����ѭ����
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			break;
		}
	}

	// ����Ƕ��ѭ����
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