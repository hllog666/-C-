#include <iostream>
using namespace std;
#include <deque>

void test01()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(100);
	d.push_back(200);
	d.push_back(300);
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "��һ��Ԫ�أ�" << d.front() << endl;
	cout << "���һ��Ԫ�أ�" << d.back() << endl;
}

int main()
{
	test01();

	return 0;
}