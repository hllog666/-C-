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
	l1.push_front(6);
	l1.push_front(7);
	printList(l1);

	l1.pop_back();
	l1.pop_front();
	printList(l1);

	l1.insert(l1.begin(), 100);
	printList(l1);

	l1.erase(l1.begin());
	printList(l1);

	l1.remove(4);
	printList(l1);

	l1.clear();
	printList(l1);
}

int main()
{
	test01();

	return 0;
}