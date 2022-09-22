#include <iostream>
using namespace std;

int main()
{
	int score = 0;
	cout << "请输入你的分数：" << endl;
	cin >> score;

	if (score > 600)
	{
		cout << "一本大学" << endl;
	}
	else if (score > 500)
	{
		cout << "二本大学" << endl;
	}
	else if (score > 400)
	{
		cout << "三本大学" << endl;
	}
	else
	{
		cout << "毛都不是" << endl;
	}


	return 0;
}