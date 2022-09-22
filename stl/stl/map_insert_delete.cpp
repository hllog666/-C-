#include <iostream>
using namespace std;
#include <map>

void printMap(map<int, int>& m)
{
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << it->second << " ";
	}
	cout << endl;
}

void test01()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	// 不建议使用
	m[4] = 40;
	printMap(m);

	m.erase(m.begin());
	printMap(m);

	m.erase(2);
	printMap(m);

	m.clear();
	printMap(m);
}

int main()
{
	test01();

	return 0;
}