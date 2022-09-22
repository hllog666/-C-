#include <iostream>
using namespace std;
#include <set>

void test01()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(1);
	cout << ret.second << endl;
	ret = s.insert(1);
	cout << ret.second << endl;

	multiset<int> ms;
	ms.insert(1);
	ms.insert(1);
	for (auto it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;
	}
}

int main()
{
	test01();

	return 0;
}