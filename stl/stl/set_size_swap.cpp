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

	if (s1.empty())
	{
		cout << "s1Îª¿Õ" << endl;
	}
	else
	{
		cout << "s1·Ç¿Õ" << endl;
		cout << s1.size() << endl;
	}

	set<int> s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

int main()
{
	test01();

	return 0;
}