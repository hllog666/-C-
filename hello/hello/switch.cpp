#include <iostream>
using namespace std;

int main()
{
	int score = 0;
	cout << "请给电影进行打分：" << endl;
	cin >> score;

	switch (score)
	{
	case 10:
	case 9:
		cout << "经典电影" << endl;
		break;
	case 8:
	case 7:
		cout << "好电影" << endl;
		break;
	case 6:
	case 5:
		cout << "电影一般" << endl;
		break;
	case 4:
	case 3:
	case 2:
	case 1:
		cout << "烂片" << endl;
		break;
	}

	return 0;
}