#include <iostream>
using namespace std;

// ͬһ����������
// ��������ͬ
// �����б�ͬ
int add(int a, int b);
int add(int a, int b, int c);

int main()
{
	int ans = add(1, 2);
	cout << "ans = " << ans << endl;

	ans = add(3, 5, 7);
	cout << "ans = " << ans << endl;

	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int add(int a, int b, int c)
{
	return a + b + c;
}