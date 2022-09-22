#include <iostream>
using namespace std;
#include <ctime>

int main()
{
	// 随机种子
	srand((unsigned int)time(NULL));

	int ans = rand() % 100 + 1;
	int guess = 0;
	cout << ans << endl;
	
	while (guess != ans)
	{
		cout << "请猜一个数：" << endl;
		cin >> guess;
		if (guess > ans)
		{
			cout << "大了" << endl;
		}
		else if (guess < ans)
		{
			cout << "小了" << endl;
		}
	}
	cout << "猜对了" << endl;

	return 0;
}