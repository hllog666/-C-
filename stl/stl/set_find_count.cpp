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

	auto pos = s1.find(3);
	if (!(pos == s1.end()))
	{
		cout << "ÕÒµ½" << endl;
	}
	else
	{
		cout << "Î´ÕÒµ½" << endl;
	}

	cout << s1.count(4) << endl;
}

int main()
{
	test01();

	return 0;
}