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

	list<int> l2(l1.begin(), l1.end());
	printList(l2);

	list<int> l3(l2);
	printList(l3);

	list<int> l4(10, 100);
	printList(l4);
}

int main()
{
	test01();

	return 0;
}