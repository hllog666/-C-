#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void test01()
{
	vector<int> v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), [](int val)->void {cout << val << endl; });
}

int main()
{
	test01();

	return 0;
}