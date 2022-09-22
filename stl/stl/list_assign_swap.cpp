#include <iostream>
using namespace std;
#include <list>

void printList(const list<int>& l)
{
	for (auto it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	printList(l1);

	list<int> l2;
	l2 = l1;
	printList(l2);

	list<int> l3;
	l3.assign(l2.begin(), l2.end());
	printList(l3);

	list<int> l4;
	l4.assign(10, 100);
	printList(l4);
}

void test02()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	printList(l1);

	list<int> l2;
	l2.assign(10, 100);

	l1.swap(l2);
	printList(l1);
	printList(l2);
}

int main()
{
	test01();
	test02();

	return 0;
}