#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 4);
	}
	for_each(v1.begin(), v1.end(), [](int val)->void {cout << val << endl; });
	for_each(v2.begin(), v2.end(), [](int val)->void {cout << val << endl; });
	cout << endl;

	vector<int> vTarget;
	vTarget.resize(min(v1.size(), v2.size()));
	auto pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), pos, [](int val)->void {cout << val << endl; });
	cout << endl;
}

int main()
{
	test01();

	return 0;
}