#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i * 10);
	}

	vector<int> vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), [](int v)->void {cout << v << endl; });
}

int main()
{
	test01();

	return 0;
}