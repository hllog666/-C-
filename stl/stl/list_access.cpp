#include <iostream>
using namespace std;
#include <list>

void test01()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);

	cout << "��һ��Ԫ�أ�" << l1.front() << endl;
	cout << "���һ��Ԫ�أ�" << l1.back() << endl;
}

int main()
{
	test01();

	return 0;
}