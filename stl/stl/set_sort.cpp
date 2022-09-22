#include <iostream>
using namespace std;
#include <set>

class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

void printSet(set<int>& s)
{
	for (auto it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printSet(set<int, MyCompare>& s)
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
	s1.insert(4);
	s1.insert(3);
	s1.insert(2);
	s1.insert(5);
	printSet(s1);

	set<int, MyCompare> s2;
	s2.insert(1);
	s2.insert(4);
	s2.insert(3);
	s2.insert(2);
	s2.insert(5);
	printSet(s2);
}

int main()
{
	test01();

	return 0;
}