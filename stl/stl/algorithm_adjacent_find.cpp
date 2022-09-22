#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void test01()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(0);
	v.push_back(4);
	v.push_back(4);
	auto pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		cout << "Î´ÕÒµ½" << endl;
	}
	else
	{
		cout << "ÕÒµ½ÁË" << endl;
		cout << *pos << endl;
	}
}

int main()
{
	test01();

	return 0;
}