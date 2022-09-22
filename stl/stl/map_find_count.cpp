#include <iostream>
using namespace std;
#include <map>

void test01()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	auto pos = m.find(3);
	if (!(pos == m.end()))
	{
		cout << "ÕÒµ½ÁË" << endl;
	}
	else
	{
		cout << "Î´ÕÒµ½" << endl;
	}

	int num = m.count(3);
	cout << num << endl;
}

int main()
{
	test01();

	return 0;
}