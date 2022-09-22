#include <iostream>
using namespace std;
#include <deque>

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(30);
	d1.push_front(40);
	printDeque(d1);

	d1.pop_front();
	d1.pop_back();
	printDeque(d1);

	d1.insert(d1.begin(), 1000);
	printDeque(d1);

	d1.insert(d1.begin(), 2, 2000);
	printDeque(d1);

	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);

	d1.erase(d1.begin());
	printDeque(d1);

	d1.clear();
	printDeque(d1);
}

int main()
{
	test01();

	return 0;
}