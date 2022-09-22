#include <iostream>
using namespace std;

int main()
{
	int num = 100;

	do
	{
		int ge = num % 10;
		int shi = num / 10 % 10;
		int bai = num / 100;
		if (ge * ge * ge + shi * shi * shi + bai * bai * bai == num)
		{
			cout << num << endl;
		}
		num++;
	} while (num < 1000);

	return 0;
}