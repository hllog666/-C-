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

	if (l1.empty())
	{
		cout << "l1Îª¿Õ" << endl;
	}
	else
	{
		cout << "l1·Ç¿Õ" << endl;
		cout << l1.size() << endl;
	}

	l1.resize(10, 100);
	printList(l1);

	l1.resize(3);
	printList(l1);
}

int main()
{
	test01();

	return 0;
}