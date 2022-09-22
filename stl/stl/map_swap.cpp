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
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 10));
	if (m.empty())
	{
		cout << "mÎª¿Õ" << endl;
	}
	else
	{
		cout << "m·Ç¿Õ" << endl;
		cout << m.size() << endl;
	}
}

void test02()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	map<int, int> m2;
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(7, 70));

	m.swap(m2);

	printMap(m);
	printMap(m2);
}

int main()
{
	test01();
	test02();

	return 0;
}