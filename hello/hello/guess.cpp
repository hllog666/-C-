#include <iostream>
using namespace std;
#include <ctime>

int main()
{
	// �������
	srand((unsigned int)time(NULL));

	int ans = rand() % 100 + 1;
	int guess = 0;
	cout << ans << endl;
	
	while (guess != ans)
	{
		cout << "���һ������" << endl;
		cin >> guess;
		if (guess > ans)
		{
			cout << "����" << endl;
		}
		else if (guess < ans)
		{
			cout << "С��" << endl;
		}
	}
	cout << "�¶���" << endl;

	return 0;
}