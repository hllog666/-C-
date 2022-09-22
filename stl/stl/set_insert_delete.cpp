#include <iostream>
using namespace std;
#include <set>

void printSet(set<int>& s)
{
	for (auto it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int> s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	printSet(s1);

	s1.erase(s1.begin());
	printSet(s1);

	s1.erase(3);
	printSet(s1);

	s1.clear();
	printSet(s1);
}

int main()
{
	test01();

	return 0;
}