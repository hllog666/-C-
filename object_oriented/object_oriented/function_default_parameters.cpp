#include <iostream>
using namespace std;

// ����Ĭ�ϲ���
int func(int a, int b = 20, int c = 30);

int main()
{
	int ans = func(2);
	cout << "ans = " << ans << endl;

	ans = func(4, 39);
	cout << "ans = " << ans << endl;

	ans = func(4, 39, 6);
	cout << "ans = " << ans << endl;

	return 0;
}

// ������Ĭ�ϲ���������Ͳ�������
int func(int a, int b, int c)
{
	return a + b + c;
}