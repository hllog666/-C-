#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	for_each(v.begin(), v.end(), [](int val)->void {cout << val << endl; });

	replace(v.begin(), v.end(), 20, 200);
	for_each(v.begin(), v.end(), [](int val)->void {cout << val << endl; });
}

int main()
{
	test01();

	return 0;
}