#include <iostream>
using namespace std;

int main()
{
	int score = 0;
	cout << "�����Ӱ���д�֣�" << endl;
	cin >> score;

	switch (score)
	{
	case 10:
	case 9:
		cout << "�����Ӱ" << endl;
		break;
	case 8:
	case 7:
		cout << "�õ�Ӱ" << endl;
		break;
	case 6:
	case 5:
		cout << "��Ӱһ��" << endl;
		break;
	case 4:
	case 3:
	case 2:
	case 1:
		cout << "��Ƭ" << endl;
		break;
	}

	return 0;
}