#include <iostream>
using namespace std;
#include <map>

class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

void printMap(map<int, int, MyCompare>& m)
{
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << it->second << " ";
	}
	cout << endl;
}

void test01()
{
	map<int, int, MyCompare> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	printMap(m);
}

int main()
{
	test01();

	return 0;
}